// Fenwick Tree
//
// Processas queries em range de operacoes que possuem inverso
// Faz updates pontuais
//
// Build: O(n)
// Query: O(log(n))
// Update: O(log(n))
//
// Query e Update sao 0-indexed

template<typename T> struct fenwick {
    vector<T> bit;
    fenwick() { }
    fenwick(int n) { bit.assign(n + 1, T()); }
    fenwick(vector<T> &v) {
        int n = v.size();
        bit.assign(n + 1, T());
        for (int i = 1; i <= n; i++) bit[i] = v[i - 1];
        for (int i = 1; i <= n; i++) {
            int j = i + (i & -i);
            if (j <= n) bit[j] = bit[j] + bit[i];
        }
    }
    T pref(int i) {
        T res = T();
        while (i > 0) {
            res = res + bit[i];
            i -= i & -i;
        }
        return res;
    }
    T query(int l, int r) { return pref(r + 1) - pref(l); }
    void update(int i, T d) {
        i++;
        while (i > 0 && i < (int)bit.size()) {
            bit[i] = bit[i] + d;
            i += i & -i;
        }
    }
    void setUpdate(int i, T d) {
        T now = query(i, i);
        update(i, now * T(-1));
        update(i, d);
    }
};
