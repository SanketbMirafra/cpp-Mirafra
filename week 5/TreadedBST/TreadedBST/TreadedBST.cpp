#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;
    bool isThreaded;

    Node(int data) {
        value = data;
        left = nullptr;
        right = nullptr;
        isThreaded = false;
    }
};

class ThreadBST {
public:
    Node* root = nullptr;

    void insert(int data) {
        Node* newNode = new Node(data);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* current = root;
        Node* parent = nullptr;

        while (current != nullptr) {
            parent = current;

            if (data < current->value) {
                if (current->left == nullptr) break;
                current = current->left;
            }
            else {
                if (current->right == nullptr || current->isThreaded) break;
                current = current->right;
            }
        }


        if (data < parent->value) {
            parent->left = newNode;
            newNode->right = parent;
            newNode->isThreaded = true;
        }
        else {
            newNode->right = parent->right;
            newNode->isThreaded = parent->isThreaded;
            parent->right = newNode;
            parent->isThreaded = false;
        }
    }

    void deleteNode(int data) {
        Node* parent = nullptr;
        Node* current = root;

        while (current != nullptr && current->value != data) {
            parent = current;
            if (data < current->value) {
                current = current->left;
            }
            else {
                if (current->isThreaded) break;
                current = current->right;
            }
        }

        if (current == nullptr || current->value != data) {
            cout << "Value not found in the tree." << endl;
            return;
        }

        if (current->left == nullptr && (current->right == nullptr || current->isThreaded)) {
            if (parent == nullptr) {
                root = nullptr;
            }
            else if (parent->left == current) {
                parent->left = nullptr;
            }
            else {
                parent->right = current->right;
                parent->isThreaded = true;
            }
            delete current;
        }
        else if (current->left == nullptr || (current->right == nullptr || current->isThreaded)) {
            Node* child = (current->left != nullptr) ? current->left : current->right;

            if (parent == nullptr) {
                root = child;
            }
            else if (parent->left == current) {
                parent->left = child;
            }
            else {
                parent->right = child;
                parent->isThreaded = current->isThreaded;
            }
            if (current->isThreaded && child != nullptr) {
                child->right = current->right;
                child->isThreaded = true;
            }
            delete current;
        }
        else {
            Node* successorParent = current;
            Node* successor = current->right;
            while (successor->left != nullptr) {
                successorParent = successor;
                successor = successor->left;
            }

            current->value = successor->value;
            if (successorParent->left == successor) {
                successorParent->left = (successor->isThreaded) ? nullptr : successor->right;
            }
            else {
                successorParent->right = successor->right;
                successorParent->isThreaded = successor->isThreaded;
            }
            delete successor;
        }
    }

    void display() {
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
            return;
        }

        Node* current = root;

        while (current->left != nullptr) {
            current = current->left;
        }


        while (current != nullptr) {
            cout << current->value << " ";
            if (current->isThreaded) {
                current = current->right;
            }
            else {

                current = current->right;
                while (current != nullptr && current->left != nullptr) {
                    current = current->left;
                }
            }
        }
        cout << endl;
    }
};

int main() {
    cout << "Threaded Binary Search Tree" << endl << endl;

    ThreadBST bst;
    bst.insert(50);
    bst.insert(60);
    bst.insert(70);
    bst.insert(12);
    bst.insert(23);
    bst.insert(36);
    bst.insert(25);
    bst.insert(9);

    cout << "Initial tree: " << endl;
    bst.display();

    cout << "\nDeleting 23:" << endl;
    bst.deleteNode(23);
    bst.display();

    cout << "\nDeleting 50:" << endl;
    bst.deleteNode(50);
    bst.display();

    return 0;
}
