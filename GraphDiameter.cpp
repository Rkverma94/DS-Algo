#include<bits/stdc++.h>
using namespace std;
class GraphDiameter {
    private:
        vector<list<int>> g;
        vector<bool> visited;
        vector<int> path;
        int maxDepth;
    public:
        GraphDiameter(int vertices, vector<vector<int>> edges) {
            cout<<"object initialized and data is being created"<<endl;
            g.resize(vertices);
            maxDepth = 0;
            visited.resize(vertices,0);
            for(int i=0; i<edges.size(); i++) {
                int a = edges[i][0];
                int b = edges[i][1];
                g[a].push_back(b);
                g[b].push_back(a);
            }
            cout<<"data is created"<<endl;
        }
        int getDiameter();
        void dfs(int, vector<bool>&, int, int&, vector<int>&);
};
void GraphDiameter :: dfs(int node, vector<bool> &visited, int depth, int &farthestNode, vector<int> &currPath) {
    visited[node] = 1;
    currPath.push_back(node);
    if(maxDepth <= depth) {
        maxDepth = depth;
        farthestNode = node;
        path = currPath;
    }
    for(list<int> :: iterator it = g[node].begin(); it != g[node].end(); it++) {
        if(!visited[*it]) {
            dfs(*it, visited, depth+1, farthestNode, currPath);
        }
    }
    currPath.pop_back();
}

int GraphDiameter :: getDiameter() {
    int node = g[0].front();
    int count = 0;
    int farthestNode = 1;
    vector<int> currPath;
    dfs(node, visited, count+1, farthestNode, currPath);
    // cout<<"fartest node from node 0 is "<<farthestNode<<endl;
    // cout<<"longest path is "<<endl;
    /*for(auto it = path.begin(); it != path.end(); it++) {
        cout<<*it<<"--";
    }*/
    visited.clear();
    currPath.clear();
    dfs(path[path.size()-1], visited, 1, farthestNode, currPath);
    return path.size();
}


int main() {
    int vertices = 5;
    vector<vector<int>> edges = {{1,0}, {0,4}, {1,2}, {1,3}};
    vector<bool> visited(vertices,0);
    GraphDiameter graph(vertices, edges);
    cout<<"Diameter of the graph is "<<graph.getDiameter();
    return 0;
}