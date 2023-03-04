/*Implementation of Queue basic operations by Linked List 
Enqueue
Dequeue
IsEmpty
*/
#include<bits/stdc++.h>
using namespace std;
class Node {
    public :
        int data;
        Node* next;
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

class Queue {
    Node* frontPointer;
    Node* rearPointer;
    public :
        Queue();
        void enqueue(int );
        int dequeue();
        bool isEmpty();
};

Queue :: Queue() {
    frontPointer = NULL;
    rearPointer = NULL;
}

/*Enqueue adds a new element to the rear end of the queue*/
void Queue :: enqueue(int data) {
    //If the rear end is null -> initialize the front and rear pointer to the new node
    if(rearPointer == NULL) {
        Node* nodeToInsert = new Node(data);
        frontPointer = nodeToInsert;
        rearPointer = nodeToInsert;
        return;
    }
    //If elements are there then link rear node's next element to the new element and adjust rear pointer
    Node* nodeToInsert = new Node(data);
    Node* tempNode = rearPointer;
    tempNode->next = nodeToInsert;
    rearPointer = nodeToInsert;
}

int Queue :: dequeue() {
    if(rearPointer == NULL || frontPointer == NULL) {
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    Node* tempNode = frontPointer;
    frontPointer = tempNode->next;
    int data = tempNode->data;
    delete tempNode;
    return data;
}

bool Queue :: isEmpty() {
    return (rearPointer == NULL || frontPointer == NULL);
}

int main() {
    Queue q;
    cout<<q.isEmpty()<<endl;
    q.enqueue(4);
    q.enqueue(5);
    cout<<q.isEmpty()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.isEmpty()<<endl;
}

