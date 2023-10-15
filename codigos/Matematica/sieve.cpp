// Crivo de Eratostenes
//
// Computa numeros primos entre [2, n] em O(n)
//
// Crivo linear computando spf (smallest prime factor) pra cada numero
// x entre [2, n] e phi(x) (funcao totiente)
// Complexidade: O(n)

int spf[maxn], phi[maxn];
vector<int> primes;
void sieve(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.emplace_back(i);
            phi[i] = i - 1;
        }
        for (int j = 0; j < (int)primes.size() && i * primes[j] <= n && primes[j] <= spf[i]; j++) {
            spf[i * primes[j]] = primes[j];
            if (primes[j] < spf[i])
                phi[i * primes[j]] = phi[i] * phi[primes[j]];
            else
                phi[i * primes[j]] = phi[i] * primes[j];
        }
    }
}
