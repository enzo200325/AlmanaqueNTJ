// Mint
//
// Inteiro automaticamente modulado

const int mod = 998244353;
struct Mint {
    int val;
    Mint(int v = 0) { val = v % mod; }
    bool operator == (Mint o) { return val == o.val; }
    int operator * (Mint o) { return (((ll)val * o.val) % mod); }
    int operator + (Mint o) { return ((ll)val + o.val) % mod; }
    int operator - (Mint o) { return ((ll)val - o.val + mod) % mod; }
    int operator ^ (ll o) { return pwr(val, o); }
    int pwr(Mint b, ll e) {
        Mint res; for (res = 1; e; e >>= 1, b = b * b) if (e & 1) res = res * res;
        return res.val;
    }
};
