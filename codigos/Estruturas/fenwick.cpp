// Fenwick Tree
//
// Processas queries de operacao com inverso
// em O(log(n)) e faz updates em O(log(n))

typedef long long ll;

struct fenwick {
    vector<ll> bit;
    fenwick (int n) { bit.assign(n+1, 0); }
    ll query(int i){
        ll res = 0;
        for(; i; i -= (i & -i))
            res += bit[i];
        return res;
    }
    ll query(int l, int r){
        return query(r) - query(l-1);
    }
    void update(int i, ll d){
        for(; i && i < (int)bit.size(); i += (i & -i))
            bit[i] += d;
    }
};
