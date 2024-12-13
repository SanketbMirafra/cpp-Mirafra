

#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T value;
    Node* left;
    Node* right;
    Node() {
        value = NULL;
        left = right = nullptr;
    }
    Node(T data) {
        value = data;                         
        left = right = nullptr;
    }
};

template <typename T>
class BinarySearchTree {

public:
    Node<T>* root;
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int value) {
        Node<T>* temp = new Node<T>(value);
        if (root == nullptr) {
            root = temp;
            return;
        }
        Node<T>* demo = root;
        Node<T>* parents = nullptr;
       
        while (demo != nullptr ) {
            if (demo->value > value) {
                parents = demo;
                demo = demo->left;
            }
            else {
                parents = demo;
                demo = demo->right;
            }
        }
        if (parents->value > value) parents->left = temp;
        else parents->right = temp;

    }

    void inOrder(Node<T>* node) {
        if (node == nullptr) {
            return;
        }
        else {
            inOrder(node->left);
            cout << node->value << " ";
            inOrder(node->right);
        }

    }
    void preOrder(Node<T>* node) {
        if (node == nullptr) {
            return;
        }
        else {
            cout << node->value << " ";
            preOrder(node->left);
            preOrder(node->right);
        }

    }

    void postOrder(Node<T>* node) {
        if (node == nullptr) {
            return;
        }
        else {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->value << " ";
        }

    }

    Node<T>* deleteNode(Node<T>* root, T value) {
           
        if (root == nullptr)return nullptr;

        if (value < root->value) {
            root->left = deleteNode(root->left, value);
        }
        else if (value > root->value) {
            root->right = deleteNode(root->right, value);
        }
        else {

            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }

            if (root->left == nullptr) {
                Node<T>* temp = root->right;
                delete root;
                return temp;
            }
            if (root->right == nullptr) {
                Node<T>* temp = root->left;
                delete root;
                return temp;
            }

            Node<T>* temp = findMin(root->right); // Find the inorder successor
            root->value = temp->value; // Replace the value
            root->right = deleteNode(root->right, temp->value); // Delete successor

        }

        return root;
    }

    Node<T>* findMin(Node<T>* node) {
        if (node == nullptr) return nullptr;

        while (node->left != nullptr) {
            node = node->left;
        }

        return node;
    }

    void reverseBst(Node<T>* root) {
        if (root == nullptr)return;

        if (root->left != nullptr)reverseBst(root->left);
        if (root->right != nullptr)reverseBst(root->right);

        Node<T>* temp = root->right;
        root->right = root->left;
        root->left = temp;
    }
};

int main()
{
    std::cout << "Binary Search Tree"<<endl<<endl;

    BinarySearchTree<int> bst;
    bst.insert(7);
    bst.insert(10);
    bst.insert(70);
    bst.insert(8);
    bst.insert(230);
    bst.insert(4);
    bst.insert(780);
    bst.insert(0);
    bst.insert(1);
    bst.deleteNode(bst.root, 7);
    bst.reverseBst(bst.root);
    bst.inOrder(bst.root);
}

