// Hashing estatico (sem update)
// 
// Usa o mint
//
// Build: O(n)
// Query: O(1)

// para usar 1 mod apenas
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

const int PRIME = 1000000 + (rng() % 1000000); // nao necessariamente primo

const int maxn = 1e6 + 5;
Hash P = {PRIME, PRIME};
Hash invP = {mint1(1) / PRIME, mint2(1) / PRIME};
Hash p[maxn], invp[maxn];

void initPrime() {
    p[0] = invp[0] = Hash(1, 1);
    for (int i = 1; i < N; i++) {
        p[i] = p[i - 1] * P;
        invp[i] = invp[i - 1] * invP;
    }
}

template<typename obj> struct Hashing {
    int N;
    vector<Hash> hsh;
    Hashing () {}
    Hashing(obj s) : N(size(s)), hsh(N + 1) {
        for (int i = 0; i < N; i++) {
            hsh[i + 1] = hsh[i] + (p[i + 1] * Hash(s[i], s[i]));
        }
    }
    Hash operator()(int l, int r) const {
        l++; r++;
        return (hsh[r] - hsh[l - 1]) * invp[l - 1];
    }
};

template<typename obj> struct revHashing { // util pra verificar palindromos e afins
    int N;
    vector<Hash> hsh;
    revHashing () {}
    revHashing(obj s) : N(size(s)), hsh(N + 1) {
        for (int i = N - 1; i >= 0; i--) {
            hsh[i] = hsh[i + 1] + (p[N - i] * Hash(s[i], s[i]));
        }
    }
    Hash operator()(int l, int r) const {
        return (hsh[l] - hsh[r + 1]) * invp[N - r - 1];
    }
};
