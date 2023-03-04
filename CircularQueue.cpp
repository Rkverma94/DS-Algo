#include<bits/stdc++.h>
using namespace std;
class CircularQueue {
    private :
        vector<int> v;
        int front;
        int rear;
        int size;
        static const int DEFAULT_SIZE = 5;
        int getSize();
    public :
        CircularQueue();
        CircularQueue(int );
        void enqueue(int );
        int dequeue();
        void displayCQ();
};

CircularQueue :: CircularQueue() {
    front = -1;
    rear = -1;
    size = DEFAULT_SIZE;
    v.resize(size);
}

CircularQueue :: CircularQueue(int size) {
    front = -1;
    rear = -1;
    size = size;
    v.resize(size);
}

int CircularQueue :: getSize() {
    return v.size();
}

void CircularQueue :: enqueue(int data) {
    if(rear == -1) {
        front = rear = 0;
        v[rear] = data;
        return;
    }
    if((rear == size-1 && front == 0) || (rear == front-1)) {
        cout<<"Queue is full"<<endl;
        return;
    }
    if(rear == size-1 && front != 0) {
        rear = 0;
        v[rear] = data;
        cout<<"rear is :"<<rear<<endl;
        return;
    }
    rear++;
    v[rear] = data;
    cout<<"rear is :"<<rear<<endl;
}

int CircularQueue :: dequeue() {
    if(front == -1) {
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    int data = v[front];
    v[front] = -1;
    if(front == rear) {
        front = -1;
        rear = -1;
    } else if(front == size-1) {
        front = 0;
    } else {
        front++;
    }
    return data;
}

void CircularQueue :: displayCQ() {
    if(front == -1) {
        cout<<"Queue is empty"<<endl;
        return;
    }
    if(rear >= front) {
        for(int i = front; i <= rear; i++) {
            cout<<v[i]<<" ";
        }
    } else {
        for(int i = front; i < size; i++) {
            cout<<v[i]<<" ";
        }

        for(int i = 0; i <= rear; i++) {
            cout<<v[i]<<" ";
        } 
    }
}

int main() {
    CircularQueue cq(6);
    cq.enqueue(56);
    cq.enqueue(4);
    cq.enqueue(6);
    cq.enqueue(26);
    cq.dequeue();
    cq.enqueue(12);
    cq.enqueue(78);
    cq.enqueue(88);
    cq.displayCQ();
    cout<<cq.dequeue()<<endl;
    cq.displayCQ();
    cout<<cq.dequeue()<<endl;
    cout<<cq.dequeue()<<endl;
    cout<<cq.dequeue()<<endl;
    cq.displayCQ();
    cout<<endl;
    cq.enqueue(66);
    cq.displayCQ();
    return 0;
}  