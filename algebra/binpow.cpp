#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
const int MOD = 1e9+7;

ll binpow(ll b, ll e) {
    int res = 1; 
    for (; e; e>>=1) {
        if (e&1) res = res*b % MOD;
        b = b*b % MOD;
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
