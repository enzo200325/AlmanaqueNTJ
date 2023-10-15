// Mint easier
//
// Inteiro automaticamente modulado
// Bem compacto

struct mint {
    int val;
    int fix(ll x) { return ((x % mod) + mod) % mod; }
    mint(ll v = 0) { val = fix(v); }
    mint pwr(mint b, ll e) {
        mint res;
        for (res = 1; e; e >>= 1, b = b * b) if (e & 1) res = res * b;
        return res;
    }
    bool operator==(mint o) { return val == o.val; }
    friend mint operator*(mint a, mint o) { return a.fix((ll)a.val * o.val); }
    friend mint operator+(mint a, mint o) { return a.fix(a.val + o.val); }
    friend mint operator-(mint a, mint o) { return a.fix(a.val - o.val); }
    friend mint operator^(mint a, ll o) { return a.pwr(a, o); }
    friend mint operator/(mint a, mint o) { return a * (o ^ (mod - 2)); }
};
