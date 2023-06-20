#include<bits/stdc++.h>
using namespace std;
class GraphDetectCycle {
    private :
    public :
        vector<list<int>> g;
        vector<bool> visited;
        vector<int> parent;
        GraphDetectCycle(int vertices, vector<vector<int>> edges) {
            g.resize(vertices);
            parent.resize(vertices);
            for(int i=0; i<edges.size(); i++) {
                int a = edges[i][0];
                int b = edges[i][1];
                g[a].push_back(b);
                g[b].push_back(a);
            }
            visited.resize(vertices, false);
        }
        bool detectCycle(int, int);
};
bool GraphDetectCycle :: detectCycle(int node, int parent) {
    visited[node] = true;
    /**
     * If child of node is not visited then visit them and find cycle in them
     * Else if child of current node is visited and that child is not equal to parent
     * it means we are coming to child which is already visited by some other node and 
     * we are not trying to traverse it by using backtracking 
    */
    for(auto it = g[node].begin(); it != g[node].end(); it++) {
        if(!visited[*it]) return detectCycle(*it, node);
        else if(visited[*it] && *it != parent) return true;
    }
    return false;
}

int main() {
    int vertices = 5;
    vector<vector<int>> edges = {{1,0}, {0,4}, {1,2}, {1,3}, {2,4}};
    GraphDetectCycle graph(vertices, edges);
    graph.parent[0] = -1;
    cout<<graph.detectCycle(0,-1);
    return 0;
}