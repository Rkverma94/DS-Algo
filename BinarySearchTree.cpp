#include<bits/stdc++.h>
using namespace std;
//Node structure class
class Node {
    public : 
        //To store data
        int data;
        //Pointer to left Node
        Node* left;
        //Pointer to right Node
        Node* right;
        //Pointer to Parent Node
        Node* parent;
        //Constructor to init a node
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
        //Insert Node in BST
        Node* insertNode(Node*, int);
        //Search a value recursively
        Node* search(Node*, int);
        //Inorder successor in bst
        Node* findSuccessor(Node*, Node*);
        //Inorder predecessor in bst
        Node* findPredecessor(Node*, Node*);
        //Find min in a tree
        Node* findMin(Node*);
        //Find max in a tree
        Node* findMax(Node*);
        //print Inorder traversal
        void inOrder(Node*);
};

Node* BinarySearchTree :: findMax(Node* root) {
    //if root is null return null
    if(root == NULL) return NULL;
    //if right is null then it means it is maximum node
    if(root->right == NULL) return root;
    //find max in right sub tree
    return findMax(root->right);
}

Node* BinarySearchTree :: findMin(Node* root) {
    //if root is null return null
    if(root == NULL) return NULL;
    //if left sub tree does not exists then return current node
    if(root->left == NULL) return root;
    //If left sub tree exists then recursively call findMind with root->left as minimum is the left most element
    return findMin(root->left);
}

Node* BinarySearchTree :: findPredecessor(Node* root, Node* keyNode) {
    /*Inorder Predecessor is the element which comes before the given keyNode
        if root is NULL then return null*/
    if(root == NULL) return NULL;
    /*if left sub tree exists for keynode then find maximum element in the left sub tree
        that element will be the Inorder Predecessor */
    if(keyNode->left != NULL) {
        return findMax(keyNode->left);
    } else {
        /*if left sub tree does not exists for keynode then 
        the parent whose right child is the keynode will be the Inorder Predecessor*/
        Node* parentNode = keyNode->parent;
        //Check if parent is null and traverse up the order till parent left is keynode
        while(parentNode != NULL && parentNode->left == keyNode) {
            keyNode = parentNode;
            parentNode = parentNode->parent;
        }
        return parentNode;
    }
}

Node* BinarySearchTree :: findSuccessor(Node* root, Node* keyNode) {
    //Inorder Successor is the element which comes after the given keynode in inorder traversal
    if(root == NULL) return NULL;
    /*If right sub tree exists for keynode then minimum element in the right sub tree
        It will be the Inorder Successor*/
    if(keyNode->right != NULL) {
        return findMin(keyNode->right);
    } else {
        /*If right sub tree does not exists for keynode then
            the parent whose left child is the keynode will be the Inorder Successor*/
        Node* parentNode = keyNode->parent;
        //Check if parent is NULL and traverse up the order till parent right is keynode
        while(parentNode != NULL && keyNode == parentNode->right) {
            keyNode = parentNode;
            parentNode = parentNode->parent;
        }
        return parentNode;
    }
}

Node* BinarySearchTree :: search(Node* root, int key) {
    //if root is null then return null
    if(root == NULL) return NULL;
    //if key is found then return current node
    if(key == root->data) return root;
    //if key is less then current node then traverse left sub tree
    if(key < root->data) {
        return search(root->left, key);
    } else {
        //otherwise traverse right sub tree
        return search(root->right, key);
    }
}

Node* BinarySearchTree :: insertNode(Node* root, int data) {
    //if null is encountered return new node with data and pointers null
    if(root == NULL) {
        Node* newNode = new Node(data);
        return newNode;
    }
    //if data is less then current node data, traverse it's left subtree and adjust parent pointer
    if(data < root->data) {
        Node* newLeftNode = insertNode(root->left, data);
        root->left = newLeftNode;
        newLeftNode->parent = root;
    } else {
        //otherwise traverse it's right subtree and adjust parent pointer
        Node* newRightNode = insertNode(root->right, data);
        root->right = newRightNode;
        newRightNode->parent = root;
    }
    return root;
}

void BinarySearchTree :: inOrder(Node* root) {
    //Inorder traversal is Left Node, Root Node, Right Node
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
    // clock_t start = clock();
    Node* foundNode = bst.search(bst.root, 4);
    // clock_t end = clock();
    // double elapsed = double(end - start)/CLOCKS_PER_SEC;
    cout<<foundNode->data<<" -parent- "<<foundNode->parent->data<<endl;
    // cout<<"Time taken---"<<elapsed<<endl;
    // cout<<"CLOCKS_PER_SEC---"<<CLOCKS_PER_SEC<<endl;
    Node* successorNode = bst.findSuccessor(bst.root, foundNode);
    if(successorNode != NULL) {
        cout<<"Successor Node is "<<successorNode->data<<endl;
    } else {
        cout<<"Successor Node does not exist. This is the max node."<<endl;
    }
    Node* predecessorNode = bst.findPredecessor(bst.root, foundNode);
    if(predecessorNode != NULL) {
        cout<<"Predecessor Node is "<<predecessorNode->data<<endl;
    } else {
        cout<<"Predecessor Node does not exist. It is the minimum Node."<<endl;
    }
    return 0;
}