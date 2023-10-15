// Fenwick Tree
//
// Processas queries de operacao com inverso
//
// Build: O(n)
// Query: O(log(n))
// Update: O(log(n))

typedef long long ll;

struct fenwick {
    vector<ll> bit;
    fenwick(int n) { bit.assign(n + 1, 0); }
    fenwick(vector<ll> &v) {
        int n = v.size();
        bit.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) bit[i] = v[i - 1];
        for (int i = 1; i <= n; i++) {
            int j = i + (i & -i);
            if (j <= n) bit[j] += bit[i];
        }
    }
    ll query(int i) {
        ll res = 0;
        for (; i; i -= (i & -i)) res += bit[i];
        return res;
    }
    ll query(int l, int r) { return query(r) - query(l - 1); }
    void update(int i, ll d) {
        for (; i && i < (int)bit.size(); i += (i & -i)) bit[i] += d;
    }
};
