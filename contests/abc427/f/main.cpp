#include "template"
#include "fast"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

#define con 1000000

void solve() {
    int n, m; cin >> n >> m;
    int nn = n/2;
    vi a(n); cin >> a;
    unordered_map<int, int> cnt1(con), cnt2(con), cntx1(con), cntx2(con);
    {
        auto dfs = [&](auto&& self, int pre, int k) -> void {
            cnt1[k]++;
            if (pre == nn-1) cntx1[k]++;
            for (int i=pre+2; i<nn; i++) {
                int K = k + a[i]; if (m <= K) K -= m;
                self(self, i, K);
            }
        };
        dfs(dfs, -2, 0);
    }
    {
        auto dfs = [&](auto&& self, int pre, int k, bool flag) -> void {
            cnt2[k]++;
            if (flag) cntx2[k]++;
            for (int i=pre+2; i<n; i++) {
                int K = k + a[i]; if (m <= K) K -= m;
                self(self, i, K, flag|(i==nn));
            }
        };
        dfs(dfs, nn-2, 0, false);
    }
    ll ans = 0;
    range(i, cnt1) {
        int j = m - i.fi; if (m <= j) j -= m;
        if (cnt2.count(j)) {
            ans += (ll)i.se * cnt2[j];
        }
    }
    range(i, cntx1) {
        int j = m - i.fi; if (m <= j) j -= m;
        if (cntx2.count(j)) {
            ans -= (ll)i.se * cntx2[j];
        }
    }
    cout << ans << nl;
}