#include "template"

int main() {
    IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    bool flag = true;
    if (a+b <= abs(c-d)) flag = false;
    if (c+d <= abs(a-b)) flag = false;
    if (a+b == c+d && b+c == d+a) flag = false;
    YN(flag);
}