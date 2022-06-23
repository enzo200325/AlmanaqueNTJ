#include <bits/stdc++.h> 

const int MAX = 1e5; 

vector<vector<pair<int, int>>> Adj(MAX); 
int D[MAX]; 

int main() {
    for (int i = 0; i < MAX; i++) {
        D[i] = INT_MAX; 
    } 

    priority_queue<pair<int, int>, vector<int>, greater<int>> pq; 
    int begin_from = 1; 

    pq.push({0, begin_from}); 
    while(!pq.empty()) {
        pair<int, int> temp = pq.front(); 
        pq.pop(); 
        int u = temp.second; 
        int w = temp.first; 
        if (w < D[u]) {
            for (int i = 0; i < Adj[u].size(); i++) {
                pq.push({Adj[u][i].first + w, Adj[u][i].second}); 
            } 
        } 
    } 

} 
