#include<bits/stdc++.h>
using namespace std;
class Node {
    public : 
        int data;
        Node* left;
        Node* right;
        Node* parent;
        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
            this->parent = NULL;
        }
};

class BinarySearchTree {
    public :
        Node* root;
        BinarySearchTree() {
            root = NULL;
        }
        Node* insertNode(Node*, int);
        void inOrder(Node*);
};

Node* BinarySearchTree :: insertNode(Node* root, int data) {
    if(root == NULL) {
        Node* newNode = new Node(data);
        return newNode;
    }
    if(data < root->data) {
        Node* newLeftNode = insertNode(root->left, data);
        root->left = newLeftNode;
        newLeftNode->parent = root;
    } else {
        Node* newRightNode = insertNode(root->right, data);
        root->right = newRightNode;
        newRightNode->parent = root;
    }
    return root;
}

void BinarySearchTree :: inOrder(Node* root) {
    if(root == NULL) return;
    inOrder(root->left);
    if(root->parent != NULL) {
        cout<<root->data<<" "<<"-Parent-"<<root->parent->data<<endl;
    } else {
        cout<<root->data<<" "<<"-Parent-"<<root->parent<<endl;
    }
    inOrder(root->right);
}

int main() {
    BinarySearchTree bst;
    bst.root = bst.insertNode(bst.root, 6);
    bst.root = bst.insertNode(bst.root, 3);
    bst.root = bst.insertNode(bst.root, 5);
    bst.root = bst.insertNode(bst.root, 7);
    bst.root = bst.insertNode(bst.root, 11);
    bst.root = bst.insertNode(bst.root, 2);
    bst.root = bst.insertNode(bst.root, 4);
    bst.inOrder(bst.root);
    return 0;
}