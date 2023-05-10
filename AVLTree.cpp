#include<bits/stdc++.h>
using namespace std;
class Node {
    public : 
        int data;
        Node* left;
        Node* right;
        int height;
        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
            this->height = 0;
        }
};

class AVL {
    public :
        Node* root;
        AVL() {
            root = NULL;
        }
        int getHeight(Node*);
        int getBalanceFactor(Node*);
        Node* LLRotation(Node*);
        Node* RRRotation(Node*);
        void preOrder(Node*);
        Node* insert(Node*, int);
        Node* deleteNode(Node*, int);
        Node* deleteNode(Node*, Node*);
        Node* findMin(Node*);
        Node* findMax(Node*);
        Node* search(Node*, int);
        Node* findSuccessor(Node*, int);
};

int AVL :: getHeight(Node* root) {
    if(root == NULL) return -1;
    return root->height;
}

int AVL :: getBalanceFactor(Node* root) {
    if(root == NULL) return 0;
    return (getHeight(root->left) - getHeight(root->right));
}

/*Insertion is in Left of Left so rotation would be clockwise*/
Node* AVL :: LLRotation(Node* root) {
    cout<<"IN LL Rotation for "<<root->data<<", "<<root->left->data<<endl;
    //make left child of root as new root and adjust left and right child appropriately
    Node* rootLeftChild = root->left;
    root->left = rootLeftChild->right;
    rootLeftChild->right = root;
    //Update new height of root and rootLeftChild
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    rootLeftChild->height = max(getHeight(rootLeftChild->left), getHeight(rootLeftChild->right)) + 1;
    //return new root
    return rootLeftChild;
}

Node* AVL :: RRRotation(Node* root) {
    cout<<"IN RR Rotation for "<<root->data<<", "<<root->right->data<<endl;
    //make right child of root as new root and adjust left and right child appropriately
    Node* rootRightChild = root->right;
    root->right = rootRightChild->left;
    rootRightChild->left = root;
    //Update new height of root and rootRightChild
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    rootRightChild->height = max(getHeight(rootRightChild->left), getHeight(rootRightChild->right)) + 1;
    //return new root
    return rootRightChild;
}

Node* AVL :: search(Node* root, int data) {
    if(root == NULL) return NULL;
    if(data < root->data) return search(root->left, data);
    else if(data > root->data) return search(root->right, data);
    return root;
}

Node* AVL :: findMax(Node* root) {
    if(root == NULL) return NULL;
    if(root->right == NULL) return root;
    return findMax(root->right);
}

Node* AVL :: findMin(Node* root) {
    if(root == NULL) return NULL;
    if(root->left == NULL) return root;
    return findMin(root->left);
}

void AVL :: preOrder(Node* root) {
    if(root == NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

Node* AVL :: insert(Node* root, int data) {
    if(root == NULL) {
        root = new Node(data);
        cout<<root->data<<endl;
        return root;
    }
    //insertion logic as per BST
    if(root->data < data) {
        root->right = insert(root->right, data);
    } else {
        root->left = insert(root->left, data);
    }
    //Balance Factor Check
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int balanceFactor = getBalanceFactor(root);
    //Check if node insertion resulting in left heavy or right heavy tree
    if(balanceFactor > 1) {
        //LL Rotation case clockwise rotation
        if(getBalanceFactor(root->left) == 1) {
            root = LLRotation(root);
        } else {
            //LR Rotation Case
            root->left = RRRotation(root->left);
            root = LLRotation(root);
        }
    } else if(balanceFactor < -1) {
        //RR Rotation case i.e. Anticlockwise rotation
        if(getBalanceFactor(root->right) == -1) {
            root = RRRotation(root);
        } else {
            //RL Rotation
            root->right = LLRotation(root->right);
            root = RRRotation(root);
        }
    }
    return root;
}

Node* AVL :: findSuccessor(Node* root, int data) {
    //if root is null return null
    if(root == NULL) return NULL;
    //search for data in tree
    Node* keyNode = search(root, data);
    //if node has right tree then find the mininum in right tree
    if(keyNode->right != NULL) return findMin(keyNode->right);
    //else right tree does not exists then create a node with null
    Node* succ = NULL;
    //start from root and check if the keynode lies in left tree. It it is then make root as succ
    while(root->data != keyNode->data) {
        if(keyNode->data < root->data) {
            succ = root;
            root=root->left;
        } else {
            root=root->right;
        }
    }
    return succ;
}

Node* AVL :: deleteNode(Node* root, int data) {
    if(root == NULL) return NULL;
    if(data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if(data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        //if node has no child
        if(root->left == NULL && root->right == NULL) {
            return NULL;
        } else if(root->left == NULL) {
            //if only root subtree exists
            Node* temp = root->right;
            delete root;
            return temp;
        } else if(root->right == NULL) {
            //if onyl left subtree exists
            Node* temp = root->left;
            delete root;
            return temp;
        } 
        //Node with two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    //balance factor check
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int balanceFactor = getBalanceFactor(root);
    if(balanceFactor > 1) {
        //LL Rotation case clockwise rotation
        if(getBalanceFactor(root->left) == 1) {
            root = LLRotation(root);
        } else {
            //LR Rotation Case
            root->left = RRRotation(root->left);
            root = LLRotation(root);
        }
    } else if(balanceFactor < -1) {
        //RR Rotation case i.e. Anticlockwise rotation
        if(getBalanceFactor(root->right) == -1) {
            root = RRRotation(root);
        } else {
            //RL Rotation
            root->right = LLRotation(root->right);
            root = RRRotation(root);
        }
    }
    return root;
}



int main() {
    AVL avlTree;
    avlTree.root = avlTree.insert(avlTree.root, 41);
    avlTree.root = avlTree.insert(avlTree.root, 17);
    avlTree.root = avlTree.insert(avlTree.root, 32);
    avlTree.root = avlTree.insert(avlTree.root, 78);
    avlTree.root = avlTree.insert(avlTree.root, 50);
    avlTree.root = avlTree.insert(avlTree.root, 48);
    avlTree.root = avlTree.insert(avlTree.root, 88);
    avlTree.root = avlTree.insert(avlTree.root, 62);
    avlTree.root = avlTree.insert(avlTree.root, 64);
    avlTree.preOrder(avlTree.root);cout<<endl;
    avlTree.root = avlTree.deleteNode(avlTree.root, 50);
    avlTree.preOrder(avlTree.root);
    return 0;
}



