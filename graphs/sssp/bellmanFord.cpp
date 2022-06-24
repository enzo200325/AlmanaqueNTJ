#include <bits/stdc++.h> 

using namespace std;

struct edge
{
    int a, b, cost;
};

int n, m, v;
vector<edge> e;
const int INF = 1000000000;

void solve()
{
    vector<int> d (n+1, INF);
    d[v] = 0;
    for (;;)
    {
        bool any = false;

        //if graph is undirected, be careful with m (the number of edges) 
        for (int j=0; j<2*m; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost)
                {
                    d[e[j].b] = d[e[j].a] + e[j].cost;
                    any = true;
                }

        if (!any) break;
    }
    // display d, for example, on the screen
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " "; 
    } 
    cout << endl;
}

//test
int main() {
    cin >> n >> m; 
    for (int i = 0; i < m; i++) {
        edge* ne = new edge; 
        cin >> ne -> a >> ne -> b >> ne -> cost; 
        e.push_back(*ne); 
        int temp = ne -> a; 
        ne -> a = ne -> b; 
        ne -> b = temp; 
        e.push_back(*ne); 
    } 
    cin >> v; 
    solve(); 
} 
