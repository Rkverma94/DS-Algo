#include<bits/stdc++.h>
using namespace std;
class Graph {
    private:

        vector<list<int>> graph;
    public:
        Graph() {

        }
        vector<list<int>> initGraph(int, vector<vector<int>>);
        void dfs(int, vector<bool> &);
        void printGraph();
};

void Graph :: dfs(int node, vector<bool> &visited) {
    visited[node] = true;
    cout<<"node visiting--->"<<node<<endl;
    for(list<int> :: iterator it = graph[node].begin(); it != graph[node].end(); it++) {
        if(!visited[*it]) {
            dfs(*it, visited);
        }
    }
}

vector<list<int>> Graph :: initGraph(int vertices, vector<vector<int>> edges) {
    cout<<"init graph"<<endl;
    graph.resize(vertices);

    for(int i=0; i<edges.size(); i++) {
        cout<<"edges["<<i<<"][0] = "<<edges[i][0]<<endl;
        cout<<"edges["<<i<<"][1] = "<<edges[i][1]<<endl;
        int a = edges[i][0];
        int b = edges[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    return graph;
}

void Graph :: printGraph() {
    cout<<"in print method"<<endl;
    for(int i=0; i<graph.size(); i++) {
        for(list<int> :: iterator it = graph[i].begin(); it != graph[i].end(); it++) {
            cout<<*it<<"-->";
        }
        cout<<endl;
    }
}

int main() {
    int vertices = 4;
    vector<vector<int>> edges = {{1,0}, {1,2}, {1,3}};
    vector<bool> visited(vertices,0);
    Graph graph;
    graph.initGraph(vertices, edges);
    graph.printGraph();
    graph.dfs(0, visited);
    return 0;
}