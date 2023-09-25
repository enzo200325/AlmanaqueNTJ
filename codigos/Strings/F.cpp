#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 3e5+5;
int arr[MAXN], n;

typedef long long ll;

// Hashing dinamico
//
// Hash que usa uma Fenwick pra updatar
//
// Build: O(n)
// Query (operator): O(log(n))
// Update: O(log(n))

// Hash dinamico com 1 mod

typedef ll Hash; 
template <typename obj = string, typename T = ll, typename U = __int128_t> struct Hashing {
    int N;
    bool inverse = 0;
    U p = 1001003;
    T mod = (T)1e18 + 9;
    vector<U> pw, hsh, inv;
    void build(obj s, bool _inverse = 0) {
        inverse = _inverse;
        if (inverse) reverse(begin(s), end(s));
        N = size(s);
        pw.resize(N + 1), hsh.resize(N + 1), inv.resize(N + 1);
        pw[1] = p;
        pw[0] = inv[0] = inv[1] = 1;
        U b = p;
        for (T e = mod - 2; e > 0; e >>= 1, b = b * b % mod) {
            if (e & 1) inv[1] = inv[1] * b % mod;
        }
        for (int i = 2; i <= N; i++) {
            inv[i] = inv[i - 1] * inv[1] % mod;
            pw[i] = pw[i - 1] * pw[1] % mod;
        }
        hsh[1] = s[0] * pw[1] % mod;
        for (int i = 2; i <= N; i++) {
            hsh[i] = s[i - 1] * pw[i] % mod;
        }
        for (int i = 1; i <= N; i++) {
            int u = i + (i & -i);
            if (u <= N) hsh[u] = (hsh[u] + hsh[i]) % mod;
        }
    }
    Hash operator()(int l, int r) {
        if (inverse) {
            l = N - 1 - l, r = N - 1 - r;
            swap(l, r);
        }
        l += 1, r += 1;
        Hash ans = 0;
        for (int i = r; i > 0; i -= i & -i) {
            ans = (ans + hsh[i]) % mod;
        }
        for (int i = l - 1; i > 0; i -= i & -i) {
            ans = (ans - hsh[i] + mod) % mod;
        }
        ans = ans * inv[l - 1] % mod;
        return ans;
    }
    void update(int idx, T val) { // update de soma
        if (inverse) idx = N - 1 - idx;
        idx += 1;
        for (int i = idx; i <= N; i += i & -i) {
            hsh[i] = (hsh[i] + val * pw[idx] % mod) % mod;
        }
    }
};

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arr[i] -= 1;
    }

    vector<int> vis(n);
    Hashing<vector<int>> a, b;
    a.build(vis);
    b.build(vis, 1);

    for(int i = 0; i < n; i++){
        a.update(arr[i], 1);
        b.update(arr[i], 1);

        int k = min(arr[i], n - 1 - arr[i]);
        int l = arr[i] - k, r = arr[i] + k;

        if(a(l, arr[i]) != b(arr[i], r)){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}
