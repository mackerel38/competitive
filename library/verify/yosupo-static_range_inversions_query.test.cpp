#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"
#include "template"
#include "BIT"
#include "Mo"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vi a(n); cin >> a;
    vi b = a;
    uniq(b);
    rep(i, n) a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    int m = b.size();
    vll ans(q);
    Mo mo(n);
    vpi queries(q);
    rep(i, q) {
        int l, r; cin >> l >> r;
        queries[i] = {l, r};
        mo.add(l, r);
    }
    BIT<int> seg(m);
    ll cnt = 0;
    auto add_left = [&](int i) {
        cnt += seg.sum(0, a[i]);
        seg.add(a[i], 1);
    };
    auto add_right = [&](int i) {
        cnt += seg.sum(a[i] + 1, m);
        seg.add(a[i], 1);
    };
    auto erase_left = [&](int i) {
        seg.add(a[i], -1);
        cnt -= seg.sum(0, a[i]);
    };
    auto erase_right = [&](int i) {
        seg.add(a[i], -1);
        cnt -= seg.sum(a[i] + 1, m);
    };
    auto out = [&](int i) {
        ans[i] = cnt;
    };
    mo.build(add_left, add_right, erase_left, erase_right, out);
    range(i, ans) cout << i << nl;
}