#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node* next;

        //Default constructor
        Node() {
            data = 0;
            next = NULL;
        }

        //parameterized constructor
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

class LinkedList {
    Node* head;
    public:
        //default constructor
        LinkedList() {
            head = NULL;
        }

        void insertNode(int);
        void insertAtPosition(int, int);
        void display();
        void deleteNode(int);
        //void deleteNodes(vector<int>);
        void reverse();
};

void LinkedList :: reverse() {
    //Create a temp node to store the head
    Node* curr = head;
    Node* next = head;
    Node* prev = NULL;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void LinkedList :: insertAtPosition(int data, int pos) {
    //Create a temp node to traverse till pos
    Node* nodeToInsert = new Node(data);
    //make a pointer for head
    Node* tempNode = head;
    //check if position is 1 or below this to insert it at the head
    if(pos <= 1) {
        nodeToInsert->next = tempNode;
        head = nodeToInsert;
        return;
    }
    //check for position to insert at position or at the end
    while(--pos > 1) {
        //go till the node-1 so that at next node we can insert the new node
        tempNode = tempNode->next;
    }
    //for insert at position we have to make new node next pointer to tempNode's next pointer
    nodeToInsert->next = tempNode->next;
    //and then tempnode's next shoul point to new node
    tempNode->next = nodeToInsert;
}

void LinkedList :: insertNode(int data) {
    //Create a new node
    Node* newNode = new Node(data);

    //Assign this new node to head;
    if(head == NULL) {
        head = newNode;
        return;
    }

    //Traverse till end of the list
    Node* tempNode = head;
    while(tempNode->next != NULL) {
        tempNode = tempNode->next;
    }
    //Insert at the end of the list
    tempNode->next = newNode;
}

void LinkedList :: deleteNode(int data) {
    //create a temp node and assign it to
    Node* temp = head;
    if(head->data == data) {
        temp = head;
        head = head->next;
        delete(temp);
        return;
    }

    while(temp->next != NULL) {
        if(temp->next->data == data) {
            Node* nodeTobeDeleted = temp->next;
            temp->next = temp->next->next;
            nodeTobeDeleted->next = NULL;
            delete(nodeTobeDeleted);
            return;      
        }
        temp = temp->next;
    }
}

/*
void LinkedList :: deleteNodes(vector<int> itemsToDelete) {
    //Loop through vector and delete each element if it exists in the linkedlist
    Node* tempHead = head;
    vector<Node*> nodesTobeDeleted;
    while(find(itemsToDelete.begin(), itemsToDelete.end(), tempHead->data) != itemsToDelete.end()) {
        tempHead = head;
        head = head->next;
        nodesTobeDeleted.push_back(tempHead);
        tempHead = head;
        cout<<tempHead->data<<endl;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        if(find(itemsToDelete.begin(), itemsToDelete.end(), temp->next->data) != itemsToDelete.end()) {
            cout<<"in while loop : "<<temp->next->next<<endl;
            Node* nodeTobeDeleted = temp->next;
            if(temp->next->next == NULL) {
                temp->next = NULL;
            } else {
                temp->next = temp->next->next;
            }
            nodeTobeDeleted->next = NULL;
            delete(nodeTobeDeleted);
            
        }
        temp = temp->next;
    }
}*/

void LinkedList :: display() {
    Node* temp = head;
    if(head == NULL) {
        cout<<"List is empty"<<endl;
        return;
    }
    while(temp != NULL) {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    LinkedList list;
    list.display();
    list.insertNode(2);
    list.insertNode(11);
    list.insertNode(45);
    list.insertNode(34);
    list.display();
    list.insertAtPosition(13,1); 
    list.display();
    list.insertAtPosition(15,6);
    list.display();
    list.insertAtPosition(25,4);
    list.display();
    list.deleteNode(15);
    list.display();
    // list.deleteNodes(vector<int> {11,34,13});
    // list.display();
    list.reverse();
    list.display();
    return 0;
    
}