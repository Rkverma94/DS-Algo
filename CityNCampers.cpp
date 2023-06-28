#include<bits/stdc++.h>
using namespace std;
class CityNCampers {
    private : 
        vector<int> parent;
        vector<int> sizes;
        
    public :
        multiset<int> sizeMulti;
        CityNCampers(int size) {
            parent.resize(size);
            sizes.resize(size);
        }
        void make(int );
        int find(int );
        void Union(int, int);
        void merge(int, int);

};

void CityNCampers :: make(int a) {
    parent[a] = a;
    sizes[a] = 1;
    sizeMulti.insert(1);
}

int CityNCampers :: find(int a) {
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void CityNCampers :: merge(int a, int b) {
    vector<int> :: iterator sizeIt = sizes.begin();
    sizeMulti.erase(*std::find(sizes.begin(), sizes.end(), sizes[a]));
    sizeMulti.erase(*std::find(sizes.begin(), sizes.end(), sizes[b]));

    sizeMulti.insert(sizes[a] + sizes[b]);
}

void CityNCampers :: Union(int a, int b) {
    a = find(a);
    b = find(b);
    if(a != b) {
        if(sizes[a] < sizes[b]) {
            swap(a, b);
        }
        parent[b] = a;
        merge(a,b);
        sizes[a] += sizes[b];
    }
}

int main() {
    int n,q;
    cin>>n>>q;
    CityNCampers cc(n);
    while(q--) {
        int i,j;
        cin>>i>>j;
        cc.make(i);
        cc.make(j);
        cc.Union(cc.find(i), cc.find(j));
        if(cc.sizeMulti.size() == 1) cout<<0<<endl;
        else {
            cout<<*(--cc.sizeMulti.end()) - *(cc.sizeMulti.begin())<<endl;
        }
    }
    return 0;
}