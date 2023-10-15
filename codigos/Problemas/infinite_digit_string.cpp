// Kth digito na string infinita de digitos
//
// Retorna qual o numero e qual o algarismo do Kth digito
// na string infinita dos numeros naturais (12345678910111213...)
// Complexidade: O(log_10(k))

pair<ll, ll> kthdig(ll k) {
    ll qtd = 1, num_alg = 1, base = 1;
    while (1) {
        ll add = (9 * base) * num_alg;
        if (qtd + add < k) {
            qtd += add;
        } else
            break;
        base *= 10, num_alg++;
    }
    ll algarismo = (k - qtd) % num_alg;
    ll numero = (k - qtd) / num_alg + base;
    return {numero, algarismo};
}
