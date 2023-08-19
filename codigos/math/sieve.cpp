

// Sieve computing spf (smallest prime factor) for each number in [2, n] 
// and totient 
//
// O(n) complexity
int spf[maxn], tot[maxn]; 
vector<int> primes; 
void sieve(int n) {
    tot[1] = 1; 
    for (int i = 2; i <= n; i++) {
        if (spf[i] == 0) { spf[i] = i; primes.emplace_back(i); tot[i] = i-1; }
        for (int j = 0; j < (int)primes.size() && i*primes[j] <= n && primes[j] <= spf[i]; j++) {
            spf[i*primes[j]] = primes[j]; 
            if (primes[j] < spf[i]) tot[i*primes[j]] = tot[i]*tot[primes[j]]; 
            else tot[i*primes[j]] = tot[i]*primes[j]; 
        } 
    } 
} 
