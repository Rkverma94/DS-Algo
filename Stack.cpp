#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node* next;
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

class Stack {
    Node* topPointer;
    int length;
    public:
        Stack();
        void push(int );
        void pop();
        int top();
        bool isEmpty();
        int size();
};

Stack :: Stack() {
    topPointer = NULL;
    length = 0;
}

void Stack :: push(int data) {
    if(topPointer == NULL) {
        Node* nodeToInsert = new Node(data);
        topPointer = nodeToInsert;
        length++;
        return;
    }
    Node* tempNode = topPointer;
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = tempNode;
    topPointer = nodeToInsert;
    length++;
}

void Stack :: pop() {
    if(topPointer == NULL) {
        cout<<"Stack is underflow"<<endl;
        return;
    }
    Node* nodeToRemove = topPointer;
    topPointer = nodeToRemove->next;
    delete nodeToRemove;
    length--;
}

int Stack :: top() {
    if(topPointer == NULL) {
        cout<<"Stack is underflow"<<endl;
        return -1;
    }
    return topPointer->data;
}

bool Stack :: isEmpty() {
    return topPointer != NULL;
}

int Stack :: size() {
    return length;
}

int main() {
    Stack stack;
    cout<<stack.isEmpty()<<endl;
    stack.push(3);
    cout<<stack.top()<<endl;
    stack.push(4);
    cout<<stack.top()<<endl;
    stack.pop();
    cout<<stack.top()<<endl;
    cout<<stack.isEmpty()<<endl;
    cout<<stack.size()<<endl;
}