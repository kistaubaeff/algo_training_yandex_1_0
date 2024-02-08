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



    int depthOfNode(Node* root, int key)
    {
        if (root->key == key)
        {
            return 1;
        }

        if (key < root->key)
        {   
            return depthOfNode(root->left, key) + 1;
        }
        else {
            return depthOfNode(root->right, key) + 1;
        }

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

    bool find(int key) {
        return findRec(root, key) != nullptr ? true : false;
    }

    void insert(int key) {
        root = insertRec(root, key);
    }

    void inorderTraversal() {
        inorderRec(root);
    }

    int getDepth(int key)
    {
        return depthOfNode(root, key);
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
        if (bst.find(curr)) {
            std::cin >> curr;
            continue;
            
        }
        bst.insert(curr);
        std::cout << bst.getDepth(curr) << ' ';
        std::cin >> curr;
        
    }
    std::cout << '\n';
    // std::cout << bst.height() << '\n';
}