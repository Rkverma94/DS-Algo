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

class CircularLinkedList {
    //Pointer to point the last node
    Node* last;
    public:
        CircularLinkedList();
        void insertAtFront(int);
        void insertAtEnd(int);
        void insertAtPos(int, int);
        void display();
        void initializeLastNode(Node*);
        void deleteNode(int);
};

CircularLinkedList :: CircularLinkedList() {
    last = NULL;
}

void CircularLinkedList :: initializeLastNode(Node* nodeToInsert) {
    last = nodeToInsert;
    nodeToInsert->next = nodeToInsert;
    return;
}

void CircularLinkedList :: deleteNode(int data) {
    if(last == NULL) return;
    Node* tempNode = last->next;
    if(tempNode->data == data) {
        last->next = tempNode->next;
        tempNode->next = NULL;
        delete tempNode;
        return;
    }
    while(tempNode != last) {
        if(tempNode->next->data == data) {
            Node* nodeToDelete = tempNode->next;
            tempNode->next = tempNode->next->next;
            nodeToDelete->next = NULL;
            delete nodeToDelete;
            return;
        }
        tempNode = tempNode->next;
    }
    cout<<"node is not found"<<endl;
}

void CircularLinkedList :: insertAtPos(int pos, int data) {
    //New Node to insert
    Node* nodeToInsert = new Node(data);
    if(last == NULL) {
        return initializeLastNode(nodeToInsert);
    }
    //If pos is less equals to 1
    if(pos <= 1) {
        return insertAtFront(data);
    }
    //check for other positions and size of list simultaneously
    Node* tempNode = last->next;
    while(tempNode != last && --pos > 1) {
        tempNode = tempNode->next;
    }
    nodeToInsert->next = tempNode->next;
    tempNode->next = nodeToInsert;
}

void CircularLinkedList :: insertAtEnd(int data) {
    //New Node to insert
    Node* nodeToInsert = new Node(data);
    //Check if List is empty
    if(last == NULL) {
        return initializeLastNode(nodeToInsert);
    }
    //insert at the end
    //initialize tempFristNode  as last.next
    //link new node to last and make new node as last
    Node* tempFirstNode = last->next;
    last->next = nodeToInsert;
    nodeToInsert->next = tempFirstNode;
    last = nodeToInsert;
}

void CircularLinkedList :: insertAtFront(int data) {
    //New node to insert
    Node* nodeToInsert = new Node(data);
    //If last node is NULL
    //keep last pointer to new node inserted
    if(last == NULL) { 
        return initializeLastNode(nodeToInsert);
    }
    Node* tempNode = last->next;
    nodeToInsert->next = tempNode;
    last->next = nodeToInsert;
}

void CircularLinkedList :: display() {
    if(last == NULL) {
        cout<<"list is empty"<<endl;
    }
    Node* tempNode = last->next;
    do {
        cout<<tempNode->data<<"->";
        tempNode = tempNode->next;
    } while(tempNode != last->next);
    cout<<endl;
}


int main() {
    CircularLinkedList cll; 
    cll.insertAtFront(4);
    cll.display();
    cll.insertAtFront(19);
    cll.display();
    cll.insertAtFront(5);
    cll.display();
    cll.insertAtEnd(10);
    cll.display();
    cll.insertAtFront(12);
    cll.display();
    cll.insertAtPos(2, 20);
    cll.display();
    cll.deleteNode(5);
    cll.display();
    cll.deleteNode(3);
    cll.display();
    return 0;
}