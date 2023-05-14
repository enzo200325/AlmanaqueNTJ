// Gerador aleatorio de inteiros em [l, r]

mt19937 rng(chrono::steady_clock::now() .time_since_epoch().count());

ll uniform(ll l, ll r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
