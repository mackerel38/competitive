#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    str s; cin >> s;
    if (s == "red") O("SSS");
    elif (s == "blue") O("FFF");
    elif (s == "green") O("MMM");
    else O("Unknown");
}