#include "queue"


template<class K, class V>
class AVLNode {
public:

    K key;
    V value;
    int height;
    AVLNode<K, V> *left;
    AVLNode<K, V> *right;

    AVLNode(K key, V value) : height(1) {
        left = NULL;
        right = NULL;
        this->key = key;
        this->value = value;
    }

    AVLNode(AVLNode<K, V> *pNode) : height(pNode->height) {
        this->left = pNode->left;
        this->right = pNode->right;
        this->key = pNode->key;
        this->value = pNode->value;
    }
};

template<class K, class V>
class AVL {
private:
    AVLNode<K, V> *root;
    int count;

    AVLNode<K, V> *addNode(AVLNode<K, V> *pNode, K key, V value) {
        if (pNode == NULL) {
            count++;
            return new AVLNode<K, V>(key, value);
        }
        if (pNode->key > key) {
            pNode->left = addNode(pNode->left, key, value);

            if (getHeight(pNode->left) - getHeight(pNode->right) == 2) {
                if (getHeight(pNode->left->right) > getHeight(pNode->left->left)) {
                    pNode = L_R_Rotation(pNode);
                } else {
                    pNode = R_Rotation(pNode);
                }
            }
        } else if (pNode->key < key) {
            pNode->right = addNode(pNode->right, key, value);

            if (getHeight(pNode->right) - getHeight(pNode->left) == 2) {
                if (getHeight(pNode->right->left) > getHeight(pNode->right->right)) {
                    pNode = R_L_Rotation(pNode);
                } else {
                    pNode = L_Rotation(pNode);
                }
            }
        } else {
            pNode->value = value;
        }

        pNode->height = max(getHeight(pNode->left), getHeight(pNode->right)) + 1;
        return pNode;
    }

    AVLNode<K, V> *removeNode(AVLNode<K, V> *pNode, K key) {
        if (pNode == NULL) return NULL;
        if (pNode->key > key) {
            pNode->left = removeNode(pNode->left, key);

            if (getHeight(pNode->right) - getHeight(pNode->left) == 2) {
                if (getHeight(pNode->right->left) > getHeight(pNode->right->right)) {
                    pNode = R_L_Rotation(pNode);
                } else {
                    pNode = L_Rotation(pNode);
                }
            }

        } else if (pNode->key < key) {
            pNode->right = removeNode(pNode->right, key);

            if (getHeight(pNode->left) - getHeight(pNode->right) == 2) {
                if (getHeight(pNode->left->right) > getHeight(pNode->left->left)) {
                    pNode = L_R_Rotation(pNode);
                } else {
                    pNode = R_Rotation(pNode);
                }
            }

        } else {
            count--;
            if (pNode->left == NULL && pNode->right == NULL) {
                delete pNode;
                return NULL;
            } else if (pNode->left == NULL) {
                AVLNode<K, V> *right = pNode->right;
                delete pNode;
                pNode = right;
            } else if (pNode->right == NULL) {
                AVLNode<K, V> *left = pNode->left;
                delete pNode;
                pNode = left;
            } else {
                if (getHeight(pNode->left) > getHeight(pNode->right)) {
                    AVLNode<K, V> *m = maximum(pNode->left);
                    AVLNode<K, V> *successor = new AVLNode<K, V>(m);
                    successor->left = removeNode(pNode->left, m->key);
                    count++;
                    successor->right = pNode->right;
                    delete pNode;
                    pNode = successor;
                } else {
                    AVLNode<K, V> *m = minimum(pNode->right);
                    AVLNode<K, V> *successor = new AVLNode<K, V>(m);
                    successor->right = removeNode(pNode->right, m->key);
                    count++;
                    successor->left = pNode->left;
                    delete pNode;
                    pNode = successor;
                }

            }
        }
        pNode->height = max(getHeight(pNode->left), getHeight(pNode->right)) + 1;
        return pNode;
    }

    AVLNode<K, V> *maximum(AVLNode<K, V> *pNode) {
        if (pNode->right == NULL) {
            return pNode;
        }
        return maximum(pNode->right);
    }

    AVLNode<K, V> *minimum(AVLNode<K, V> *pNode) {
        if (pNode->left == NULL) {
            return pNode;
        }
        return minimum(pNode->left);
    }

    AVLNode<K, V> *deleteMax(AVLNode<K, V> *pNode) {
        if (pNode->right == NULL) {
            AVLNode<K, V> *left = pNode->left;
            delete pNode;
            count--;
            return left;
        }
        pNode->right = deleteMax(pNode->right);
        return pNode;
    }


    /**
     * 右旋
     */
    AVLNode<K, V> *R_Rotation(AVLNode<K, V> *pNode) {
        AVLNode<K, V> *left = pNode->left;
        AVLNode<K, V> *leftRight = left->right;
        left->right = pNode;
        pNode->left = leftRight;

        pNode->height = max(getHeight(pNode->left), getHeight(pNode->right)) + 1;
        left->height = max(getHeight(left->left), getHeight(left->right)) + 1;

        return left;
    }

    /**
     * 先左旋再右旋
     */
    AVLNode<K, V> *L_R_Rotation(AVLNode<K, V> *pNode) {
        pNode->left = L_Rotation(pNode->left);
        return R_Rotation(pNode);
    }

    /**
     * 先右旋再左旋
     */
    AVLNode<K, V> *R_L_Rotation(AVLNode<K, V> *pNode) {
        pNode->right = R_Rotation(pNode->right);
        return L_Rotation(pNode);
    }

    /**
     * 左旋
     */
    AVLNode<K, V> *L_Rotation(AVLNode<K, V> *pNode) {
        AVLNode<K, V> *right = pNode->right;
        AVLNode<K, V> *rightLeft = right->left;
        right->left = pNode;
        pNode->right = rightLeft;

        pNode->height = max(getHeight(pNode->left), getHeight(pNode->right)) + 1;
        right->height = max(getHeight(right->left), getHeight(right->right)) + 1;
        return right;
    }

    int getHeight(AVLNode<K, V> *pNode) {
        return pNode ? pNode->height : 0;
    }

    void inOrderTraverse(AVLNode<K, V> *node, void (*param)(K, V)) {
        if (node == NULL) return;
        inOrderTraverse(node->left, param);
        param(node->key, node->value);
        inOrderTraverse(node->right, param);
    }

public:
    AVL() {
        root = NULL;
        count = 0;
    }

    ~AVL() {
        if (!isEmpty()) {
            queue<AVLNode<K, V> *> q;
            q.push(root);
            while (!q.empty()) {
                AVLNode<K, V> *f = q.front();
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
        AVLNode<K, V> *p = root;
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
        root = removeNode(root, key);
    }

    bool contains(K key) {
        AVLNode<K, V> *node = root;
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

    /**
     * 中序遍历
     */
    void inOrderTraverse(void (*param)(K, V)) {
        inOrderTraverse(root, param);
    }

    /**
    * 层序遍历
    */
    void levelTraverse(void (*param)(K, V)) {
        if (root == NULL) return;
        AVLNode<K, V> *node = root;
        queue<AVLNode<K, V> *> nodes;
        nodes.push(node);
        while (!nodes.empty()) {
            node = nodes.front();
            nodes.pop();
            param(node->key, node->value);
            if (node->left != NULL) nodes.push(node->left);
            if (node->right != NULL) nodes.push(node->right);
        }
    }


    bool isEmpty() {
        return count == 0;
    }
};
