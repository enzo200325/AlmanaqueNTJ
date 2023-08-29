// Binary Lifting
// 
// Binary Lifting (em nodos)
//
// Computa LCA e tambem resolve queries de operacoes
// associativas e comutativas em caminhos.
//
// Build(): O(n log(n))
// Query(): O(log(n))
// Lca(): O(log(n))
//
// up[u][i] = (2 ^ i)-esimo pai do u
// st[u][i] = query ate (2 ^ i)-esimo pai do u (NAO INCLUI O U)

const int maxn = 3e5 + 5, LG = 20;
vector<int> adj[maxn];

struct BinaryLifting {
    int up[maxn][LG], st[maxn][LG], val[maxn], t = 1;
    int tin[maxn], tout[maxn];

    const int neutral = 0;
    int merge(int l, int r) { return l + r; }

    void build(int u, int p = -1) {
        tin[u] = t++;
        for (int i = 0; i < LG - 1; i++) {
            up[u][i + 1] = up[up[u][i]][i];
            st[u][i + 1] = merge(st[u][i], st[up[u][i]][i]);
        }
        for (int v : adj[u]) if (v != p) {
            up[v][0] = u, st[v][0] = val[u];
            build(v, u);
        }
        tout[u] = t++;
    }

    void build(int root, vector<int> &v) {
        t = 1;
        int N = size(v);
        for (int i = 0; i < N; i++) val[i] = v[i];
        up[root][0] = root;
        st[root][0] = val[root];
        build(root);
    }

    bool ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int query2(int u, int v, bool include_lca) {
        if (ancestor(u, v)) return include_lca ? val[u] : neutral;
        int ans = val[u];
        for (int i = LG - 1; i >= 0; i--) {
            if (!ancestor(up[u][i], v)) {
                ans = merge(ans, st[u][i]);
                u = up[u][i];
            }
        }
        return include_lca ? merge(ans, st[u][0]) : ans;
    }

    int query(int u, int v) { 
        if (u == v) return val[u];
        return merge(query2(u, v, 1), query2(v, u, 0));
    }

    int lca(int u, int v) {
        if (ancestor(u, v)) return u;
        if (ancestor(v, u)) return v;
        for (int i = LG - 1; i >= 0; i--) {
            if (!ancestor(up[u][i], v)) {
                u = up[u][i];
            }
        }
        return up[u][0];
    }

} bl;

// Binary Lifting (em arestas)
//
// up[u][i] = (2 ^ i)-esimo pai do u
// st[u][i] = query ate (2 ^ i)-esimo pai do u

const int maxn = 3e5 + 5, LG = 20;
vector<pair<int, int>> adj[maxn];

struct BinaryLifting {
    int up[maxn][LG], st[maxn][LG], t = 1;
    int tin[maxn], tout[maxn];

    const int neutral = 0;
    int merge(int l, int r) { return l + r; }

    void build(int u, int p = -1) {
        tin[u] = t++;
        for (int i = 0; i < LG - 1; i++) {
            up[u][i + 1] = up[up[u][i]][i];
            st[u][i + 1] = merge(st[u][i], st[up[u][i]][i]);
        }
        for (auto [w, v] : adj[u]) if (v != p) {
            up[v][0] = u, st[v][0] = w;
            build(v, u);
        }
        tout[u] = t++;
    }

    bool ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int query2(int u, int v) {
        if (ancestor(u, v)) return neutral;
        int ans = neutral;
        for (int i = LG - 1; i >= 0; i--) {
            if (!ancestor(up[u][i], v)) {
                ans = merge(ans, st[u][i]);
                u = up[u][i];
            }
        }
        return merge(ans, st[u][0]);
    }

    int query(int u, int v) { 
        if (u == v) return neutral;
#warning TRATAR ESSE CASO ACIMA
        return merge(query2(u, v), query2(v, u));
    }
} bl;

// Binary Lifting para operacoes nao comutativas (em nodos)
//
// Levemente diferente do padrao
//
// Esse aqui resolve query de Kadani em arvore
// https://codeforces.com/contest/1843/problem/F2

const int maxn = 3e5 + 5, LG = 20;
vector<int> adj[maxn];

struct node {
    int pref, suff, sum, best;
};
const node neutral = {0, 0, 0, 0};
node new_node(int x) {
    return node{x, x, x, x};
}

node merge(node& l, node& r) {
    int pref = max(l.pref, l.sum + r.pref);
    int suff = max(r.suff, r.sum + l.suff);
    int sum = l.sum + r.sum;
    int best = max(l.suff + r.pref, max(l.best, r.best));
    return node{pref, suff, sum, best};
}

struct BinaryLifting {
    int up[maxn][LG], val[maxn], t = 1;
    int tin[maxn], tout[maxn];
    node st[maxn][LG], st2[maxn][LG];

    void build(int u, int p = -1) {
        tin[u] = t++;
        for (int i = 0; i < LG - 1; i++) {
            up[u][i + 1] = up[up[u][i]][i];
            st[u][i + 1] = merge(st[u][i], st[up[u][i]][i]);
            st2[u][i + 1] = merge(st2[up[u][i]][i], st2[u][i]);
        }
        for (int v : adj[u]) if (v != p) {
            up[v][0] = u;
            st[v][0] = new_node(val[u]);
            st2[v][0] = new_node(val[u]);
            build(v, u);
        }
        tout[u] = t++;
    }

    void build(int root, vector<int> &v) {
        t = 1;
        int N = size(v);
        for (int i = 0; i < N; i++) val[i] = v[i];
        up[root][0] = root;
        st[root][0] = new_node(val[root]);
        st2[root][0] = new_node(val[u]);
        build(root);
    }

    bool ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    node query2(int u, int v, bool include_lca, bool invert) {
        if (ancestor(u, v)) return include_lca ? new_node(val[u]) : neutral;
        node ans = new_node(val[u]);
        for (int i = LG - 1; i >= 0; i--) {
            if (!ancestor(up[u][i], v)) {
                if (invert) ans = merge(st2[u][i], ans);
                else ans = merge(ans, st[u][i]);
                u = up[u][i];
            }
        }
        if (!include_lca) return ans;
        return merge(ans, st[u][0]);
    }

    node query(int u, int v) { 
        if (u == v) return new_node(val[u]);
        node l = query2(u, v, 1, 0);
        node r = query2(v, u, 0, 1);
        return merge(l, r);
    }

    int lca(int u, int v) {
        if (ancestor(u, v)) return u;
        if (ancestor(v, u)) return v;
        for (int i = LG - 1; i >= 0; i--) {
            if (!ancestor(up[u][i], v)) {
                u = up[u][i];
            }
        }
        return up[u][0];
    }

} bl, bl2;

