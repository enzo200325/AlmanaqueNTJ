// Hashing estatico e dinamico
//
// Hashing estatico
// Tambem funciona com vector
//
// Build: O(n)
// Query (operator): O(1)

// Hash com 1 mod

template <typename obj = string, typename T = ll, typename U = __int128_t> struct Hashing {
    int N;
    bool inverse = 0;
    U p = 1001003;
    T mod = (T)1e18 + 9;
    vector<U> pw, hsh;
    void build(obj s, bool _inverse = 0) {
        inverse = _inverse;
        if (inverse) reverse(begin(s), end(s));
        N = size(s);
        pw.assign(N, 1), hsh.assign(N, s[0] % mod);
        for (int i = 1; i < N; i++) {
            pw[i] = pw[i - 1] * p % mod;
            hsh[i] = (hsh[i - 1] * p + s[i]) % mod;
        }
    }
    ll operator()(int l, int r) {
        if (inverse) {
            l = N - 1 - l, r = N - 1 - r;
            swap(l, r);
        }
        Hash ans = hsh[r];
        if (l > 0) ans = (ans - (hsh[l - 1] * pw[r - l + 1] % mod) + mod) % mod;
        return ans;
    }
};

// Hash com multiplos mods

const int mods = 2;
typedef array<int, mods> Hash; // array<T, mods>

template <typename obj = string, typename T = int, typename U = ll> struct Hashing {
    int N;
    bool inverse = 0;
    U p = 1001003;
    Hash mod {998244353, (T)1e9 + 9};
    array<vector<U>, mods> pw, hsh;
    void build(obj s, bool _inverse = 0) {
        inverse = _inverse;
        if (inverse) reverse(begin(s), end(s));
        N = size(s);
        for (int j = 0; j < mods; j++) {
            pw[j].assign(N, 1), hsh[j].assign(N, s[0] % mod[j]);
            for (int i = 1; i < N; i++) {
                pw[j][i] = pw[j][i - 1] * p % mod[j];
                hsh[j][i] = (hsh[j][i - 1] * p + s[i]) % mod[j];
            }
        }
    }
    Hash operator()(int l, int r) {
        if (inverse) {
            l = N - 1 - l, r = N - 1 - r;
            swap(l, r);
        }
        Hash ans;
        for (int j = 0; j < mods; j++) {
            ans[j] = hsh[j][r];
            if (l > 0) {
                ans[j] = (ans[j] - (hsh[j][l - 1] * pw[j][r - l + 1] % mod[j]) + mod[j]) % mod[j];
            }
        }
        return ans;
    }
};

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

// Hash dinamico com multiplos mods

const int mods = 2;
typedef array<int, mods> Hash; // array<T, mods>
 
template <typename obj = string, typename T = int, typename U = ll> struct Hashing {
    int N;
    bool inverse = 0;
    U p = 1001003;
    Hash mod {998244353, (T)1e9 + 9};
    array<vector<U>, mods> pw, hsh, inv;
    void build(obj s, bool _inverse = 0) {
        inverse = _inverse;
        if (inverse) reverse(begin(s), end(s));
        N = size(s);
        for (int j = 0; j < mods; j++) {
            pw[j].resize(N + 1), hsh[j].resize(N + 1), inv[j].resize(N + 1);
            pw[j][1] = p;
            pw[j][0] = inv[j][0] = inv[j][1] = 1;
            U b = p;
            for (T e = mod[j] - 2; e > 0; e >>= 1, b = b * b % mod[j]) {
                if (e & 1) inv[j][1] = inv[j][1] * b % mod[j];
            }
            for (int i = 2; i <= N; i++) {
                inv[j][i] = inv[j][i - 1] * inv[j][1] % mod[j];
                pw[j][i] = pw[j][i - 1] * pw[j][1] % mod[j];
            }
            hsh[j][1] = s[0] * pw[j][1] % mod[j];
            for (int i = 2; i <= N; i++) {
                hsh[j][i] = s[i - 1] * pw[j][i] % mod[j];
            }
            for (int i = 1; i <= N; i++) {
                int u = i + (i & -i);
                if (u <= N) hsh[j][u] = (hsh[j][u] + hsh[j][i]) % mod[j];
            }
        }
    }
    Hash operator()(int l, int r) {
        if (inverse) {
            l = N - 1 - l, r = N - 1 - r;
            swap(l, r);
        }
        Hash ans;
        l += 1, r += 1;
        for (int j = 0; j < mods; j++) {
            ans[j] = 0;
            for (int i = r; i > 0; i -= i & -i) {
                ans[j] = (ans[j] + hsh[j][i]) % mod[j];
            }
            for (int i = l - 1; i > 0; i -= i & -i) {
                ans[j] = (ans[j] - hsh[j][i] + mod[j]) % mod[j];
            }
            ans[j] = ans[j] * inv[j][l - 1] % mod[j];
        }
        return ans;
    }
    void update(int idx, T val) { // update de soma
        if (inverse) idx = N - 1 - idx;
        idx += 1;
        for (int j = 0; j < mods; j++) {
            for (int i = idx; i <= N; i += i & -i) {
                hsh[j][i] = (hsh[j][i] + val * pw[j][idx] % mod[j]) % mod[j];
            }
        }
    }
};
