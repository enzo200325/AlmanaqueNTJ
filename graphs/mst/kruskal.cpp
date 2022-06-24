#include <bits/stdc++.h> 

using namespace std; 

vector<int> parent, rankk;

void make_set(int v) {
    parent[v] = v;
    rankk[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rankk[a] < rankk[b])
            swap(a, b);
        parent[b] = a;
        if (rankk[a] == rankk[b])
            rankk[a]++;
    }
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int main() {
    int n;
    vector<Edge> edges;

    //test =============
    cin >> n; 
    int m; cin >> m; 
    for (int i = 0; i < m; i++) {
        Edge e; 
        cin >> e.u >> e.v >> e.weight; 
        edges.push_back(e); 
        int temp = e.u; 
        e.u = e.v; 
        e.v = temp; 
        edges.push_back(e); 
    } 

    int cost = 0;
    vector<Edge> result;
    parent.resize(n+1);
    rankk.resize(n+1);
    for (int i = 1; i <= n; i++)
        make_set(i);

    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }
    cout << cost << endl;
} 

