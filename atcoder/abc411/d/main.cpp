#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}
struct Node {
    char c;
    int to;
};
static Node Nodes[1000005];
int cn = 0;

void solve() {
    int n, q;
    cin >> n >> q;
    vi pre(n + 1, -1);
    int s = -1;
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (x == 1) {
            pre[y] = s;
        } else if (x == 2) {
            str s;
            cin >> s;
            range(ch, s) {
                Nodes[cn].c = ch;
                Nodes[cn].to = pre[y];
                pre[y] = cn;
                cn++;
            }
        } else {
            s = pre[y];
        }
    }
    str ans;
    while (s != -1) {
        ans += Nodes[s].c;
        s = Nodes[s].to;
    }
    Reverse(ans);
    cout << ans << nl;
}
