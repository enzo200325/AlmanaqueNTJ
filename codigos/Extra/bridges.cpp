// Bridges e ebcc
//
// dfaffds
// fsf
// dsa
// fadsfsad
// f

const int maxn = 4e5;
int n, m;
bool vis[maxn];
int dp[maxn], dep[maxn];
vector<int> adj[maxn];
vector<ii> bridges;

void dfs_dp(int u, int p = -1, int d = 0){
    dp[u] = 0, dep[u] = d, vis[u] = 1;
    for(auto v : adj[u]) if(v != p) {
        if(vis[v]){
            if(dep[v] < dep[u]) dp[v]--, dp[u]++;
        } else {
            dfs_dp(v, u, d+1);
            dp[u] += dp[v];
        }
    }
    if(dp[u] == 0 && p != -1){ // edge {u, p} eh uma ponte
        bridges.emplace_back(u, p);
    }
}

void find_bridges(){
    memset(vis, 0, n+1);
    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs_dp(i);
    }
}

// EDGE BICONNECTED COMPONENTS (requer todo codigo acima)
int ebcc[maxn], ncc = 1;
vector<int> adjbcc[maxn];

void dfs_ebcc(int u, int p = -1, int cc = 1){
    vis[u] = 1;
    if(dp[u] == 0 && p != -1){
        cc = ++ncc;
    }
    ebcc[u] = cc;
    for(auto v : adj[u]) if(!vis[v]) {
        dfs_ebcc(v, u, cc);
    }
}

void build_ebcc_graph(){
    find_bridges();
    memset(vis, 0, n+1);
    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs_ebcc(i);
    }
    // Opcao 1 - constroi o grafo condensado passando por todas as edges
    for(int u = 1; u <= n; u++){
        for(auto v : adj[u]){
            if(ebcc[u] != ebcc[v]){
                adjbcc[ebcc[u]].emplace_back(ebcc[v]);
            } else {
                // faz algo
            }
        }
    }
    // Opcao 2 - constroi o grafo condensado passando so pelas pontes
    for(auto [u,v] : bridges){
        adjbcc[ebcc[u]].emplace_back(ebcc[v]);
        adjbcc[ebcc[v]].emplace_back(ebcc[u]);
    }
}
