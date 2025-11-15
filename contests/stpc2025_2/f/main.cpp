#include "template"
#include "atcoder/convolution"
using namespace atcoder;
using mint = modint998244353;

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    str s; cin >> s;
    if (n == 1) {
        cout << s << nl;
        return;
    }
    queue<vec<mint>> q;
    mint k = 10;
    rep1(i, n-1) {
        vec<mint> x = {mint(1), k};
        q.push(x);
        k *= k;
    }
    while (1 < (int)q.size()) {
        auto x = q.front(); q.pop();
        auto y = q.front(); q.pop();
        auto z = convolution(x, y);
        q.push(z);
    }
    auto ans = q.front();
    mint re = 0;
    Reverse(s);
    rep(i, n) re += ans[i] * (s[i] - '0');
    cout << re.val() << nl;
}