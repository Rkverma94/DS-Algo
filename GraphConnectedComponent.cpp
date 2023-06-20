#include<bits/stdc++.h>
using namespace std;
class GraphConnectedComponents {
public:
    vector<vector<int>> components;
    vector<int> currentComponent;
    void dfs(int node, vector<bool> &visited, vector<list<int>> &g) {
        visited[node] = 1;
        currentComponent.push_back(node);
        for(auto it = g[node].begin(); it != g[node].end(); it++) {
            if(!visited[*it]) {
                dfs(*it, visited, g);
            }
        }
    }
    int countConnectedComponents(int n, vector<vector<int>>& edges) {
        vector<list<int>> g(n);
        vector<bool> visited(n,0);
        int totalComponent = 1;
        for(int i=0; i<edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        currentComponent.clear();
        dfs(0, visited, g);
        components.push_back(currentComponent);
        for(int i=0; i<visited.size(); i++) {
            if(!visited[i]) {
                totalComponent++;
                currentComponent.clear();
                dfs(i, visited, g);
                components.push_back(currentComponent);
            }
        }
        return totalComponent;
    }
};

int main() {
    int vertices = 6;
    vector<vector<int>> edges = {{0,1},{0,2},{1,2},{3,4}};
    GraphConnectedComponents graph;
    cout<<"Connected Components in graph is "<<graph.countConnectedComponents(vertices, edges);
}