#include <cmath>
#include "iostream"
#include "queue"
#include "fstream"

using namespace std;
/**
 * 未完成，看这里https://github.com/nayuki/Reference-Huffman-coding
 */
class Huffman {
private:
    class Node {
    private:
        char Ch;
        int Freq;
        Node *Left;
        Node *Right;
    public:
        Node(char Ch, int Freq, Node *Left, Node *Right) : Ch(Ch), Freq(Freq), Left(Left), Right(Right) {

        }

        bool isLeaf() {
            return Left == NULL && Right == NULL;
        }

        char getCh() const {
            return Ch;
        }

        int getFreq() const {
            return Freq;
        }

        Node *getLeft() const {
            return Left;
        }

        Node *getRight() const {
            return Right;
        }

        class Compare {
        public:
            bool operator()(Node *a, Node *b) {
                return a->Freq > b->Freq;
            }
        };
    };

    /**
     * 构建Huffman树
     */
    static Node *buildTrie(int *freq) {
        //创建一个最小堆优先队列
        priority_queue<Node *, vector<Node *>, Node::Compare> pq;
        for (int i = 0; i < 256; i++) {
            char iChar = i;
            if (freq[iChar] > 0) {
                Node *temp = new Node(iChar, freq[iChar], NULL, NULL);
                pq.push(temp);
            }
        }
        Node *root = NULL;
        while (pq.size() > 1) {
            Node *l, *r;
            l = pq.top();
            pq.pop();

            r = pq.top();
            pq.pop();

            root = new Node(0, l->getFreq() + r->getFreq(), l, r);
            pq.push(root);
        }
        return pq.top();
    }

    /**
     * 用Huffman树构建编码：
     * s是Huffman编码字符串
     * 如果不是叶子结点，就递归调用
     * 如果往左走，就让s+‘0’;如果往右走，就让s+'1'
     * 如果是叶子结点，就可以把x结点的字符的编码保存到st中
     */
    static void buildCode(string *st, Node *x, string s) {
        if (!x->isLeaf()) {
            buildCode(st, x->getLeft(), s + '0');
            buildCode(st, x->getRight(), s + '1');
        } else {
            st[x->getCh()] = s;
        };
    }

    /**
     * 在计算机中，我们是按照一个字节八位来处理，而我们的编码有可能不是8的倍数，所以to8对我们的编码进行补零处理。
     */
    static string to8(string s) {
        int size = s.length();
        int mod = 8 - (size % 8);
        string bu = "";
        for (int i = 0; i < mod; i++)
            bu += "0";
        s += bu;
        return s;
    }

/**
 * 字符串为01串，把每个字节的'0'、'1'当做bit，然后转换为byte
 * 比如字符串“0100000101000010”就被我们处理为“AB”
 */
    static string getByte(string s) {
        string sByte = "";
        int round = s.length() / 8;
        for (int i = 0; i < round; i++) {
            int sum = 0;
            for (int j = 0; j < 8; j++) {
                if (s.at(8 * i + j) == '1') sum += (int) pow(2, 7 - j);
            }
            char temp = sum;
            sByte += temp;
        }
        return sByte;
    }

    /**
     * 在考虑解压时，我们需要同样的Huffman树才能进行解压，
     * 故我们还需要把Huffman树按照特定顺序写入到压缩文件开头。
     */

    static void writeTrie(Node *x, string &fileName) {
        ofstream output(fileName.c_str(), ios::out | ios::app | ios::binary);
        writeTrie(x, &output);
        output.close();
    }

    static void writeTrie(Node *x, ofstream *output) {
        if (x->isLeaf()) {
            //如果是叶子结点，就把true写入，并且把x结点的字符写入文件
            bool temp = true;
            output->write((char *) &temp, sizeof(bool));
            char xtemp = x->getCh();
            output->write((char *) &xtemp, sizeof(char));
            return;
        } else {
            //否则如果不是叶子结点，就只把false写入文件
            bool temp = false;
            output->write((char *) &temp, sizeof(bool));
            writeTrie(x->getLeft(), output);
            writeTrie(x->getRight(), output);
        }
    }

public:
    /**
     * 用Huffman编码压缩
     */
    static void compress(char *input, int len, string filename) {
        //创建freq数组，用来保存每个字符出现频数，并且扫描每个字符，统计频数
        int *freq = new int[256];
        for (int i = 0; i < 256; i++) {
            freq[i] = 0;
        }
        for (int i = 0; i < len; i++) {
            freq[input[i]]++;
        }
        Node *root = buildTrie(freq);

        string *st = new string[256];
        buildCode(st, root, "");
        //把用‘0’、‘1’表示的编码字符转转化为字节
        for (int i = 0; i < 256; i++) {
            st[i] = to8(st[i]);
            st[i] = getByte(st[i]);
        }
        //由于需要Huffman编码才能解码，所以用writeTrie把Huffman编码写入文件以便解码
        writeTrie(root, filename);
        ofstream output(filename.c_str(), ios::out | ios::app | ios::binary);
        output.write((char *) &len, sizeof(int));
        for (int i = 0; i < len; i++) {
            string code = st[input[i]];
            output.write((char *) &code, code.length());
        }
        delete freq;
        delete st;
        output.close();
    }
};

class BMP{
private:
    string path;
    string filename;

};