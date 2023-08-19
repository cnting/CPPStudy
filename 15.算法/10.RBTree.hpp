#define red true
#define black false
typedef bool rb_color;

#include "queue"

/**
 * 红黑树性质
 * 1.每个节点是红色或黑色
 * 2.根节点是黑色
 * 3.每个叶子节点(NIL)是黑色。这里说的叶子节点是空节点
 * 4.如果一个节点是红色的，它的子节点必须是黑色的
 * 5.从一个根节点到所有叶子节点的所有路径上包含相同数目的黑节点
 *
 * 红黑树 vs AVL树
 * 新增：AVL复杂度是log(N)，红黑树是log(N)/2
 * 查找：AVL复杂度是log(N)，红黑树是log(2N)
 * 删除：
 */
template<class K, class V>
class RBTree {
private:
    struct RBNode;
    RBNode *root;
    int count;

    /**
     * 出现双红怎么解决？
     * 1.父亲节点颜色是黑色的，不用解决
     * 2.叔叔节点是红色的，把叔叔节点染黑，把父亲节点染黑，然后指针回溯至爷爷，爷爷染红
     * 3.叔叔节点是黑色的，把父亲染黑，把爷爷染红，右旋爷爷
     * （1）如果当前节点是父亲的右儿子，把父亲节点左旋，变成情况2
     */
    void solveDoubleRed(RBNode *pNode) {
        while (pNode->parent && pNode->parent->color == red) {
            if (getColor(brother(parent(pNode))) == red) { //情况2
                setColor(parent(pNode), black);
                setColor(brother(parent(pNode)), black);
                setColor(parent(parent(pNode)), red);
                pNode = parent(parent(pNode));
            } else {
                //情况3
                if (left(parent(parent(pNode))) == parent(pNode)) {
                    if (right(parent(pNode)) == pNode) {
                        pNode = parent(pNode);
                        L_Rotation(pNode);
                    }
                    setColor(parent(pNode), black);
                    setColor(parent(parent(pNode)), red);
                    R_Rotation(parent(parent(pNode)));
                } else {
                    if (left(parent(pNode)) == pNode) {
                        pNode = parent(pNode);
                        R_Rotation(pNode);
                    }
                    setColor(parent(pNode), black);
                    setColor(parent(parent(pNode)), red);
                    L_Rotation(parent(parent(pNode)));
                }

            }
        }
        root->color = black;
    }

    /**
     * 失去了黑色节点，破坏了性质5，需要修正
     * 1.如果兄弟节点是红色的，把兄弟节点染黑，父节点染红，左/右旋父节点
     * 2.如果兄弟节点是黑色的，并且两个侄子节点都是黑色的，将兄弟节点染红，指针回溯至父亲节点
     * 3.如果兄弟节点是黑色的并且近侄子是红色的，远侄子是黑色，将近侄子染黑，兄弟染红，左/右旋兄弟节点，进入下面情况4
     * 4.如果兄弟节点是黑色的并且远侄子是红色的，将兄弟节点染成父亲节点的颜色，父亲节点染黑，远侄子染黑，左/右旋父亲节点
     */
    void solveLostBlack(RBNode *pNode) {
        while (pNode != root && pNode->color == black) {
            if (left(parent(pNode)) == pNode) { //当前节点是父亲节点的左节点  //情况1
                RBNode *sib = brother(pNode);
                if (getColor(sib) == red) {
                    setColor(sib, black);
                    setColor(parent(pNode), red);
                    L_Rotation(parent(pNode));
                    sib = brother(pNode);
                }

                if (getColor(left(sib)) == black && getColor(right(sib)) == black) {  //情况2
                    setColor(sib, red);
                    pNode = parent(pNode);
                } else {
                    if (getColor(right(sib)) == black) {
                        setColor(sib, red);
                        setColor(left(sib), black);
                        R_Rotation(sib);
                        sib = brother(sib);
                    }
                    setColor(sib, getColor(parent(pNode)));
                    setColor(parent(pNode), black);
                    setColor(right(sib), black);
                    L_Rotation(parent(pNode));

                    pNode = root;
                }
            } else {  //当前节点是父亲节点的右节点
                RBNode *sib = brother(pNode);
                if (getColor(sib) == red) {
                    setColor(sib, black);
                    setColor(parent(pNode), red);
                    R_Rotation(parent(pNode));
                    sib = brother(pNode);
                }

                if (getColor(left(sib)) == black && getColor(right(sib)) == black) {
                    setColor(sib, red);
                    pNode = parent(pNode);
                } else {
                    if (getColor(left(sib)) == black) {
                        setColor(sib, red);
                        setColor(right(sib), black);
                        L_Rotation(sib);
                        sib = brother(sib);
                    }
                    setColor(sib, getColor(parent(pNode)));
                    setColor(parent(pNode), black);
                    setColor(left(sib), black);
                    R_Rotation(parent(pNode));

                    pNode = root;
                }
            }
        }
        //当遇到一个红色节点，把红色节点染黑即可
        pNode->color = black;
    }


