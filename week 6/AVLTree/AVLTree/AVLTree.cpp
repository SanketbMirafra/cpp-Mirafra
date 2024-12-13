
#include <iostream>
using namespace std;

class Node {

public:
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        height = 1;
        left = right = nullptr;
    }
};

class AVLTree {
    Node* root;

    // Get Height of the Tree
    int getHeight(Node* node) {
        return node ? node->height : 0;
    }

    //Get Balace Factor of Tree
    int getBalaceFactor(Node* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    Node* rightRotation(Node* node) {

        Node* x = node->left;
        Node* y = x->right;

        x->right = node;
        node->left = y;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    Node* leftRotation(Node* node) {

        Node* x = node->right;
        Node* y = x->left;

        x->left = node;
        node->right = y;

        node->height = 1+ max(getHeight(node->left), getHeight(node->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    void inorder(Node* node, string s) {

        if (node == nullptr) {
            return;
        }

        inorder(node->left, "left");
        cout << node->data << " "<<s<<" ";
        inorder(node->right, "right");
    }

    //Insert function for data
    Node* insert(Node* root, int data) {
        
        if (root == nullptr) return new Node(data);

        if (data < root->data) {
            root->left = insert(root->left, data);
        }
        else if (data > root->data) {
            root->right = insert(root->right, data);
        }
        else {
            return root;
        }

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int balace = getBalaceFactor(root);

        if (balace > 1 && data < root->left->data) {
            return rightRotation(root);
        }

        if (balace < -1 && data > root->right->data) {
            return leftRotation(root);
        }

        if (balace > 1 && data > root->left->data) {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }

        if (balace < -1 && data < root->right->data) {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }

        return root;
    }

    // find minimum node for deleting perticular node
    Node* findMinNode(Node* node) {
        if (node == nullptr)return nullptr;

        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Delete Given Value Fron This Node
    Node* deleteNode(Node* node, int key) {
        if (node == nullptr) return nullptr;

        if (node->data > key) {
            node->left = deleteNode(node->left, key);
        }
        else if (node->data < key) {
            node->right = deleteNode(node->right, key);
        }
        else {

            if (node->right == nullptr && node->left == nullptr) {
                delete node;
                return nullptr;
            }
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* minNode = findMinNode(node->right);
            node->data = minNode->data;
            node->right = deleteNode(node->right, minNode->data);
        }

        //balace tree
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balace = getBalaceFactor(node);

        // Balance the tree after deletion
        if (balace > 1) {
            if (getBalaceFactor(node->left) >= 0) {
                return rightRotation(node); // Left-Left case
            }
            else {
                node->left = leftRotation(node->left); // Left-Right case
                return rightRotation(node);
            }
        }

        if (balace < -1) {
            if (getBalaceFactor(node->right) <= 0) {
                return leftRotation(node); // Right-Right case
            }
            else {
                node->right = rightRotation(node->right); // Right-Left case
                return leftRotation(node);
            }
        }


        return node;


    }



public:
    AVLTree() {
        root = nullptr;
    }

    void insert(int data) {
        root = insert(root, data);
    }

    void inorder() {
        inorder(root, "root");
    }

    void deleteNode(int key) {
        root = deleteNode(root, key);
    }
};


int main()
{
    std::cout << "--------------- AVLTree  ------------" << endl << endl;

    AVLTree av;

    av.insert(10);
    av.insert(20);
    av.insert(30);
    av.insert(40);
    av.insert(50);
    av.insert(60);
    //av.deleteNode(30);
    av.inorder();
}
