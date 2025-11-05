#include "template"
#include "autodp/stringdp"
using mint = modint1000000007;

mint naive(const string& s) {
    long long l=0, r=0;
    for (auto& c : s) {
        l<<=1; r<<=1;
        l += (c - '0') % 2;
        r += (c - '0') / 2;
    }
    mint re = 0;
    for (int i=l; i<=r; i++) for (int j=i; j<=r; j++) if (i) if (j%i == (i^j)) re++;
    return re;
}
int main() {
	embed_coefs<mint, naive>(4, -1, -1);
}