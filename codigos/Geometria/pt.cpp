// Ponto (Inteiro)
//
// Ponto com coordenadas inteiras e alguns metodos

struct pt {
    ll x, y;
    pt() : x(0), y(0) {}
    pt(ll _x, ll _y) : x(_x), y(_y) {}

    pt operator*(const ll &b) { return pt(b * x, b * y); }
    pt operator-(const pt &b) { return pt(x - b.x, y - b.y); }
    pt operator+(const pt &b) { return pt(x + b.x, y + b.y); }
    ll operator*(const pt &b) { return x * b.x + y * b.y; }
    ll operator^(const pt &b) { return x * b.y - y * b.x; }

    bool operator<(const pt &p) {
        if (x == p.x) return y < p.y;
        return x < p.x;
    }
    ll dist2(const pt &p) {
        ll dx = x - p.x;
        ll dy = y - p.y;
        return dx * dx + dy * dy;
    }

    friend ostream &operator<<(ostream &out, const pt &a) { return out << "(" << a.x << "," << a.y << ")"; }
    friend istream &operator>>(istream &in, pt &a) { return in >> a.x >> a.y; }
};
