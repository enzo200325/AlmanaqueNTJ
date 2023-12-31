// Hashing dinamico (com update)
// 
// Usa o mint e rng()
// Usa fenwick pra updatar
//
// Build: O(n)
// Query: O(log(n))
// Update: O(log(n))
//
// LEMBRAR DE CHAMAR O initPrime() !
//
// para usar apenas 1 mod:
// using Hash = mint;

const int mod1 = 998244353;
const int mod2 = 1e9 + 7;

using mint1 = Mint<mod1>;
using mint2 = Mint<mod2>;
using Hash = pair<mint1, mint2>;

Hash operator*(Hash a, Hash o) {
    return {a.first * o.first, a.second * o.second};
}
Hash operator+(Hash a, Hash o) {
    return {a.first + o.first, a.second + o.second};
}
Hash operator-(Hash a, Hash o) {
    return {a.first - o.first, a.second - o.second};
}

const int ORD = 1e6;
const int PRIME = ORD + (rng() % ORD); // nao necessariamente primo

const int MAXN = 4e5 + 5;

Hash P = {PRIME, PRIME};
Hash invP = {mint1(1) / PRIME, mint2(1) / PRIME};

Hash p[MAXN], invp[MAXN];

void initPrime() {
    p[0] = invp[0] = Hash(1, 1);
    for (int i = 1; i < MAXN; i++) {
        p[i] = p[i - 1] * P;
        invp[i] = invp[i - 1] * invP;
    }
}

template<typename obj = string> struct DynamicHashing {
    int N;
    fenwick<Hash> hsh;
    DynamicHashing () {}
    DynamicHashing(obj s) : N(size(s)) {
        vector<Hash> arr(N);
        for (int i = 0; i < N; i++) {
            arr[i] = (p[i + 1] * Hash(s[i], s[i]));
        }
        hsh = fenwick(arr);
    }
    Hash operator()(int l, int r) {
        return hsh.query(l, r) * invp[l];
    }
    void update(int i, char c) {
        hsh.setUpdate(i, Hash(c, c) * p[i + 1]);
    }
};

template<typename obj = string> struct revDynamicHashing {
    // hash em que query(l, r) retorna o hash da substring de [l, r] invertida
    // util pra verificar palindromos e afins
    int N;
    fenwick<Hash> hsh;
    revDynamicHashing () {}
    revDynamicHashing(obj s) : N(size(s)) {
        vector<Hash> arr(N);
        for (int i = N - 1; i >= 0; i--) {
            arr[i] = (p[N - i] * Hash(s[i], s[i]));
        }
        hsh = fenwick(arr);
    }
    Hash operator()(int l, int r) {
        return hsh.query(l, r) * invp[N - r - 1];
    }
    void update(int i, char c) {
        hsh.setUpdate(i, Hash(c, c) * p[N - i]);
    }
};
