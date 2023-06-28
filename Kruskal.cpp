#include<bits/stdc++.h>
using namespace std;
class KruskalAlgo {
    vector<int> parent;
    vector<int> sizes;
    public : 
        vector<list<int>> mstPath;
        KruskalAlgo(int size) {
            parent.resize(size);
            sizes.resize(size);
            mstPath.resize(size);
        }
        void make(int a) {
            parent[a] = a;
            sizes[a] = 1;
        }
        int find(int a) {
            if(a == parent[a]) return a;
            return parent[a] = find(parent[a]);
        }
        void Union(int a, int b) {
            a = find(a);
            b = find(b);
            if(a != b) {
                if(sizes[a] < sizes[b]) {
                    swap(a,b);
                }
                parent[b] = a;
                sizes[a] += sizes[b];
            }
        }
        static bool compare(vector<int> r1, vector<int> r2) {
            if(r1[2] < r2[2]) return true;
            return false;
        }
        void mst(vector<vector<int>> edges) {
            for(int i=0; i<edges.size(); i++) make(i);
            sort(edges.begin(), edges.end(), compare);
            for(int i=0; i<edges.size(); i++) {
                cout<<edges[i][0]<<" - "<<edges[i][1]<<" with weight "<<edges[i][2]<<endl;
            }
            for(int i=0; i<edges.size(); i++) {
                cout<<"in dsu "<<endl;
                if(find(edges[i][0]) != find(edges[i][1])) {
                    cout<<"taking edges "<<edges[i][0]<<" and "<<edges[i][1]<<endl;
                    Union(find(edges[i][0]), find(edges[i][1]));
                    mstPath[edges[i][0]].push_back(edges[i][1]);
                }
            }
        }
};

int main() {
    int vertices = 6;
    vector<vector<int>> edges = {{0,1,2}, {1,2,3}, {2,3,5}, {3,4,9}, {3,0,1}, {0,4,4}, {1,3,3}, {1,5,6}, {5,2,7}};
    KruskalAlgo ka(vertices);
    ka.mst(edges);
    for(int i = 0; i<ka.mstPath.size(); i++) {
        cout<<"Path from "<<i<<" to ";
        for(auto it = ka.mstPath[i].begin(); it != ka.mstPath[i].end(); it++) {
            cout<<*it<<"->";
        }
        cout<<endl;
    }
    return 0;
}