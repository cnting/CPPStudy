#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

//void*可以是任意类型的
void *thread_run(void *arg) {
    int no = static_cast<int>(reinterpret_cast<uintptr_t>(arg));
    if (no == 2) {
        //退出线程
        pthread_exit((void *) -1);
    }
    printf("I am a thread:%d\n", no);
    return 0;
}

/**
 * 创建线程
 */
void test1() {
    //创建线程
    pthread_t tid;
    for (int i = 0; i < 5; i++) {
        pthread_create(&tid, NULL, thread_run, (void *) i);
    }
    printf("I am main thread\n");
    sleep(1);
}

/**
 * 等待线程
 */
void test2() {
    pthread_t tid;
    pthread_create(&tid, NULL, thread_run, (void *) 2);
    printf("I am main thread\n");

    //等待线程
    int *retval;
    pthread_join(tid, (void **) &retval);
    printf("retval:%d\n", retval);
}

void *thread_run1(void *arg) {
    int no = static_cast<int>(reinterpret_cast<uintptr_t>(arg));
    while (1) {
        //printf会进内核，如果把这个注释掉，pthread_cancel会一直卡主
        printf("I am a thread:%d\n", no);

        //检测线程是否取消
//        pthread_testcancel();
    }
    return 0;
}

/**
 * 取消线程
 */
void test3() {
    pthread_t tid;
    pthread_create(&tid, NULL, thread_run1, (void *) 1);
    printf("I am main thread\n");

    sleep(5);
    //取消线程，需要有函数进内核
    pthread_cancel(tid);
}

void *thread_run2(void *arg) {
    int no = static_cast<int>(reinterpret_cast<uintptr_t>(arg));
    while (1) {
        printf("I am a thread:%d\n", no);
        sleep(2);
    }
    return 0;
}

/**
 * 线程分离
 */
void test4() {
    pthread_t tid;
    pthread_create(&tid, NULL, thread_run2, (void *) 1);
    //线程分离后，会直接往下执行，pthread_join就不会等thread_run2了
    pthread_detach(tid);
    printf("I am main thread\n");
    int *retval;
    pthread_join(tid, (void **) &retval);
    printf("retval:%d\n", retval);
    sleep(3);
}

/**
 * 线程同步
 */
long num = 0;
//锁
pthread_mutex_t mutex;

void *thread_run3(void *arg) {
    for (int i = 0; i < 2000000; i++) {
        //加锁
        pthread_mutex_lock(&mutex);
        num++;
        pthread_mutex_unlock(&mutex);
    }
    return 0;
}

void test5() {
    pthread_mutex_init(&mutex, NULL);
    pthread_t tid;
    for (int i = 0; i < 4; i++) {
        pthread_create(&tid, NULL, thread_run3, 0);
    }
    sleep(5);
    pthread_mutex_destroy(&mutex);
    printf("num=%ld", num);
}

/**
 * 生产者消费者
 */
pthread_cond_t product_cond;

void *consumer(void *arg) {

    for(;;) {
        pthread_mutex_lock(&mutex);
        while (num <= 0) {
            printf("等待生产者生成产品\n");
            pthread_cond_wait(&product_cond, &mutex);
        }
        num--;
        printf("消费产品:%ld\n", num);

        pthread_mutex_unlock(&mutex);
        sleep(2);
    }
    return 0;
}

void *producer(void *arg) {
    for(;;) {
        pthread_mutex_lock(&mutex);

        num++;
        printf("生产者生成产品:%ld\n", num);
        //通知消费者
        pthread_cond_signal(&product_cond);

        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return 0;
}

void test6() {
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&product_cond, NULL);  //类似Java中的Condition
    pthread_t tid;

    pthread_create(&tid, NULL, producer, NULL);
    pthread_detach(tid);
    pthread_create(&tid, NULL, consumer, NULL);
    pthread_detach(tid);
    while (1){}
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&product_cond);
}

int main() {
    test6();
    return 0;
}
