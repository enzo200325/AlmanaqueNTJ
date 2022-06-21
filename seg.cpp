#include <bits/stdc++.h> 

using namespace std; 

const int n = 6; 

//array para o qual se quer formar a segment tree
int arr[n] = {3, 4, 1, 7, 8, 1}; 

vector<int> A(4*n); 

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

int getSum(int i, int j, int ci, int cj) {
    if (i == ci && cj == j) {

    int mid = (ci + cj)/2; 
    return getSum(i, j, ci, min(cj, mid)) + getSum(i, j, max(ci, mid+1), cj);   

}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    makeSeg(0, n-1, 1); 
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ", "; 
    } 
    cout << endl;
    for (int i = 1; i < A.size(); i++) {
        cout << A[i] << ", "; 
    } 
    cout << endl;
} 