    RBNode *findTree(K key) {
        RBNode *node = root;
        while (node) {
            if (key == node->key) {
                return node;
            } else if (key > node->key) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
        return NULL;
    }

    RBNode *L_Rotation(RBNode *pNode) {
        RBNode *right = pNode->right;
        pNode->right = right->left;
        right->left = pNode;

        //调整pNode父亲的儿子指向
        if (pNode->parent == NULL) {
            root = right;
        } else if (pNode->parent->left == pNode) {
            pNode->parent->left = right;
        } else {
            pNode->parent->right = right;
        }

        right->parent = pNode->parent;
        if (pNode->right) {
            pNode->right->parent = pNode;
        }
        pNode->parent = right;

        return right;
    }

    RBNode *R_Rotation(RBNode *pNode) {
        RBNode *left = pNode->left;
        pNode->left = left->right;
        left->right = pNode;

        //调整pNode父亲的儿子指向
        if (pNode->parent == NULL) {
            root = left;
        } else if (pNode->parent->left == pNode) {
            pNode->parent->left = left;
        } else {
            pNode->parent->right = left;
        }

        left->parent = pNode->parent;
        if (pNode->left) {
            pNode->left->parent = pNode;
        }
        pNode->parent = left;

        return left;
    }

    void setColor(RBNode *pNode, bool color) {
        if (pNode) {
            pNode->color = color;
        }
    }

    bool getColor(RBNode *pNode) {
        return pNode ? pNode->color : black;
    }

    RBNode *parent(RBNode *pNode) {
        return pNode ? pNode->parent : NULL;
    }

    RBNode *brother(RBNode *pNode) {
        RBNode *l = left(parent(pNode));
        RBNode *r = right(parent(pNode));
        return l == pNode ? r : l;
    }

    RBNode *left(RBNode *pNode) {
        return pNode ? pNode->left : NULL;
    }

    RBNode *right(RBNode *pNode) {
        return pNode ? pNode->right : NULL;
    }

public:
    struct iterator;

    RBTree() : root(NULL) {
        count = 0;
    }

    iterator insert(K key, V value) {
        if (root == NULL) {
            root = new RBNode(NULL, NULL, NULL, key, value, black);
            count = 1;
            return iterator(root);
        }
        RBNode *node = root;
        RBNode *parent = NULL;
        do {
            parent = node;
            if (key == node->key) {
                node->value = value;
                return iterator(node);
            } else if (key > node->key) {
                node = node->right;
            } else {
                node = node->left;
            }
        } while (node);
        RBNode *new_node = new RBNode(NULL, NULL, parent, key, value, red);
        if (key > parent->key) {
            parent->right = new_node;
        } else {
            parent->left = new_node;
        }
        solveDoubleRed(new_node);
        count++;
        return iterator(new_node);
    }

    /**
     * 删除节点操作
     * 1.删除红色节点不影响
     * 2.假如删除一个黑色节点，会破坏性质5
     * 3.假设左右子树都不为空，需要找到后继节点来代替它，其实删除的是后继节点
     * 4.假设删除的节点的左右两棵子树上有一颗不为空的情况，会找不为空的那个子树来代替
     */
    bool remove(K key) {
        RBNode *current = findTree(key);
        if (current == NULL) {
            return false;
        }
        if (current->left != NULL && current->right != NULL) {
            RBNode *successor = current->successor();
            current->key = successor->key;
            current->value = successor->value;
            current = successor;
        }
        RBNode *replace = current->left ? current->left : current->right;

        if (replace != NULL) {
            if (parent(current) == NULL) {
                root = replace;
            } else if (current->parent->left == current) {
                current->parent->left = replace;
            } else {
                current->parent->right = replace;
            }
            replace->parent = current->parent;

            if (current->color == black) {
                solveLostBlack(replace);
            }
            delete (current);
        } else if (current->parent == NULL) {
            delete root;
            root = NULL;
        } else {
            if (current->color == black) {
                solveLostBlack(current);
            }
            if (current->parent) {
                if (current->parent->left == current) {
                    current->parent->left = NULL;
                } else {
                    current->parent->right = NULL;
                }
            }

            delete (current);
        }
        count--;
        return true;

    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    /**
   * 层序遍历
   */
    void rbLevelTraverse(void (*param)(K, bool isRed)) {
        if (root == NULL) return;
        RBNode *node = root;
        queue<RBNode *> nodes;
        nodes.push(node);
        while (!nodes.empty()) {
            node = nodes.front();
            nodes.pop();
            param(node->key, node->color);
            if (node->left != NULL) nodes.push(node->left);
            if (node->right != NULL) nodes.push(node->right);
        }
    }
};

template<class K, class V>
struct RBTree<K, V>::RBNode {

public:
    RBNode *left;
    RBNode *right;
    RBNode *parent;
    K key;
    V value;
    rb_color color;

    RBNode(RBNode *left,
           RBNode *right,
           RBNode *parent,
           K key,
           V value,
           rb_color color) : left(left), right(right), parent(parent), key(key), value(value), color(color) {}

    /**
     * 找前驱
     */
    RBNode *precursor() {
        if (left) {
            RBNode *node = left;
            while (node->right) {
                node = node->right;
            }
            return node;
        } else {
            RBNode *node = this;
            while (node->parent != NULL && node->parent->left == node) {
                node = node->parent;
            }
            return node->parent;
        }
    }

    /**
     * 找后继
     */
    RBNode *successor() {
        if (right) {
            RBNode *node = right;
            while (node->left) {
                node = node->left;
            }
            return node;
        } else {
            RBNode *node = this;
            while (node->parent != NULL && node->parent->right == node) {
                node = node->parent;
            }
            return node->parent;
        }
    }

};

template<class K, class V>
struct RBTree<K, V>::iterator {
private:
    RBNode *node;
public:
    iterator(RBNode *node) : node(node) {}


    iterator &operator--() {
        node = node->precursor();
        return this;
    }

    iterator &operator++() {
        node = node->successor();
        return this;
    }

    V operator*() {
        return node->value;
    }

};


