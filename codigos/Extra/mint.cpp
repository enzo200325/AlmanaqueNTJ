// Mint
//
// Inteiro automaticamente modulado

template<int mod> struct Mint {
    int val;
    Mint(ll v = 0) { val = v % mod; if (val < 0) val += mod; }
    Mint pwr(Mint b, ll e) {
        Mint res;
        for (res = 1; e; e >>= 1, b = b * b) if (e & 1) res = res * b;
        return res;
    }
    bool operator==(Mint o) const { return val == o.val; }
    bool operator<(Mint o) const { return val < o.val; }
    friend Mint operator*(Mint a, Mint o) { return (ll)a.val * o.val; }
    friend Mint operator+(Mint a, Mint o) {
        a.val += o.val;
        if (a.val >= mod) a.val -= mod;
        return a;
    }
    friend Mint operator-(Mint a, Mint o) {
        a.val -= o.val;
        if (a.val < 0) a.val += mod;
        return a;
    }
    friend Mint operator^(Mint a, ll o) { return a.pwr(a, o); }
    friend Mint operator/(Mint a, Mint o) { return a * (o ^ (mod - 2)); }
};

const int mod = 998244353;
using mint = Mint<mod>;
