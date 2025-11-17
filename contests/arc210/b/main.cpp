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
    bipq<ll> left, mid, right;
    range(i, a) left.push(a[i]);
    range(i, b) left.push(b[i]);
    ll ans = Sum(a) + Sum(b);
    while (N < left.size()) {
        mid.push(left.top_max());
        ans -= left.top_max();
        left.pop_max();
    }
    while (right.size() < N) {
        right.push(mid.top_max());
        ans += mid.top_max();
        mid.pop_max();
    }
    auto eraseadd = [&](ll erase, ll add) {
        if (erase <= left.top_max()) {
            left.erase(erase);
            ans -= erase;
            ans += mid.top_min();
            left.push(mid.top_min());
            mid.pop_min();
        } elif (right.top_min() <= erase) {
            right.erase(erase);
            ans -= erase;
            ans += mid.top_max();
            right.push(mid.top_max());
            mid.pop_max();
        } else {
            mid.erase(erase);
        }
        if (add <= left.top_max()) {
            left.push(add);
            ans += add;
            ans -= left.top_max();
            mid.push(left.top_max());
            left.pop_max();
        } elif (right.top_min() <= add) {
            right.push(add);
            ans += add;
            ans -= right.top_min();
            mid.push(right.top_min());
            right.pop_min();
        } else {
            mid.push(add);
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