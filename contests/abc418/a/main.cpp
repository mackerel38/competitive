#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; str s; cin >> n >> s;
    Reverse(s);
    YN(s[0]=='a' && s[1] == 'e' && s[2] == 't');
}