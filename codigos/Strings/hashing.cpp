// Hashing
//
// Hashing estatico
// Tambem funciona com vector
//
// Build: O(n)
// Query (operator): O(1)

const int mods = 1;
typedef array<ll, mods> Hash; // array<T, mods>

template <typename obj = string, typename T = ll, typename U = __int128_t> struct Hashing {
    int N;
    bool inverse = 0;
    U p = 1001003;
    Hash mod{(T)1e18 + 9};
    array<vector<T>, mods> pw, hsh;
    void build(obj s, bool _inverse = 0) {
        inverse = _inverse;
        if (inverse) reverse(begin(s), end(s));
        N = size(s);
        for (int j = 0; j < mods; j++) {
            pw[j].resize(N), hsh[j].resize(N);
            pw[j][0] = 1;
            hsh[j][0] = s[0] % mod[j];
            for (int i = 1; i < N; i++) {
                pw[j][i] = (U)pw[j][i - 1] * p % mod[j];
                hsh[j][i] = ((U)hsh[j][i - 1] * p + s[i]) % mod[j];
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
                ans[j] = (ans[j] - ((U)hsh[j][l - 1] * pw[j][r - l + 1] % mod[j]) + mod[j]) % mod[j];
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

const int mods = 1;
typedef array<ll, mods> Hash; // array<T, mods>

template <typename obj = string, typename T = ll, typename U = __int128_t> struct Hashing {
    int N;
    bool inverse = 0;
    U p = 1001003;
    Hash mod{(ll)1e18 + 9};
    array<vector<ll>, mods> pw, hsh, inv;
    void build(obj s, bool _inverse = 0) {
        inverse = _inverse;
        if (inverse) reverse(begin(s), end(s));
        N = size(s);
        for (int j = 0; j < mods; j++) {
            pw[j].resize(N + 1), hsh[j].resize(N + 1), inv[j].resize(N + 1);
            pw[j][1] = p;
            pw[j][0] = inv[j][0] = inv[j][1] = 1;
            U b = p;
            for (U e = mod[j] - 2; e > 0; e >>= 1, b = b * b % mod[j]) {
                if (e & 1) inv[j][1] = (U)inv[j][1] * b % mod[j];
            }
            for (int i = 2; i <= N; i++) {
                inv[j][i] = (U)inv[j][i - 1] * inv[j][1] % mod[j];
                pw[j][i] = (U)pw[j][i - 1] * pw[j][1] % mod[j];
            }
            hsh[j][1] = s[0] * pw[j][1] % mod[j];
            for (int i = 2; i <= N; i++) {
                hsh[j][i] = (U)s[i - 1] * pw[j][i] % mod[j];
            }
            for (int i = 1; i <= N; i++) {
                int u = i + (i & -i);
                if (u <= N) hsh[j][u] = (hsh[j][u] + hsh[j][i]) % mod[j];
            }
        }
    }
    Hash operator()(int l, int r) {
        assert(l <= r);
        if (inverse) {
            l = N - 1 - l, r = N - 1 - r;
            swap(l, r);
        }
        Hash ans;
        l += 1, r += 1;
        for (int j = 0; j < mods; j++) {
            ans[j] = 0;
            for (int i = r; i > 0; i -= (i & -i)) {
                ans[j] = (ans[j] + hsh[j][i]) % mod[j];
            }
            for (int i = l - 1; i > 0; i -= (i & -i)) {
                ans[j] = (ans[j] - hsh[j][i] + mod[j]) % mod[j];
            }
            ans[j] = (U)ans[j] * inv[j][l - 1] % mod[j];
        }
        return ans;
    }
    void update(int idx, T val) {
        if (inverse) idx = N - 1 - idx;
        idx += 1;
        for (int j = 0; j < mods; j++) {
            T u = 0;
            for (int i = idx; i > 0; i -= (i & -i)) {
                u = (u + hsh[j][i]) % mod[j];
            }
            for (int i = idx - 1; i > 0; i -= (i & -i)) {
                u = (u - hsh[j][i] + mod[j]) % mod[j];
            }
            for (int i = idx; i <= N; i += (i & -i)) {
                hsh[j][i] = (hsh[j][i] - u + mod[j]) % mod[j];
            }
            for (int i = idx; i <= N; i += (i & -i)) {
                hsh[j][i] = (hsh[j][i] + (U)val * pw[j][idx] % mod[j]) % mod[j];
            }
        }
    }
};
