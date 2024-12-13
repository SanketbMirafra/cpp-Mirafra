

#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Node{
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
class BinaryTree {

public:
    Node<T>* root;

    BinaryTree() {
        root = nullptr;
    }
  
    void insertLeaves(T data, Node<T>*& root1) {
        Node<T>* newNode = new Node<T>(data);

        if (root1 == nullptr) {
            root1 = newNode;
            return;
        }
        queue<Node<T>*> q;
        q.push(root1);

        while (!q.empty()) {
            Node<T>* temp = q.front();
            q.pop();

            if (temp->left == nullptr) {
                temp->left = newNode;
                return;
            }
            else {
                q.push(temp->left);
            }

            if (temp->right == nullptr) {
                temp->right = newNode;
                return;
            }
            else {
                q.push(temp->right);
            }
        }
    }


    void deleteDeepest(Node<T>*& root1) {
        if (root1 == nullptr) return;

        if (root1->left == nullptr && root1->right == nullptr) {
            delete root1;
            root1 = nullptr;
            root = nullptr;
            return;
        }

        Node<T>* parent = nullptr;
        Node<T>* deepest = root1;
        queue<Node<T>*> q;
        q.push(root1);

        while (!q.empty()) {
            Node<T>* temp = q.front();
            q.pop();

            if (temp->left) {
                parent = temp;
                deepest = temp->left;
                q.push(temp->left);
            }
            if (temp->right) {
                parent = temp;
                deepest = temp->right;
                q.push(temp->right);
            }
        }

        root1->value = deepest->value;

        if (parent->left == deepest)
            parent->left = nullptr;
        else
            parent->right = nullptr;

        delete deepest;
    }


    void deleteNode(int value) {
        if (root == nullptr) return;

        Node<T>* parent = nullptr;
        Node<T>* deepest = root;
        Node<T>* demo = nullptr;
        queue<Node<T>*> q;
        q.push(root);

        while (!q.empty()) {
            Node<T>* temp = q.front();
            q.pop();

            if (temp->left) {
                parent = temp;
                deepest = temp->left;
                q.push(temp->left);
            }
           if (temp->right) {
                parent = temp;
                deepest = temp->right;
                q.push(temp->right);
            }

            if (demo == nullptr && temp->value == value) {
                demo = temp;
            }
        }

        demo->value = deepest->value;

        if (parent->left == deepest) {
            parent->left = nullptr;
        }
        else parent->right = nullptr;
        
       delete deepest;

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


};

int main()
{
    std::cout << "---------- Binary Tree ----------"<<endl<<endl;

    BinaryTree<int> bt;
    bt.insertLeaves(10, bt.root);
    bt.insertLeaves(20, bt.root);
    bt.insertLeaves(30, bt.root);
    bt.insertLeaves(40, bt.root);
    bt.insertLeaves(50, bt.root);
    bt.insertLeaves(60, bt.root);
    bt.insertLeaves(70, bt.root);
    bt.insertLeaves(80, bt.root);
    bt.insertLeaves(90, bt.root);
    bt.insertLeaves(100, bt.root);
    bt.insertLeaves(110, bt.root);
    bt.insertLeaves(120, bt.root);
    bt.insertLeaves(130, bt.root);
    bt.deleteDeepest(bt.root);

    cout << "Inorder Traversal : " << endl;
    bt.inOrder(bt.root); cout << endl<<endl;
    cout << "Postorder Traversal : " << endl;
    bt.postOrder(bt.root); cout << endl << endl;
    cout << "Preorder Traversal : " << endl;
    bt.preOrder(bt.root);
    cout << endl << endl;
    bt.deleteNode(130);
    cout << "Inorder Traversal : " << endl;
    bt.inOrder(bt.root); cout << endl << endl;
    cout << "Postorder Traversal : " << endl;
    bt.postOrder(bt.root); cout << endl << endl;
    cout << "Preorder Traversal : " << endl;
    bt.preOrder(bt.root);
    cout << endl << endl;

    return 0;
}

