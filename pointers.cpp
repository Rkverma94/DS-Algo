#include<bits/stdc++.h>
using namespace std;
int main() {
    int a = 10;
    int *p = &a;
    int **t = &p;
    cout<<"*p = "<<*p<<endl;
    cout<<"&p = "<<&p<<endl;
    cout<<"&a = "<<&a<<endl;
    cout<<"p = "<<p<<endl;
    cout<<"*t = "<<*t<<endl;
    cout<<"**t = "<<**t<<endl;
    return 0;
}