#include "template"
#include "bipq"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    ll n, m, q; cin >> n >> m >> q;
    ll N = n / 2;
    vll a(n), b(m); cin >> a >> b;
    multiset<ll> left, mid, right;
    ll ans = 0;
    vll c = a; range(i, b) c.pb(i);
    Sort(c);
    rep(i, N) {
        left.insert(c[i]);
        ans += c[i];
    }
    loop(i, N, N+m) {
        mid.insert(c[i]);
    }
    loop(i, N+m, n+m) {
        right.insert(c[i]);
        ans += c[i];
    }
    auto eraseadd = [&](ll erase, ll add) {
        if (erase <= *left.rbegin()) {
            left.erase(left.find(erase));
            ans -= erase;
            ans += *mid.begin();
            left.insert(*mid.begin());
            mid.erase(mid.find(*mid.begin()));
        } elif (*right.begin() <= erase) {
            right.erase(right.find(erase));
            ans -= erase;
            ans += *mid.rbegin();
            right.insert(*mid.rbegin());
            mid.erase(mid.find(*mid.rbegin()));
        } else {
            mid.erase(mid.find(erase));
        }
        if (add <= *left.rbegin()) {
            left.insert(add);
            ans += add;
            ans -= *left.rbegin();
            mid.insert(*left.rbegin());
            left.erase(left.find(*left.rbegin()));
        } elif (*right.begin() <= add) {
            right.insert(add);
            ans += add;
            ans -= *right.begin();
            mid.insert(*right.begin());
            right.erase(right.find(*right.begin()));
        } else {
            mid.insert(add);
        }
    };
    while (q--) {
        int x, y, z; cin >> x >> y >> z; y--;
        if (x == 1) {
            eraseadd(a[y], z);
            a[y] = z;
        } else {
            eraseadd(b[y], z);
            b[y] = z;
        }
        cout << ans << nl;
    }
}