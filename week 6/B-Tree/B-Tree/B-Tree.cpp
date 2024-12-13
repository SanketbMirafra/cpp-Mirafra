#include <iostream>
#include <vector>
using namespace std;

class BTreeNode {
public:
    vector<int> keys;            
    vector<BTreeNode*> children; 
    bool isLeaf;                  
    int t;                       

    
    BTreeNode(int t, bool isLeaf);

   
    ~BTreeNode() {
        for (auto child : children) {
            delete child;
        }
    }
};


BTreeNode::BTreeNode(int t, bool isLeaf) {
    this->t = t;
    this->isLeaf = isLeaf;
}


class BTree {
    BTreeNode* root; 
    int t;         

public:
    
    BTree(int t) {
        root = nullptr;
        this->t = t;
    }

   
    ~BTree() {
        delete root;
    }

    
    void traverse() {
        if (root) {
            traverseNode(root);
        }
    }

    BTreeNode* search(int key) {
        return (root == nullptr) ? nullptr : searchNode(root, key);
    }

    void insert(int key);

private:
 
    void traverseNode(BTreeNode* node);

    BTreeNode* searchNode(BTreeNode* node, int key);
    void insertNonFull(BTreeNode* node, int key);
    void splitChild(BTreeNode* parent, int i, BTreeNode* child);
};

void BTree::traverseNode(BTreeNode* node) {
    for (int i = 0; i < node->keys.size(); i++) {
        if (!node->isLeaf) {
            traverseNode(node->children[i]);
        }
        cout << node->keys[i] << " ";
    }
    if (!node->isLeaf) {
        traverseNode(node->children[node->keys.size()]);
    }
}


BTreeNode* BTree::searchNode(BTreeNode* node, int key) {
    int i = 0;
    while (i < node->keys.size() && key > node->keys[i]) {
        i++;
    }
    if (i < node->keys.size() && node->keys[i] == key) {
        return node;
    }
    if (node->isLeaf) {
        return nullptr;
    }
    return searchNode(node->children[i], key);
}

// Insert a new key into the B-tree
void BTree::insert(int key) {
    if (root == nullptr) {
        root = new BTreeNode(t, true);
        root->keys.push_back(key);
    }
    else {
        if (root->keys.size() == 2 * t - 1) {
            BTreeNode* newNode = new BTreeNode(t, false);
            newNode->children.push_back(root);
            splitChild(newNode, 0, root);

            int i = (newNode->keys[0] < key) ? 1 : 0;
            insertNonFull(newNode->children[i], key);
            root = newNode;
        }
        else {
            insertNonFull(root, key);
        }
    }
}

// Insert a key into a non-full node
void BTree::insertNonFull(BTreeNode* node, int key) {
    int i = node->keys.size() - 1;

    if (node->isLeaf) {
        node->keys.push_back(0); 
        while (i >= 0 && node->keys[i] > key) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
    }
    else {
        while (i >= 0 && node->keys[i] > key) {
            i--;
        }
        i++;
        if (i < node->children.size() && node->children[i]->keys.size() == 2 * t - 1) {
            splitChild(node, i, node->children[i]);
            if (node->keys[i] < key) {
                i++;
            }
        }
        if (i < node->children.size()) {
            insertNonFull(node->children[i], key);
        }
    }
}

// Split a child node
void BTree::splitChild(BTreeNode* parent, int i, BTreeNode* child) {
    BTreeNode* newNode = new BTreeNode(child->t, child->isLeaf);
    int mid = child->t - 1;

    for (int j = mid + 1; j < child->keys.size(); j++) {
        newNode->keys.push_back(child->keys[j]);
    }
    child->keys.resize(mid);

    if (!child->isLeaf) {
        for (int j = mid + 1; j < child->children.size(); j++) {
            newNode->children.push_back(child->children[j]);
        }
        child->children.resize(mid + 1);
    }

    parent->children.insert(parent->children.begin() + i + 1, newNode);
    parent->keys.insert(parent->keys.begin() + i, child->keys[mid]);
}

int main() {
    BTree tree(3);

    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);

    cout << "Traversal of the tree: ";
    tree.traverse();
    cout << endl;

    int key = 6;
    if (tree.search(key)) {
        cout << "Key " << key << " is present in the tree.\n";
    }
    else {
        cout << "Key " << key << " is not present in the tree.\n";
    }

    return 0;
}
