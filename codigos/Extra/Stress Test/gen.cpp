// Gerador aleatorio de casos

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r) {
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

int main(){
    cout << uniform(1, 10) << endl;
}
