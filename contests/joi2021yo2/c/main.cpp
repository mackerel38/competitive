#include "template"
#include "segtree"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; ll d, k; cin >> n >> d >> k;
    vec<pair<ll, int>> s;
    rep(i, n) {
        ll x; int y; cin >> y >> x;
        s.pb({x, y});
    }
    Sort(s);
    vll s2(n); rep(i, n) s2[i] = s[i].fi;
    vvll t(2);
    rep(i, n) t[s[i].se-1].pb(i);
    vll dp(n, 1); // dp[i]:= i番目のイベントに必ず参加するとしたときの参加回数の最大値
    vvll t2(2);
    rep(i, n) t2[s[i].se-1].pb(s[i].fi);
    rep(i, n) {
        debug(s[i].fi);
        debug(s[i].se);
        if (s[i].se == 1) {
            { // 移動
                ll T = s[i].fi + 1 + d + k * dp[i];
                debug(T);
                int j = lower_bound(all(t2[1]), T) - t2[1].begin();
                if (j < t2[1].size()) chmax(dp[lower_bound(all(s2), t2[1][j]) - s2.begin()], dp[i]+1);
            }
            { // 待機
                ll T = s[i].fi + 1;
                debug(T);
                int j = lower_bound(all(t2[0]), T) - t2[0].begin();
                if (j < t2[0].size()) chmax(dp[lower_bound(all(s2), t2[0][j]) - s2.begin()], dp[i]+1);
            }
        } else {
            { // 移動
                ll T = s[i].fi + 1 + d + k * dp[i];
                debug(T);
                int j = lower_bound(all(t2[0]), T) - t2[0].begin();
                if (j < t2[0].size()) chmax(dp[lower_bound(all(s2), t2[0][j]) - s2.begin()], dp[i]+1);
            }
            { // 待機
                ll T = s[i].fi + 1;
                debug(T);
                int j = lower_bound(all(t2[1]), T) - t2[1].begin();
                if (j < t2[1].size()) chmax(dp[lower_bound(all(s2), t2[1][j]) - s2.begin()], dp[i]+1);
            }
        }
    }
    debug(dp);
    cout << Max(dp) << nl;
}