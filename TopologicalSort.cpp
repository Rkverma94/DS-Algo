#include<bits/stdc++.h>
using namespace std;
class GraphTopoSort {
    private :
        vector<list<int>> g;
    public :
        vector<bool> visited;
        GraphTopoSort(int vertices, vector<vector<int>> edges) {
            g.resize(vertices);
            visited.resize(vertices, 0);
            for(int i=0; i<edges.size(); i++) {
                int a = edges[i][0];
                int b = edges[i][1];
                g[b].push_back(a);
            }
        }
        void topoSort();
        void dfs(int , stack<int> &);
};
void GraphTopoSort :: dfs(int node, stack<int> &st) {
    visited[node] = 1;
    for(auto it = g[node].begin(); it != g[node].end(); it++) {
        if(!visited[*it]) dfs(*it, st);
    }
    st.push(node);
}
void GraphTopoSort :: topoSort() {
    stack<int> st;
    for(int i=0; i<g.size(); i++) {
        if(!visited[i]) 
            dfs(i, st);
    }
    while(!st.empty()) {
        cout<<st.top()<<endl;
        st.pop();
    }
}

int main() {
    int vertices = 5;
    vector<vector<int>> edges = {{1,0}, {3,1}, {3,2}, {4,3}, {4,2}};
    GraphTopoSort graph(vertices, edges);
    graph.topoSort();
    return 0;
}