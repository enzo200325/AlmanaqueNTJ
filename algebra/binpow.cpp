#include <bits/stdc++.h>

using namespace std; 

typedef long long ll; 

ll binpow(ll a, ll b) {
    int res = 1; 
    while (b > 0) {
        if (b & 1) {
            res *= a; 
        } 
        b >>= 1; 
        a *= a; 
    } 
    return res; 
} 

//test
int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    int n; cin >> n; 
    cout << binpow((ll)n, 5LL) << endl;
}
