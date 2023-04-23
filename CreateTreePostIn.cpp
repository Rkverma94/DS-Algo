#include<bits/stdc++.h>
using namespace std;
class Node {
    public : 
        int data;
        Node* left;
        Node* right;
        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

class CreateTreePostIn {
    public :
        Node* root;
        CreateTreePostIn() {
            root = NULL;
        }
        Node* generateTree(vector<int>, vector<int>, int, int);
        int search(vector<int>, int, int, int);
        void preOrder(Node*);
};

int CreateTreePostIn :: search(vector<int> inOrder, int startIdx, int endIdx, int key) {
    for(int i = startIdx; i <= endIdx; i++) {
        if(inOrder[i] == key) return i;
    }
    return -1;
}

Node* CreateTreePostIn :: generateTree(vector<int> inOrder, vector<int> postOrder, int inStart, int inEnd) {
    if(inStart > inEnd) return NULL;
    static int postIdx = postOrder.size() - 1;
    Node* newNode = new Node(postOrder[postIdx]);
    postIdx--;
    if(inStart == inEnd) return newNode;
    int inIdx = search(inOrder, inStart, inEnd, newNode->data);
    if(inIdx == -1) return newNode;
    newNode->right = generateTree(inOrder, postOrder, inIdx+1, inEnd);
    newNode->left = generateTree(inOrder, postOrder, inStart, inIdx - 1);
    return newNode;
}

void CreateTreePostIn :: preOrder(Node* root) {
    if(root == NULL) return;
    cout<<root->data<<endl;
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    vector<int> inOrder = {56, 12, 78, 10, 122, 14, 34};
    vector<int> postOrder = {56, 78, 12, 122, 34, 14, 10};
    CreateTreePostIn t;
    t.root = t.generateTree(inOrder, postOrder, 0, inOrder.size() - 1);
    t.preOrder(t.root);
    return 0;
}