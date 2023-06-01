#include<bits/stdc++.h>
using namespace std;
//Structure of a trie node
class Node {
    public:
        Node* childNodes[26];
        int wordEndCnt;
        Node();
        
};

Node :: Node() {
    //Initialize the wordEndCnt with 0
    //initialize every index of child node with null
    wordEndCnt = 0;
    for(int i=0; i<26; i++) {
        childNodes[i] = NULL;
    }
}

Node* insertKey(Node*, string);
bool searchKey(Node*, string);

Node* insertKey(Node* root, string key) {
    Node* currentNode = root;
    int length = key.size();
    //iterate over the length of the string
    for(int i=0; i<length; i++) {
        //check X-'a' th index for null
        if(currentNode->childNodes[key[i] - 'a'] == NULL) {
            //make a new trie node
            Node* newNode = new Node();
            //point the currentNode's X-'a'th child to new node
            currentNode->childNodes[key[i] - 'a'] = newNode;
        }
        //move the currentNode pointer to the newly created node
        currentNode = currentNode->childNodes[key[i] - 'a'];
    }
    currentNode->wordEndCnt++;
    return root;
}

bool searchKey(Node* root, string key) {
    Node* currentNode = root;
    int length = key.size();
    for(int i=0; i<length; i++) {
        if(currentNode->childNodes[key[i] - 'a'] == NULL) return false;
        currentNode = currentNode->childNodes[key[i] - 'a'];
    }
    return currentNode != NULL && currentNode->wordEndCnt > 0;
}

int main() {
    Node* root = new Node();
    vector<string> listOfStr;
    string mainText = "banana";
    for(int i=0; i<mainText.size(); i++) {
        int j=i;
        string toInsert;
        while(j < mainText.size()) {
            toInsert.push_back(mainText[j++]);
        }
        listOfStr.push_back(toInsert);
    }
    //Printing the suffix of text
    for(int i=0; i<listOfStr.size(); i++) {
        cout<<"str "<<i+1<<" - "<<listOfStr[i]<<", ";
    }
    cout<<endl;
    for(int i=0; i<listOfStr.size(); i++) {
        root = insertKey(root, listOfStr[i]);    
    }
    cout<<"code is there or not - "<<searchKey(root, "code");
    return 0;
}
