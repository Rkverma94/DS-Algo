#include<bits/stdc++.h>
using namespace std;
class DoubleEndedQueue {
    vector<int> arr;
    int front;
    int rear;
    int size;
    public :
        DoubleEndedQueue();
        DoubleEndedQueue(int );
        void insertAtFront(int );
        void insertAtEnd(int );
        void deleteAtFront();
        void deleteAtRear();
        bool isFull();
        bool isEmpty();
        int getFront();
        int getRear();
};

DoubleEndedQueue :: DoubleEndedQueue() {
    front = -1;
    rear = 0;
    size = 10;
    arr.resize(size);
}

DoubleEndedQueue :: DoubleEndedQueue(int newSize) {
    front = -1;
    rear = 0;
    size = newSize;
    arr.resize(size);
}

bool DoubleEndedQueue :: isFull() {
    return ((front == 0 && rear == size-1) || (front == rear+1));
}

bool DoubleEndedQueue :: isEmpty() {
    return (front == -1);
}

void DoubleEndedQueue :: insertAtFront(int data) {
    if(isFull()) {
        cout<<"Overflow"<<endl;
        return;
    }
    if(front == -1) {
        front = 0;
        rear = 0;
    } else if(front == 0) {
        front = size - 1;
    } else {
        front--;
    }
    arr[front] = data;
}

void DoubleEndedQueue :: insertAtEnd(int data) {
    if(isFull()) {
        cout<<"Overflow"<<endl;
        return;
    }
    if(rear == -1) {
        front = 0;
        rear = 0;
    } else if(rear == size - 1) {
        rear = 0;
    } else {
        rear++;
    }
    arr[rear] = data;
}

void DoubleEndedQueue :: deleteAtFront() {
    if(isEmpty()) {
        cout<<"Underflow"<<endl;
        return;
    }
    if(front == rear) {
        front = -1;
        rear = -1;
    } else if(front == size - 1) {
        front = 0;
    } else {
        front++;
    }
}

void DoubleEndedQueue :: deleteAtRear() {
    if(isEmpty()) {
        cout<<"Underflow"<<endl;
        return;
    }
    if(front == rear) {
        front = -1;
        rear = -1;
    } else if(rear == 0) {
        rear = size - 1;
    } else {
        rear--;
    }
}

int DoubleEndedQueue :: getFront() {
    if(isEmpty()) {
        cout<<"Underflow"<<endl;
        return -1;
    }
    return arr[front];
}

int DoubleEndedQueue :: getRear() {
    if(isEmpty() || rear < 0) {
        cout<<"Underflow"<<endl;
        return -1;
    }
    return arr[rear];
}

int main() {
    DoubleEndedQueue dq(4);
    dq.insertAtFront(5);
    cout<<dq.getFront()<<endl;
    dq.insertAtFront(8);
    cout<<dq.getFront()<<endl;
    dq.insertAtEnd(11);
    cout<<dq.getRear()<<endl;
    dq.insertAtEnd(10);
    cout<<dq.getRear()<<endl;
    dq.insertAtEnd(7);//Account to overflow exception
    dq.deleteAtFront();
    cout<<dq.getFront()<<endl;
    return 0;
}