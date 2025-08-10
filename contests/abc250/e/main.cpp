#include "template"
#include "inthash"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;
    vi b(n); cin >> b;
    vec<ull> hasha(n+1);
    set<int> s;
    rep(i, n) {
        if (s.count(a[i])) {
            hasha[i+1] = hasha[i];
        } else {
            hasha[i+1] = hasha[i] ^ inthash(a[i]);
            s.insert(a[i]);
            }
    }
    vec<ull> hashb(n+1);
    s.clear();
    rep(i, n) {
        if (s.count(b[i])) {
            hashb[i+1] = hashb[i];
        } else {
            hashb[i+1] = hashb[i] ^ inthash(b[i]);
            s.insert(b[i]);
        }
    }
    int q; cin >> q;
    debug(hasha);
    debug(hashb);
    while (q--) {
        int x, y; cin >> x >> y;
        YN(hasha[x] == hashb[y]);
    }
}