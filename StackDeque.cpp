#include<bits/stdc++.h>
#include "DoublyEndedQueue.h"
using namespace std;
class StackWithDeque {
    DoubleEndedQueue deque;
    public :
        StackWithDeque();
        bool isEmpty();
        int top();
        void push(int );
        void pop();
};

StackWithDeque :: StackWithDeque() {

}

bool StackWithDeque :: isEmpty() {
    return deque.isEmpty();
}

int StackWithDeque :: top() {
    return deque.getRear();
}

void StackWithDeque :: push(int data) {
    deque.insertAtEnd(data);
}

void StackWithDeque :: pop() {
    deque.deleteAtRear();
}

int main() {
    StackWithDeque st;
    st.push(5);
    cout<<st.top()<<endl;
    st.push(10);
    cout<<st.top()<<endl;
    cout<<st.isEmpty()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    return 0;
}
