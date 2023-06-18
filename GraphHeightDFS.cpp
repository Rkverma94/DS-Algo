#include<bits/stdc++.h>
using namespace std;
class GraphHeight {
    private :
        vector<list<int>> g;
        
    public :
        int maxHeight = 0;
        vector<int> path;
        GraphHeight(int vertices, vector<vector<int>> edges) {
            g.resize(vertices);
            for(int i=0; i<edges.size(); i++) {
                int a = edges[i][0];
                int b = edges[i][1];
                g[a].push_back(b);
                g[b].push_back(a);
            }
        }
        void getHeight(int, vector<bool> &, vector<int> &, int);
};

void GraphHeight :: getHeight(int node, vector<bool> &visited, vector<int> &currPath, int height) {
    visited[node] = true;
    currPath.push_back(node);
    if(maxHeight <= height) {
        maxHeight = height;
        path = currPath;
    }
    for(auto it = g[node].begin(); it != g[node].end(); it++) {
        if(!visited[*it]) {
            getHeight(*it, visited, currPath, height+1);
        }
    }
    cout<<"Current Path with "<<node<<" is "<<endl;
    for(auto it = currPath.begin(); it != currPath.end(); it++) {
        cout<<*it<<"--";
    }
    currPath.pop_back();
    cout<<endl;
}

int main() {
    int vertices = 5;
    vector<vector<int>> edges = {{1,0}, {0,4}, {1,2}, {1,3}};
    vector<bool> visited(vertices,0);
    vector<int> currPath;
    GraphHeight graph(vertices, edges);
    int node = 3;
    graph.getHeight(node, visited, currPath, 0);
    cout<<"Height of graph by DFS choosing "<<node<<" is "<<graph.maxHeight<<endl;
    cout<<"Longest path tracked is "<<endl;
    for(auto it = graph.path.begin(); it != graph.path.end(); it++) {
        cout<<*it<<"--";
    }
    return 0;
}