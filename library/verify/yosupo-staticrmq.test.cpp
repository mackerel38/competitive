#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "template"
#include "sparsetable"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q;
    cin >> n >> q;
    vi a(n);
    cin >> a;
    sparsetable<int, [](int a, int b) { return min(a, b); }> st(a);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << st.prod(l, r) << nl;
    }
}