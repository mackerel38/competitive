#include "template"

int main() { IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    int N = 1 << n;
    vi p(N); cin >> p;
    auto f = [&](auto&& self, int x, int y) -> void {
        if (y) {
            int Y = 1 << y, s = 1 << (y-1);
            rep(i, Y) {
                if (p[x+Y-1-i] < p[x+i]) {
                    reverse(p.begin()+x, p.begin()+x+Y);
                    break;
                } elif (p[x+i] < p[x+Y-1-i]) {
                    break;
                }
            }
            self(self, x, y-1);
            self(self, x+s, y-1);
        }
    };
    f(f, 0, n);
    cout << p;
}