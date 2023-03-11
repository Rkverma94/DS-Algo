#include<bits/stdc++.h>
#include "Stack.h"
using namespace std;
class QueueImpStack : Stack{
    Stack st;
    Stack helperStack;
    public:
        QueueImpStack();
        void enqueue(int );
        int dequeue();
};

QueueImpStack :: QueueImpStack() {

}

void QueueImpStack :: enqueue(int data) {
    //cout<<st.isEmpty()<<endl;
    while(!st.isEmpty()) {
        helperStack.push(st.top());
        st.pop();
    }
    if(st.isEmpty()) st.push(data);
    while(!helperStack.isEmpty()) {
        st.push(helperStack.top());
        helperStack.pop();
    }
}

int QueueImpStack :: dequeue() {
    if(st.isEmpty()) {
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    int returnData = st.top();
    st.pop();
    return returnData;
}

int main() {
    QueueImpStack q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    return 0;
}