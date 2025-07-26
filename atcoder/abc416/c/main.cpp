#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}
void solve() {
    int n, k, x; cin >> n >> k >> x;
    vec<str> s(n); cin >> s;
    vec<str> t;
    auto f = [&](auto&& self, int i, str y) -> void {
        if (i == k) {
            t.pb(y);
            return;
        }
        for (int j = 0; j < n; ++j) {
            self(self, i + 1, y + s[j]);
        }
    };
    f(f, 0, "");
    Sort(t);
    debug(t.size());
    debug(t);
    cout << t[x - 1] << nl;
}
/*
void solve() {
    int n, k, x; cin >> n >> k >> x;
    vec<str> s(n); cin >> s;
    vec<str> t;
    vi a(n); iota(all(a), 0);
    do {
        vi b = a;
        do {
            str y;
            rep(i, k) y += s[b[i]];
            t.pb(y);
        } while(nextp(b));
    } while(nextc(a, k));
    Sort(t);
    debug(t.size());
    debug(t);
    cout << t[x-1] << nl;
}
*/