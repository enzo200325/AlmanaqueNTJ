// Convex Hull
//
// Algoritmo Graham's Scan
// Complexidade: O(n log(n))

bool ccw(pt &p, pt &a, pt &b, bool collinear = 0) {
    pt p1 = a - p;
    pt p2 = b - p;
    return collinear ? (p2 ^ p1) <= 0 : (p2 ^ p1) < 0;
}

vector<pt> convex_hull(vector<pt> v, bool collinear = 0) {
    int n = size(v);
    pt p0 = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < p0) p0 = v[i];
    }

    sort(begin(v), end(v), [&](pt &l, pt &r) { // sorta clockwise
        pt p1 = l - p0;
        pt p2 = r - p0;
        ll c1 = p1 ^ p2;
        return c1 < 0 || ((c1 == 0) && p0.dist2(l) < p0.dist2(r));
    });

    if (collinear) {
        for (int i = n - 2; i >= 0; i--) { // reverte o ultimo lado do poligono
            if (ccw(v[0], v[n - 1], v[i])) {
                reverse(begin(v) + i + 1, end(v));
                break;
            }
        }
    }

    vector<pt> ch{p0, v[1]};
    for (int i = 2; i < n; i++) {
        while (ch.size() > 2 && (ccw(ch.end()[-2], ch.end()[-1], v[i], !collinear))) ch.pop_back();
        ch.emplace_back(v[i]);
    }

    return ch;
}
