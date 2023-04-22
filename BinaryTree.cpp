#include<bits/stdc++.h>
using namespace std;
class Node {
    public : 
        int data;
        Node* parent;
        Node* left;
        Node* right;
        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
            this->parent = NULL;
        }
};
class BinaryTree {
    public :
        Node* root;
        BinaryTree();
        //Insert Node at left
        void insertNodeLeft(int);
        //Insert Node at right
        void insertNodeRight(int);
        //level wise insertion
        void insertNodeLevelWise(int);
        void inorder(Node*);
        void preorder(Node*);
        void postorder(Node*);
        void display();
};

BinaryTree :: BinaryTree() {
    root = NULL;
}

void BinaryTree :: insertNodeLevelWise(int data) {
    if(root == NULL) {
        Node* newNode = new Node(data);
        root = newNode;
        return;
    }
    Node* temp = root;
    queue<Node*> helperQueue;
    helperQueue.push(temp);
    while(!helperQueue.empty()) {
        Node* frontNode = helperQueue.front();
        helperQueue.pop();
        if(frontNode->left != NULL) {
            helperQueue.push(frontNode->left);
        } else {
            Node* newNode = new Node(data);
            frontNode->left = newNode;
            newNode->parent = frontNode;
            return;
        }
        //frontNode right node
        if(frontNode->right != NULL) {
            helperQueue.push(frontNode->right);
        } else {
            Node* newNode = new Node(data);
            frontNode->right = newNode;
            newNode->parent = frontNode;
            return;
        }
    }
}

void BinaryTree :: display() {
    if(root == NULL) {
        cout<<"Tree is empty"<<endl;
        return;
    }
    Node* temp = root;
    queue<Node*> tempQueue;
    tempQueue.push(temp);
    while(!tempQueue.empty()) {
        Node* frontNode = tempQueue.front();
        tempQueue.pop();
        cout<<frontNode->data<<"-parent-"<<frontNode->parent->data<<endl;
        if(frontNode->left != NULL) tempQueue.push(frontNode->left);
        if(frontNode->right != NULL) tempQueue.push(frontNode->right);
    }
}

void BinaryTree :: inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    if(root->parent != NULL) {
        cout<<root->data<<"-parent-"<<root->parent->data<<endl;
    } else {
        cout<<root->data<<"-parent-"<<root->parent<<endl;
    }
    inorder(root->right);
}

void BinaryTree :: preorder(Node* root) {
    if(root == NULL) return;
    if(root->parent != NULL) {
        cout<<root->data<<"-parent-"<<root->parent->data<<endl;
    } else {
        cout<<root->data<<"-parent-"<<root->parent<<endl;
    }
    preorder(root->left);
    preorder(root->right);
}

void BinaryTree :: postorder(Node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    if(root->parent != NULL) {
        cout<<root->data<<"-parent-"<<root->parent->data<<endl;
    } else {
        cout<<root->data<<"-parent-"<<root->parent<<endl;
    }
}

int main() {
    BinaryTree bt;
    bt.insertNodeLevelWise(10);
    bt.insertNodeLevelWise(12);
    bt.insertNodeLevelWise(14);
    bt.insertNodeLevelWise(56);
    bt.insertNodeLevelWise(78);
    bt.insertNodeLevelWise(122);
    bt.insertNodeLevelWise(34);
    //bt.display();
    cout<<"In Order"<<endl;
    bt.inorder(bt.root);
    cout<<"Pre Order"<<endl;
    bt.preorder(bt.root);
    cout<<"Post Order"<<endl;
    bt.postorder(bt.root);
    return 0;
}