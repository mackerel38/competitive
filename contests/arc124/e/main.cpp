#include "template"
#include "autodp/sequensedp"
using mint = modint998244353;
vvi enumerate_all_sequences(const vi& ub) {
	int n = ub.size();
	vvi seqs;

	vi seq; // 作成途中の列
	int i = 0; // 列の長さ

	function<void()> rf = [&]() {
		// 完成していれば記録する．
		if (i == n) {
			seqs.push_back(seq);
			return;
		}

		rep(x, ub[i]) {
			seq.push_back(x); i++;
			rf();
			seq.pop_back(); i--;
		}
	};

	rf();

	return seqs;
}


// 愚直
mint naive(const string& s) {
	int n = s.size();

	vi a(n);
	rep(i, n) a[i] = s[i] - '0' + 1;

	auto seqs = enumerate_all_sequences(a);
	range(i, a) i--;

	vvi S;
	range(seq, seqs) {
		vi b(a);
		rep(i, n) {
			b[i] -= seq[i];
			b[(i + 1) % n] += seq[i];
		}
		S.push_back(b);
	}

	uniq(S);

	mint res = 0;
	range(b, S) {
		mint val = 1;
		rep(i, n) val *= b[i];
		res += val;
	}

	return res;
}
int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    // embed_coefs<mint, naive>(4);
    int n; cin >> n;
    vec<mint> a; range(i, a) { int x; cin >> x; i = x; }
    cout << solvedp(a).val() << nl;
}