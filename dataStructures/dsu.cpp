#include <bits/stdc++.h> 

using namespace std; 

vector<int> parent(n+1); 

//union by size: 
vector<int> size(n+1); 
void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

//union by rank 
vector<int> rankk(n+1); 
void make_set(int v) {
    parent[v] = v;
    rankk[v] = 0;
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

//---------------------------

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

