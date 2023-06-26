/**
 * This is the simplest implementation of disjoint set using array of parent.
 * It only works when node data is given in continuous form.
 * 
*/
#include<bits/stdc++.h>
using namespace std;
class DisjointSet {
    private :
        vector<int> parent;
    public : 
        DisjointSet(int size) {
            parent.resize(size);
        }
        void makeSet(int);
        int find(int);
        void Union(int, int);
};

void DisjointSet :: makeSet(int setEle) {
    parent[setEle] = setEle;
}

int DisjointSet :: find(int setEle) {
    if(setEle == parent[setEle]) return setEle;
    return find(parent[setEle]);
}

void DisjointSet :: Union(int a, int b) {
    a = parent[a];
    b = parent[b];
    parent[a] = b;
}

int main() {
    DisjointSet s(8);
    s.makeSet(0);
    s.makeSet(1);
    s.makeSet(2);
    s.makeSet(3);
    s.makeSet(4);
    s.makeSet(5);
    s.makeSet(6);
    s.makeSet(7);
    s.makeSet(8);
    s.Union(s.find(4), s.find(5));
    cout<<"4 and 5 belong to same set or not "<<endl;
    if(s.find(4) == s.find(5)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}