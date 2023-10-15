// Mint
//
// Inteiro automaticamente modulado

const int mod = 998244353;

struct mint {
    int val;
    mint(ll v = 0) { val = v % mod; if (val < 0) val += mod; }
    mint pwr(mint b, ll e) {
        mint res;
        for (res = 1; e; e >>= 1, b = b * b) if (e & 1) res = res * b;
        return res;
    }
    bool operator==(mint o) { return val == o.val; }
    friend mint operator*(mint a, mint o) { return (ll)a.val * o.val; }
    friend mint operator+(mint a, mint o) {
        a.val += o.val;
        if (a.val >= mod) a.val -= mod;
        return a;
    }
    friend mint operator-(mint a, mint o) {
        a.val -= o.val;
        if (a.val < 0) a.val += mod;
        return a;
    }
    friend mint operator^(mint a, ll o) { return a.pwr(a, o); }
    friend mint operator/(mint a, mint o) { return a * (o ^ (mod - 2)); }
};
