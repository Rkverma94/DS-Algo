/**
 * We are given no of empires and no of takeovers, followed by pair of i,j where empire i invaded j
 * and tookover j. Return the number of empires that we have currently.
*/
#include<bits/stdc++.h>
using namespace std;
class DisjointSet {
    private:
        vector<int> parent;
        vector<int> sizeArr;
    public:
        DisjointSet(int size) {
            parent.resize(size+1);
            sizeArr.resize(size+1);
        }
        void make(int );
        int find(int );
        void Union(int, int);
        int countEmpires();
};

void DisjointSet :: make(int a) {
    parent[a] = a;
    sizeArr[a] = 1;
}

int DisjointSet :: find(int a) {
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void DisjointSet :: Union(int a, int b) {
    a = find(a);
    b = find(b);
    if(a != b) {
        if(sizeArr[a] > sizeArr[b]) {
            swap(a, b);
        }
        parent[a] = b;
        sizeArr[a] += sizeArr[b];
    }
}

int DisjointSet :: countEmpires() {
    int count = 0;
    for(int i=1; i<=parent.size(); i++) {
        if(parent[i] == i) count++;
    }
    return count;
}

int main() {
    int n, takeovers;
    cout<<"Enter the number of empires : "<<endl;
    cin>>n;
    cout<<"Enter the no of takeovers done : "<<endl;
    cin>>takeovers;
    DisjointSet ds(n);
    for(int i=1; i<=n; i++) {
        ds.make(i);
    }
    while(takeovers--) {
        int i,j;
        cout<<"Enter the empire which did takeover to another empires ex: 1 2"<<endl;
        cin>>i>>j;
        ds.Union(ds.find(i), ds.find(j));
    }
    int newEmpiresCount = ds.countEmpires();
    cout<<"New Empires after all invasion : "<<newEmpiresCount<<endl;
    return 0;
}