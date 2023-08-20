// Binary Lifting
// 
// Binary Lifting (em nodos)
//
// Computa LCA e tambem resolve queries de operacoes
// associativas e comutativas em caminhos. Para operacoes
// nao comutativas, modificar funcao query ou usar HLD.
//
// Build(): O(n log(n))
// Query(): O(log(n))
// Lca(): O(log(n))
//
// up[u][i] = (2 ^ i)-esimo pai do u
// st[u][i] = query ate (2 ^ i)-esimo pai do u (NAO INCLUI O U)

const int maxn = 1e5 + 5, LG = 20;
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
        int N = size(v);
        for (int i = 0; i < N; i++) val[i] = v[i];
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

const int maxn = 1e5 + 5, LG = 20;
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
