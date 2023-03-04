#include<bits/stdc++.h>
using namespace std;
class Node {
    public : 
        int data;
        Node* next;
        Node* prev;
        Node(int data) {
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
};

class DoublyCircularLinkedList {
    Node* head;
    void initializeHeadNode(int);
    public : 
        DoublyCircularLinkedList();
        void insertAtFront(int );
        void insertAtLast(int );
        void insertAtPos(int, int);
        void deleteNode(int );
        Node* searchNode(int );
        void display();
};

DoublyCircularLinkedList :: DoublyCircularLinkedList() {
    head = NULL;
}

void DoublyCircularLinkedList :: initializeHeadNode(int data) {
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = nodeToInsert;
    nodeToInsert->prev = nodeToInsert;
    head = nodeToInsert;
}

void DoublyCircularLinkedList :: insertAtFront(int data) {
    if(head == NULL) {
        return initializeHeadNode(data);
    }
    Node* tempNode = head;
    Node* tempLast = head->prev;
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = tempNode;
    tempNode->prev = nodeToInsert;
    tempLast->next = nodeToInsert;
    nodeToInsert->prev = tempLast;
    head = nodeToInsert;
}

void DoublyCircularLinkedList :: insertAtLast(int data) {
    if(head == NULL) {
        return initializeHeadNode(data);
    }
    Node* nodeToInsert = new Node(data);
    Node* tempNode = head;
    Node* tempLast = head->prev;
    tempLast->next = nodeToInsert;
    nodeToInsert->prev = tempLast;
    tempNode->prev = nodeToInsert;
    nodeToInsert->next = tempNode;
}

void DoublyCircularLinkedList :: insertAtPos(int pos, int data) {
    if(head == NULL) return initializeHeadNode(data);
    if(pos <= 1) return insertAtFront(data);
    Node* tempNode = head;
    while(tempNode->next != head && --pos > 1) {
        tempNode = tempNode->next;
    }
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = tempNode->next;
    tempNode->next->prev = nodeToInsert;
    tempNode->next = nodeToInsert;
    nodeToInsert->prev = tempNode;
}

void DoublyCircularLinkedList :: deleteNode(int data) {
    if(head == NULL) return;
    Node* tempNode = head;
    Node* tempLast = head->prev;
    if(tempNode->data == data) {
        tempLast->next = tempNode->next;
        tempNode->next->prev = tempLast;
        head = tempNode->next;
        Node* nodeToDelete = tempNode;
        nodeToDelete->next = NULL;
        nodeToDelete->prev = NULL;
        delete nodeToDelete;
        return;
    }
    while(tempNode->next != head) {
        if(tempNode->next->data == data) {
            Node* nodeToDelete = tempNode->next;
            tempNode->next = nodeToDelete->next;
            nodeToDelete->next->prev = tempNode;
            nodeToDelete->next = NULL;
            nodeToDelete->prev = NULL;
            delete nodeToDelete;
            return;
        }
        tempNode = tempNode->next;
    }
    cout<<"Node is not found"<<endl;
}

Node* DoublyCircularLinkedList :: searchNode(int data) {
    if(head == NULL) return NULL;
    Node* tempLast = head->prev;
    if(head->data == data) return head;
    if(tempLast->data == data) return tempLast;
    Node* tempNode = head;
    while(tempNode != tempLast) {
        if(tempNode->data == data) return tempNode;
        if(tempLast->data == data) return tempLast;
        tempNode = tempNode->next;
        tempLast = tempLast->prev;
    }
    cout<<"Node is not found"<<endl;
    return NULL;
}

void DoublyCircularLinkedList :: display() {
    Node* tempNode = head;
    Node* tempLast = head->prev;
    while(tempNode->next != tempLast->next) {
        cout<<tempNode->data<<"->";
        tempNode = tempNode->next;
    }
    
    cout<<tempNode->data<<endl;
}

int main() {
    DoublyCircularLinkedList dcll;
    dcll.insertAtFront(12);
    dcll.display();
    dcll.insertAtFront(19);
    dcll.display();
    dcll.insertAtLast(56);
    dcll.display();
    dcll.insertAtPos(3, 23);
    dcll.display();
    dcll.insertAtFront(29);
    dcll.display();
    dcll.insertAtLast(34);
    dcll.display();
    dcll.deleteNode(29);
    dcll.display();
    dcll.deleteNode(23);
    dcll.display();
    Node* seachedNode = dcll.searchNode(19);
    cout<<seachedNode->data<<endl;
    return 0;
}
