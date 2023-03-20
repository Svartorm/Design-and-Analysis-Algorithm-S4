// 
// https://www.spoj.com/problems/ULM09/
//

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define edge pair<int, int>

class Graph {
    private:
    vector<pair<int, edge> > G;  // graph
    vector<pair<int, edge> > T;  // mst
    int *parent;
    int V;  // number of vertices/nodes in graph
    public:
    Graph(int V);
    void AddWeightedEdge(int u, int v, int w);
    int find_set(int i);
    void union_set(int u, int v);
    void kruskal();
    void print();
    int getMSTCost();
};
Graph::Graph(int V) {
    parent = new int[V];

    //i 0 1 2 3 4 5
    //parent[i] 0 1 2 3 4 5
    for (int i = 0; i < V; i++)
        parent[i] = i;

    G.clear();
    T.clear();
}
void Graph::AddWeightedEdge(int u, int v, int w) {
    G.push_back(make_pair(w, edge(u, v)));
}
int Graph::find_set(int i) {
    // If i is the parent of itself
    if (i == parent[i])
        return i;
    else
        // Else if i is not the parent of itself
        // Then i is not the representative of his set,
        // so we recursively call Find on its parent
        return find_set(parent[i]);
}

void Graph::union_set(int u, int v) {
    parent[u] = parent[v];
}
void Graph::kruskal() {
    int i, uRep, vRep;
    sort(G.begin(), G.end());  // increasing weight
    for (i = 0; i < G.size(); i++) {
        uRep = find_set(G[i].second.first);
        vRep = find_set(G[i].second.second);
        if (uRep != vRep) {
        T.push_back(G[i]);  // add to tree
        union_set(uRep, vRep);
        }
    }
}
int Graph::getMSTCost() {
    int sum = 0;
    for (int i = 0; i < T.size(); i++) {
        sum += T[i].first;
    }
    return sum;
}
void Graph::print() {
    cout << "Edge :"
        << " Weight" << endl;
    for (int i = 0; i < T.size(); i++) {
        cout << T[i].second.first << " - " << T[i].second.second << " : "
        << T[i].first;
        cout << endl;
    }
}

int main() {
    while (true) {
        int Junction, Roads, totalCost = 0;
        scanf("%d %d", &Junction, &Roads);

        if (Junction == 0 && Roads == 0) {
            break;
        }

        // create graph
        Graph g(Junction);

        for (int i = 0; i < Roads; i++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);

            // add edge
            g.AddWeightedEdge(a, b, c);
            totalCost += c;
        }

        // run kruskal
        g.kruskal();
        //g.print();

        printf("%d", totalCost - g.getMSTCost());
    }
}