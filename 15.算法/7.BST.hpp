#include "queue"

template<class K, class V>
class TreeNode {
public:

    K key;
    V value;
    TreeNode<K, V> *left;
    TreeNode<K, V> *right;

    TreeNode(K key, V value) {
        left = NULL;
        right = NULL;
        this->key = key;
        this->value = value;
    }

    TreeNode(TreeNode<K, V> *pNode) {
        this->left = pNode->left;
        this->right = pNode->right;
        this->key = pNode->key;
        this->value = pNode->value;
    }
};

template<class K, class V>
class BST {
private:
    TreeNode<K, V> *root;
    int count;

    TreeNode<K, V> *addNode(TreeNode<K, V> *pNode, K key, V value) {
        if (pNode == NULL) {
            count++;
            return new TreeNode<K, V>(key, value);
        }
        if (pNode->key > key) {
            pNode->left = addNode(pNode->left, key, value);
        } else if (pNode->key < key) {
            pNode->right = addNode(pNode->right, key, value);
        } else {
            pNode->value = value;
        }
        return pNode;
    }


    void inOrderTraverse(TreeNode<K, V> *node, void (*param)(K, V)) {
        if (node == NULL) return;
        inOrderTraverse(node->left, param);
        param(node->key, node->value);
        inOrderTraverse(node->right, param);
    }

public:
    BST() {
        root = NULL;
        count = 0;
    }

    ~BST() {
        if (!isEmpty()) {
            queue < TreeNode<K, V> * > q;
            q.push(root);
            while (!q.empty()) {
                TreeNode<K, V> *f = q.front();
                q.pop();
                if (f->left != NULL) q.push(f->left);
                if (f->right != NULL) q.push(f->right);
                delete f;
            }
            root = NULL;
        }
    }

    void put(K key, V value) {
        root = addNode(root, key, value);
    }

    V get(K key) {
        TreeNode<K, V> *p = root;
        while (p != NULL) {
            if (p->key < key) p = p->right;
            else if (p->key > key) p = p->left;
            else return p->value;
        }
        return NULL;
    }

    int size() {
        return count;
    }

    void remove(K key) {
        TreeNode<K, V> *p = root;
        TreeNode<K, V> *pp = NULL;
        //找要删除节点
        while (p != NULL && p->key != key) {
            pp = p;
            if (p->key < key) p = p->right;
            else p = p->left;
        }
        //没有找到要删除节点
        if (p == NULL) return;

        //左右子节点都不为空，找左子节点的最右子节点（最大值）
        if (p->left != NULL && p->right != NULL) {
            TreeNode<K, V> *childP = p->left;
            TreeNode<K, V> *childPP = p;
            while (childP->right != NULL) {
                childPP = childP;
                childP = childP->right;
            }
            p->key = childP->key;
            p->value = childP->value;
            p = childP;  // 下面就变成了删除childP了
            pp = childPP;
        }
        TreeNode<K, V> *child = NULL;
        if (p->left != NULL) {
            child = p->left;
        } else if (p->right != NULL) {
            child = p->right;
        }
        //要删除的是根节点
        if (pp == NULL) root = child;
        else if (pp->left == p) pp->left = child;
        else if (pp->right == p) pp->right = child;
        delete p;
        count--;
    }

    bool contains(K key) {
        TreeNode<K, V> *node = root;
        while (node) {
            if (node->key == key) {
                return true;
            } else if (node->key < key) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
        return false;
    }

    void inOrderTraverse(void (*param)(K, V)) {
        inOrderTraverse(root, param);
    }


    bool isEmpty() {
        return count == 0;
    }
};
