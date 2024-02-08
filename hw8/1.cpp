#include <iostream>

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int data) {
        key = data;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* findRec(Node* root, int key) {
        if (root == nullptr || root->key == key) {
            return root;
        }

        if (key < root->key) {
            return findRec(root->left, key);
        }

        return findRec(root->right, key);
    }

    Node* insertRec(Node* root, int key) {
        if (findRec(root, key)){
            return root;
        }
        if (root == nullptr) {
            return new Node(key);
        }

        if (key < root->key) {
            root->left = insertRec(root->left, key);
        } else if (key > root->key) {
            root->right = insertRec(root->right, key);
        }

        return root;
    }

    void inorderRec(Node* root) {
        if (root != nullptr) {
            inorderRec(root->left);
            std::cout << root->key << " ";
            inorderRec(root->right);
        }
    }

    int heightRec(Node* root)
    {
        if (!root) return 0;
        int left_h = heightRec(root->left);
        int right_h = heightRec(root->right);
        return std::max(left_h, right_h) + 1;
    }

    void deleteTree(Node* root)
    {
        if (root)
        {
            deleteTree(root->left);
            deleteTree(root->right);
            delete root;
        }
    }

    


public:
    BST() {
        root = nullptr;
    }

    int height()
    {
        return heightRec(root);
    }

    Node* find(int key) {
        return findRec(root, key);
    }

    void insert(int key) {
        root = insertRec(root, key);
    }

    void inorderTraversal() {
        inorderRec(root);
    }
    ~BST()
    {
        deleteTree(root);
    }

};

int main() {
    BST bst;
    int curr;
    std::cin >> curr;
    while(curr != 0)
    {
        bst.insert(curr);
        std::cin >> curr;
    }
    std::cout << bst.height() << '\n';
}