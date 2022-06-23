#include <bits/stdc++.h> 

using namespace std;

const int MAX = 1e5; 
typedef pair<int,int> ii;

vector<vector<pair<int, int>>> Adj(MAX); 
int D[MAX]; 
priority_queue<ii, vector<ii>, greater<ii>> pq; 

int main() {
    for (int i = 0; i < MAX; i++) {
        D[i] = INT_MAX; 
    } 

    int begin_from = 1;

    pq.push({0, begin_from}); 
    while(!pq.empty()) {
        pair<int, int> temp = pq.top(); 
        pq.pop(); 
        int u = temp.second; 
        int w = temp.first; 
        if (w < D[u]) {
            D[u] = w;
            for (int i = 0; i < Adj[u].size(); i++) {
                pq.push({Adj[u][i].first + w, Adj[u][i].second}); 
            } 
        } 
    } 
} 
