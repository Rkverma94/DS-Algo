#include<bits/stdc++.h>
using namespace std;
class CompleteGraph {
    private:
    public:
        vector<list<int>> g;
         vector<bool> visited;
        CompleteGraph(int vertices, vector<vector<int>> edges) {
            g.resize(vertices);
            visited.resize(vertices);
            for(int i=0; i<edges.size(); i++) {
                int a = edges[i][0];
                int b = edges[i][1];
                g[a].push_back(b);
                g[b].push_back(a);
            }
        }
        bool completeGraph(vector<list<int>>);
        void dfs(int, vector<list<int>>&, vector<bool>&, int&, int&);
};
void CompleteGraph :: dfs(int node, vector<list<int>> &g, vector<bool> &visited, int &vcc, int &ecc) {
    visited[node] = 1;
    vcc++;
    ecc += g[node].size();
    cout<<"ecc at node "<<node<<" is : "<<ecc<<endl;
    list<int> :: iterator it;
    for(it = g[node].begin(); it != g[node].end(); it++) {
        if(!visited[*it]) {
            dfs(*it, g, visited, vcc, ecc);
        }
    }
}

bool CompleteGraph :: completeGraph(vector<list<int>> g) {
    for(int i=0; i<g.size(); i++) {
        if(!visited[i]) {
            int vcc = 0, ecc = 0;
            dfs(i, g, visited, vcc, ecc);
            return (ecc == vcc*(vcc-1));
        }
    }
    return false;
}

int main() {
    int vertices = 3;
    vector<vector<int>> edges = {{0,1},{0,2},{1,2}};
    CompleteGraph graph(vertices, edges);
    cout<<"Graph is complete or not : "<<graph.completeGraph(graph.g)<<endl;
    return 0;
}