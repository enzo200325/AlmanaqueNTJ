#include <bits/stdc++.h> 

using namespace std; 

const int MAX = 1e5; 

int A[4*MAX]; 
int arr[MAX]; 

int makeSeg(int i, int j, int idx) {
    if (i == j) {
        A[idx] = arr[i]; 
        return arr[i]; 
    } 
    int mid = (i+j)/2;
    int a = makeSeg(i, mid, idx*2); 
    int b = makeSeg(mid+1, j, idx*2 + 1); 
    A[idx] = a + b; 
    return a + b; 
} 

int getSum(int i, int j, int ci, int cj, int idx) {
    if (i > j) {
        return 0; 
    } 
    else if (i == ci && j == cj) {
        return A[idx];  
    } 

    int mid = (ci + cj)/2; 
    return getSum(i, min(j, mid), ci, mid, idx*2) + getSum(max(i, mid+1), j, mid+1, cj, idx*2 + 1);  

}

void update(int v, int ci, int cj, int pos, int nv) {
    if (ci == cj) {
        A[v] = nv; 
    } 
    else {
        int mid = (ci + cj)/2; 
        if (pos <= mid) {
            update(v*2, ci, mid, pos, nv); 
        } 
        else {
            update(v*2+1, mid+1, cj, pos, nv); 
        } 
        A[v] = A[v*2] + A[v*2+1]; 
    } 
} 


//test
int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    int n; cin >> n; 
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    } 

    makeSeg(0, n-1, 1); 
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            cout << getSum(i, j, 0, n-1, 1) << endl;
        } 
    } 
    cout << "====================" << endl;
    update(1, 0, n-1, 2, 100); 
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            cout << getSum(i, j, 0, n-1, 1) << endl;
        } 
    } 
} 
