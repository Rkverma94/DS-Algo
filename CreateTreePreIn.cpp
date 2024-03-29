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
class CreateTree {  
    public :
        Node* root;
        CreateTree() {
            root = NULL;
        }
        Node* generateTree(vector<int>, vector<int>, int, int, unordered_map<int, int>);
        //int search(vector<int>, int, int, int);
        void postOrder(Node*);
};

/*int CreateTree :: search(vector<int> inOrder, int startIdx, int endIdx, int data) {
    //This search method is taking O(n) to search.
    //We can remove this by changing search to a hashmap or inorders
    for(int i = startIdx; i <= endIdx; i++) {
        if(inOrder[i] == data) {
            return i;
        }
    }
    return -1;
}*/

Node* CreateTree :: generateTree(vector<int> preOrder, vector<int> inOrder, int inStart, int inEnd, unordered_map<int, int> map) {
    cout<<"---Start----"<<endl;
    static int preIdx = 0;
    //if indices are overlapping or crossing then return null
    if(inStart > inEnd) return NULL;
    cout<<"preOrder value---"<<preOrder[preIdx]<<endl;
    Node* newNode = new Node(preOrder[preIdx++]);
    //if this is leaf node then return it
    if(inStart == inEnd) return newNode;

    int inIdx = map[newNode->data];//search(inOrder, inStart, inEnd, newNode->data);
    cout<<"InOrder Idx found :: "<<inIdx<<endl;
    if(inIdx == -1) return newNode;
    newNode->left = generateTree(preOrder, inOrder, inStart, inIdx - 1, map);
    newNode->right = generateTree(preOrder, inOrder, inIdx + 1, inEnd, map);
    cout<<"------end------"<<endl;
    return newNode;
}

void CreateTree :: postOrder(Node* root) {
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main() {
    vector<int> inOrder = {56, 12, 78, 10, 122, 14, 34};
    vector<int> preOrder = {10, 12, 56, 78, 14, 122, 34};
    CreateTree t;
    unordered_map<int, int> map;
    for(int i=0; i<inOrder.size(); i++) {
        map[inOrder[i]] = i;
    } 
    t.root = t.generateTree(preOrder, inOrder, 0, inOrder.size() - 1, map);
    t.postOrder(t.root);
    return 0;
}