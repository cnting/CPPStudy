
#include <cstdio>

void hannuota(int n, char start, char help, char end) {
    if (n == 1) {
        printf("把 %d 盘子从 %c 挪动到 %c\n", n, start, end);
    } else {
        hannuota(n - 1, start, end, help);
        printf("把 %d 盘子从 %c 挪动到 %c\n", n, start, end);
        hannuota(n - 1, help, start, end);
    }
}