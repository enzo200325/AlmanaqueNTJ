#include <bits/stdc++.h>

using namespace std; 

struct FenwickTree2D {
    vector<vector<int>> bit;  // binary indexed tree
    int n, m;

    FenwickTree2D(int n, int m) {
        this->n = n;
        this->m = m; 
        for (int i = 0; i < n; i++) {
            bit[i].assign(m, 0); 
        } 
    }

    //estranho essa bomba:  
    FenwickTree2D(vector<vector<int>> a) : FenwickTree2D(a.size(), a[0].size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int x, int y) {
        int ret = 0;
        for (int i = x; i >= 0; i = (i & (i  + 1)) - 1) {
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
                ret += bit[i][j]; 
            } 
        } 
        return ret;
    }

    void add(int x, int y, int delta) {
        for (int i = x; i < n; i = i | (i + 1)) {
            for (int j = y; j < n; j = j | (j + 1)) {
                bit[i][j] += delta; 
            } 
        } 
    }
};

//test
int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    int n; cin >> n; 
    int m; cin >> m; 
    vector<vector<int>> A(n, vector<int>(m)); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j]; 
        } 
    } 

    FenwickTree2D ft(A); 
    cout << ft.sum(2, 3) << endl; 
}
