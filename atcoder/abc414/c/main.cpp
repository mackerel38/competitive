#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int a; ll n; cin >> a >> n;
    ll ans = 0;
    rep1(i, 1000000) {
        str s = to_string(i);
        str t = s.substr(0, s.size()-1); Reverse(t);
        s += t;
        ll x = stoll(s);
        ll y = x;
        if (x > n) continue;
        str S = "";
        bool flag = false;
        while (x) {
            S += char(x % a + '0');
            x /= a;
        }
        str T = S;
        Reverse(T);
        if (S == T) ans += y;
    }
    rep1(i, 1000000) {
        str s = to_string(i);
        str t = s.substr(0, s.size()); Reverse(t);
        s += t;
        ll x = stoll(s);
        ll y = x;
        if (x > n) continue;
        str S = "";
        bool flag = false;
        while (x) {
            S += char(x % a + '0');
            x /= a;
        }
        str T = S;
        Reverse(T);
        if (S == T) ans += y;
    }
    cout << ans << nl;
}