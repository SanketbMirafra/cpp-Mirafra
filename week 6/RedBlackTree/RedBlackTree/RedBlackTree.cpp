#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node* parents;
    int color; 

    Node(int data) {
        value = data;
        color = 1; 
        left = right = parents = nullptr;
    }
};

class RedBlackTree {
    Node* root;

    void bstInsert(Node*& root, Node* newNode) {
        if (root == nullptr) {
            root = newNode;
            root->color = 0; 
            return;
        }

        Node* temp = root;
        Node* parent = nullptr;
        while (temp != nullptr) {
            parent = temp;
            if (temp->value > newNode->value) {
                temp = temp->left;
            }
            else if (temp->value < newNode->value) {
                temp = temp->right;
            }
            else {
                return; 
            }
        }

        newNode->parents = parent;
        if (parent->value > newNode->value) {
            parent->left = newNode;
        }
        else {
            parent->right = newNode;
        }
    }

    void rightRotate(Node*& root, Node* pt) {
        Node* x = pt->left;
        Node* y = x->right;

        pt->left = y;
        if (y != nullptr) {
            y->parents = pt;
        }

        x->parents = pt->parents;

        if (pt->parents == nullptr) {
            root = x;
        }
        else if (pt == pt->parents->left) {
            pt->parents->left = x;
        }
        else {
            pt->parents->right = x;
        }

        x->right = pt;
        pt->parents = x;
    }

    void leftRotate(Node*& root, Node* pt) {
        Node* y = pt->right;

        pt->right = y->left;
        if (y->left != nullptr) {
            y->left->parents = pt;
        }

        y->parents = pt->parents;

        if (pt->parents == nullptr) {
            root = y;
        }
        else if (pt == pt->parents->left) {
            pt->parents->left = y;
        }
        else {
            pt->parents->right = y;
        }

        y->left = pt;
        pt->parents = y;
    }

    void fixViolation(Node*& root, Node* pt) {
        Node* parent = nullptr;
        Node* grandParents = nullptr;

        while (pt != root && pt->color == 1 && pt->parents->color == 1) {
            parent = pt->parents;
            grandParents = parent->parents;

            if (parent == grandParents->left) {
                Node* uncle = grandParents->right;

                if (uncle != nullptr && uncle->color == 1) {
                    uncle->color = 0;
                    parent->color = 0;
                    grandParents->color = 1;
                    pt = grandParents;
                }
                else {
                    if (pt == parent->right) {
                        leftRotate(root, parent);
                        pt = parent;
                        parent = pt->parents;
                    }

                    rightRotate(root, grandParents);
                    swap(parent->color, grandParents->color);
                    pt = parent;
                }
            }
            else {
                Node* uncle = grandParents->left;

                if (uncle != nullptr && uncle->color == 1) {
                    uncle->color = 0;
                    parent->color = 0;
                    grandParents->color = 1;
                    pt = grandParents;
                }
                else {
                    if (pt == parent->left) {
                        rightRotate(root, parent);
                        pt = parent;
                        parent = pt->parents;
                    }

                    leftRotate(root, grandParents);
                    swap(parent->color, grandParents->color);
                    pt = parent;
                }
            }
        }

        root->color = 0;
    }

    void deleteFix(Node*& root, Node* x) {
        while (x != root && (x == nullptr || x->color == 0)) {
            if (x == x->parents->left) {
                Node* sibling = x->parents->right;

                if (sibling->color == 1) {
                    sibling->color = 0;
                    x->parents->color = 1;
                    leftRotate(root, x->parents);
                    sibling = x->parents->right;
                }

                if ((sibling->left == nullptr || sibling->left->color == 0) &&
                    (sibling->right == nullptr || sibling->right->color == 0)) {
                    sibling->color = 1;
                    x = x->parents;
                }
                else {
                    if (sibling->right == nullptr || sibling->right->color == 0) {
                        sibling->left->color = 0;
                        sibling->color = 1;
                        rightRotate(root, sibling);
                        sibling = x->parents->right;
                    }

                    sibling->color = x->parents->color;
                    x->parents->color = 0;
                    sibling->right->color = 0;
                    leftRotate(root, x->parents);
                    x = root;
                }
            }
            else {
                Node* sibling = x->parents->left;

                if (sibling->color == 1) {
                    sibling->color = 0;
                    x->parents->color = 1;
                    rightRotate(root, x->parents);
                    sibling = x->parents->left;
                }

                if ((sibling->left == nullptr || sibling->left->color == 0) &&
                    (sibling->right == nullptr || sibling->right->color == 0)) {
                    sibling->color = 1;
                    x = x->parents;
                }
                else {
                    if (sibling->left == nullptr || sibling->left->color == 0) {
                        sibling->right->color = 0;
                        sibling->color = 1;
                        leftRotate(root, sibling);
                        sibling = x->parents->left;
                    }

                    sibling->color = x->parents->color;
                    x->parents->color = 0;
                    sibling->left->color = 0;
                    rightRotate(root, x->parents);
                    x = root;
                }
            }
        }

        if (x != nullptr) {
            x->color = 0;
        }
    }

    void transplant(Node*& root, Node* u, Node* v) {
        if (u->parents == nullptr) {
            root = v;
        }
        else if (u == u->parents->left) {
            u->parents->left = v;
        }
        else {
            u->parents->right = v;
        }

        if (v != nullptr) {
            v->parents = u->parents;
        }
    }

    Node* minimum(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void deleteNodeHelper(Node*& root, Node* z) {
        Node* y = z;
        Node* x;
        int originalColor = y->color;

        if (z->left == nullptr) {
            x = z->right;
            transplant(root, z, z->right);
        }
        else if (z->right == nullptr) {
            x = z->left;
            transplant(root, z, z->left);
        }
        else {
            y = minimum(z->right);
            originalColor = y->color;
            x = y->right;

            if (y->parents == z) {
                if (x != nullptr) {
                    x->parents = y;
                }
            }
            else {
                transplant(root, y, y->right);
                y->right = z->right;
                y->right->parents = y;
            }

            transplant(root, z, y);
            y->left = z->left;
            y->left->parents = y;
            y->color = z->color;
        }

        if (originalColor == 0) {
            deleteFix(root, x);
        }
    }

public:
    RedBlackTree() {
        root = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        bstInsert(root, newNode);
        fixViolation(root, newNode);
    }

    void deleteNode(int value) {
        Node* z = root;
        while (z != nullptr) {
            if (z->value == value) {
                deleteNodeHelper(root, z);
                return;
            }
            else if (z->value > value) {
                z = z->left;
            }
            else {
                z = z->right;
            }
        }
        cout << "Value not found in the tree.\n";
    }

    void inorder(Node* node) {
        if (node == nullptr) {
            return;
        }

        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }

    void display() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    RedBlackTree rbt;

    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(30);
    rbt.insert(15);
    rbt.insert(25);
    rbt.insert(5);

    cout << "Inorder Traversal of Created Tree: \n";
    rbt.display();

    cout << "\nDeleting 15:\n";
    rbt.deleteNode(15);
    rbt.display();

    cout << "\nDeleting 10:\n";
    rbt.deleteNode(10);
    rbt.display();

    return 0;
}
