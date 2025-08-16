#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int h, w, k; cin >> h >> w >> k;
    vec<str> s(h); cin >> s;
    int ans = inf;
    rep(t, 1<<(h-1)) {
        int n = __popcount(t);
        int ans2 = n;
        vi cnt(n+1);
        vi tocnt(h);
        int c = 0;
        rep1(i, h-1) {
            if (bit(t, i-1)) c++;
            tocnt[i] = c;
        }
        rep(i, w) {
            bool iscut = false;
            rep(j, h) {
                if(s[j][i] == '1') cnt[tocnt[j]]++;
                if (k < cnt[tocnt[j]]) iscut = true;
            }
            if (iscut) {
                ans2++;
                rep(j, n+1) cnt[j] = 0;
                rep(j, h) if (s[j][i] == '1') cnt[tocnt[j]]++;
                bool ng = false;
                rep(j, h) if (k < cnt[tocnt[j]]) ng = true;
                if (ng) {
                    ans2 = inf;
                    break;
                }
            }
        }
        chmin(ans, ans2);
    }
    cout << ans << nl;
}