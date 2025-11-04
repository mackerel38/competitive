#ifndef HIDDEN_IN_VS // 折りたたみ用

// 警告の抑制
#define _CRT_SECURE_NO_WARNINGS

// ライブラリの読み込み
#include <bits/stdc++.h>
using namespace std;

// 型名の短縮
using ll = long long; using ull = unsigned long long; // -2^63 ～ 2^63 = 9e18（int は -2^31 ～ 2^31 = 2e9）
using pii = pair<int, int>;	using pll = pair<ll, ll>;	using pil = pair<int, ll>;	using pli = pair<ll, int>;
using vi = vector<int>;		using vvi = vector<vi>;		using vvvi = vector<vvi>;	using vvvvi = vector<vvvi>;
using vl = vector<ll>;		using vvl = vector<vl>;		using vvvl = vector<vvl>;	using vvvvl = vector<vvvl>;
using vb = vector<bool>;	using vvb = vector<vb>;		using vvvb = vector<vvb>;
using vc = vector<char>;	using vvc = vector<vc>;		using vvvc = vector<vvc>;
using vd = vector<double>;	using vvd = vector<vd>;		using vvvd = vector<vvd>;
template <class T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
using Graph = vvi;

// 定数の定義
const double PI = acos(-1);
int DX[4] = { 1, 0, -1, 0 }; // 4 近傍（下，右，上，左）
int DY[4] = { 0, 1, 0, -1 };
int INF = 1001001001; ll INFL = 4004004003094073385LL; // (int)INFL = INF, (int)(-INFL) = -INF;

// 入出力高速化
struct fast_io { fast_io() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(18); } } fastIOtmp;

// 汎用マクロの定義
#define all(a) (a).begin(), (a).end()
#define sz(x) ((int)(x).size())
#define lbpos(a, x) (int)distance((a).begin(), std::lower_bound(all(a), (x)))
#define ubpos(a, x) (int)distance((a).begin(), std::upper_bound(all(a), (x)))
#define Yes(b) {cout << ((b) ? "Yes\n" : "No\n");}
#define rep(i, n) for(int i = 0, i##_len = int(n); i < i##_len; ++i) // 0 から n-1 まで昇順
#define repi(i, s, t) for(int i = int(s), i##_end = int(t); i <= i##_end; ++i) // s から t まで昇順
#define repir(i, s, t) for(int i = int(s), i##_end = int(t); i >= i##_end; --i) // s から t まで降順
#define repe(v, a) for(const auto& v : (a)) // a の全要素（変更不可能）
#define repea(v, a) for(auto& v : (a)) // a の全要素（変更可能）
#define repb(set, d) for(int set = 0, set##_ub = 1 << int(d); set < set##_ub; ++set) // d ビット全探索（昇順）
#define repis(i, set) for(int i = lsb(set), bset##i = set; i < 32; bset##i -= 1 << i, i = lsb(bset##i)) // set の全要素（昇順）
#define repp(a) sort(all(a)); for(bool a##_perm = true; a##_perm; a##_perm = next_permutation(all(a))) // a の順列全て（昇順）
#define uniq(a) {sort(all(a)); (a).erase(unique(all(a)), (a).end());} // 重複除去
#define EXIT(a) {cout << (a) << endl; exit(0);} // 強制終了
#define inQ(x, y, u, l, d, r) ((u) <= (x) && (l) <= (y) && (x) < (d) && (y) < (r)) // 半開矩形内判定

// 汎用関数の定義
template <class T> inline ll powi(T n, int k) { ll v = 1; rep(i, k) v *= n; return v; }
template <class T> inline bool chmax(T& M, const T& x) { if (M < x) { M = x; return true; } return false; } // 最大値を更新（更新されたら true を返す）
template <class T> inline bool chmin(T& m, const T& x) { if (m > x) { m = x; return true; } return false; } // 最小値を更新（更新されたら true を返す）
template <class T> inline T getb(T set, int i) { return (set >> i) & T(1); }
template <class T> inline T smod(T n, T m) { n %= m; if (n < 0) n += m; return n; } // 非負mod

// 演算子オーバーロード
template <class T, class U> inline istream& operator>>(istream& is, pair<T, U>& p) { is >> p.first >> p.second; return is; }
template <class T> inline istream& operator>>(istream& is, vector<T>& v) { repea(x, v) is >> x; return is; }
template <class T> inline vector<T>& operator--(vector<T>& v) { repea(x, v) --x; return v; }
template <class T> inline vector<T>& operator++(vector<T>& v) { repea(x, v) ++x; return v; }

#endif // 折りたたみ用


#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;

#ifdef _MSC_VER
#include "localACL.hpp"
#endif

//using mint = modint998244353;
using mint = static_modint<(int)1e9+7>;
//using mint = modint; // mint::set_mod(m);

using vm = vector<mint>; using vvm = vector<vm>; using vvvm = vector<vvm>; using vvvvm = vector<vvvm>; using pim = pair<int, mint>;
#endif


#ifdef _MSC_VER // 手元環境（Visual Studio）
#include "local.hpp"
#else // 提出用（gcc）
int mute_dump = 0;
int frac_print = 0;
#if __has_include(<atcoder/all>)
namespace atcoder {
	inline istream& operator>>(istream& is, mint& x) { ll x_; is >> x_; x = x_; return is; }
	inline ostream& operator<<(ostream& os, const mint& x) { os << x.val(); return os; }
}
#endif
inline int popcount(int n) { return __builtin_popcount(n); }
inline int popcount(ll n) { return __builtin_popcountll(n); }
inline int lsb(int n) { return n != 0 ? __builtin_ctz(n) : 32; }
inline int lsb(ll n) { return n != 0 ? __builtin_ctzll(n) : 64; }
inline int msb(int n) { return n != 0 ? (31 - __builtin_clz(n)) : -1; }
inline int msb(ll n) { return n != 0 ? (63 - __builtin_clzll(n)) : -1; }
#define dump(...)
#define dumpel(v)
#define dump_math(v)
#define input_from_file(f)
#define output_to_file(f)
#define Assert(b) { if (!(b)) { vc MLE(1<<30); EXIT(MLE.back()); } } // RE の代わりに MLE を出す
#endif


// 愚直
mint naive(const string& s) {
	int n = 0;
	repe(c, s) n = n * 2 + (c - '0');

	vector<pii> uv;

	repi(a, 0, n) repi(b, 0, n - a) {
		int u = a ^ b;
		int v = a + b;
		if (u <= n) uv.emplace_back(u, v);
	}
	uniq(uv);

	return sz(uv);
}


//【行列】
/*
* Matrix<T>(int n, int m) : O(n m)
*	n×m 零行列で初期化する．
*
* Matrix<T>(int n) : O(n^2)
*	n×n 単位行列で初期化する．
*
* Matrix<T>(vvT a) : O(n m)
*	二次元配列 a[0..n)[0..m) の要素で初期化する．
*
* bool empty() : O(1)
*	行列が空かを返す．
*
* A + B : O(n m)
*	n×m 行列 A, B の和を返す．+= も使用可．
*
* A - B : O(n m)
*	n×m 行列 A, B の差を返す．-= も使用可．
*
* c * A ／ A * c : O(n m)
*	n×m 行列 A とスカラー c のスカラー積を返す．*= も使用可．
*
* A * x : O(n m)
*	n×m 行列 A と n 次元列ベクトル x の積を返す．
*
* x * A : O(n m)（やや遅い）
*	m 次元行ベクトル x と n×m 行列 A の積を返す．
*
* A * B : O(n m l)
*	n×m 行列 A と m×l 行列 B の積を返す．
*
* Mat pow(ll d) : O(n^3 log d)
*	自身を d 乗した行列を返す．
*/
template <class T>
struct Matrix {
	int n, m; // 行列のサイズ（n 行 m 列）
	vector<vector<T>> v; // 行列の成分

	// n×m 零行列で初期化する．
	Matrix(int n, int m) : n(n), m(m), v(n, vector<T>(m)) {}

	// n×n 単位行列で初期化する．
	Matrix(int n) : n(n), m(n), v(n, vector<T>(n)) { rep(i, n) v[i][i] = T(1); }

	// 二次元配列 a[0..n)[0..m) の要素で初期化する．
	Matrix(const vector<vector<T>>& a) : n(sz(a)), m(sz(a[0])), v(a) {}
	Matrix() : n(0), m(0) {}

	// 代入
	Matrix(const Matrix&) = default;
	Matrix& operator=(const Matrix&) = default;

	// アクセス
	inline vector<T> const& operator[](int i) const { return v[i]; }
	inline vector<T>& operator[](int i) {
		// verify : https://judge.yosupo.jp/problem/matrix_product

		// inline を付けて [] でアクセスするとなぜか v[] への直接アクセスより速くなった．
		return v[i];
	}

	// 入力
	friend istream& operator>>(istream& is, Matrix& a) {
		rep(i, a.n) rep(j, a.m) is >> a.v[i][j];
		return is;
	}

	// 行の追加
	void push_back(const vector<T>& a) {
		Assert(sz(a) == m);
		v.push_back(a);
		n++;
	}

	// 行の削除
	void pop_back() {
		Assert(n > 0);
		v.pop_back();
		n--;
	}

	// サイズ変更
	void resize(int n_) {
		v.resize(n_);
		n = n_;
	}

	void resize(int n_, int m_) {
		n = n_;
		m = m_;

		v.resize(n);
		rep(i, n) v[i].resize(m);
	}

	// 空か
	bool empty() const { return min(n, m) == 0; }

	// 比較
	bool operator==(const Matrix& b) const { return n == b.n && m == b.m && v == b.v; }
	bool operator!=(const Matrix& b) const { return !(*this == b); }

	// 加算，減算，スカラー倍
	Matrix& operator+=(const Matrix& b) {
		rep(i, n) rep(j, m) v[i][j] += b[i][j];
		return *this;
	}
	Matrix& operator-=(const Matrix& b) {
		rep(i, n) rep(j, m) v[i][j] -= b[i][j];
		return *this;
	}
	Matrix& operator*=(const T& c) {
		rep(i, n) rep(j, m) v[i][j] *= c;
		return *this;
	}
	Matrix operator+(const Matrix& b) const { return Matrix(*this) += b; }
	Matrix operator-(const Matrix& b) const { return Matrix(*this) -= b; }
	Matrix operator*(const T& c) const { return Matrix(*this) *= c; }
	friend Matrix operator*(const T& c, const Matrix<T>& a) { return a * c; }
	Matrix operator-() const { return Matrix(*this) *= T(-1); }

	// 行列ベクトル積 : O(m n)
	vector<T> operator*(const vector<T>& x) const {
		vector<T> y(n);
		rep(i, n) rep(j, m)	y[i] += v[i][j] * x[j];
		return y;
	}

	// ベクトル行列積 : O(m n)
	friend vector<T> operator*(const vector<T>& x, const Matrix& a) {
		vector<T> y(a.m);
		rep(i, a.n) rep(j, a.m) y[j] += x[i] * a[i][j];
		return y;
	}

	// 積：O(n^3)
	Matrix operator*(const Matrix& b) const {
		// verify : https://judge.yosupo.jp/problem/matrix_product

		Matrix res(n, b.m);
		rep(i, res.n) rep(k, m) rep(j, res.m) res[i][j] += v[i][k] * b[k][j];
		return res;
	}
	Matrix& operator*=(const Matrix& b) { *this = *this * b; return *this; }

	// 累乗：O(n^3 log d)
	Matrix pow(ll d) const {
		// verify : https://judge.yosupo.jp/problem/pow_of_matrix

		Matrix res(n), pow2 = *this;
		while (d > 0) {
			if (d & 1) res *= pow2;
			pow2 *= pow2;
			d >>= 1;
		}
		return res;
	}

#ifdef _MSC_VER
	friend ostream& operator<<(ostream& os, const Matrix& a) {
		rep(i, a.n) {
			os << "[";
			rep(j, a.m) os << a[i][j] << " ]"[j == a.m - 1];
			if (i < a.n - 1) os << "\n";
		}
		return os;
	}
#endif
};


//【行簡約形（行交換なし）】O(n m min(n, m))
/*
* 行基本変形（行交換なし）で n×m 行列 A を行簡約形に変形し，ピボット位置のリストを返す．
*/
template <class T>
vector<pii> row_reduced_form(Matrix<T>& A) {
	int n = A.n, m = A.m;
	
	vector<pii> piv;
	piv.reserve(min(n, m));

	// 未確定の列を記録しておくリスト
	list<int> rjs;
	rep(j, m) rjs.push_back(j);

	rep(i, n) {
		// 第 i 行の係数を左から走査し非 0 を見つける．
		auto it = rjs.begin();
		for (; it != rjs.end(); it++) if (A[i][*it] != 0) break;

		// 第 i 行の全てが 0 なら無視する．
		if (it == rjs.end()) continue;

		// A[i][j] をピボットに選択する．
		int j = *it;
		rjs.erase(it);
		piv.emplace_back(i, j);

		// A[i][j] が 1 になるよう行全体を A[i][j] で割る．
		T Aij_inv = T(1) / A[i][j];
		repi(j2, j, m - 1) A[i][j2] *= Aij_inv;

		// 第 i 行以外の第 j 列の成分が全て 0 になるよう第 i 行を定数倍して減じる．
		rep(i2, n) if (A[i2][j] != 0 && i2 != i) {
			T mul = A[i2][j];
			repi(j2, j, m - 1) A[i2][j2] -= A[i][j2] * mul;
		}
	}

	return piv;
}


//【逆行列】O(n^3)
/*
* n 次正方行列 mat の逆行列を返す（存在しなければ空）
*/
template <class T>
Matrix<T> inverse_matrix(const Matrix<T>& mat) {
	// verify : https://judge.yosupo.jp/problem/inverse_matrix

	int n = mat.n;

	// 元の行列 mat と単位行列を繋げた拡大行列 v を作る．
	vector<vector<T>> v(n, vector<T>(2 * n));
	rep(i, n) rep(j, n) {
		v[i][j] = mat[i][j];
		if (i == j) v[i][n + j] = 1;
	}
	int m = 2 * n;

	// 注目位置を (i, j)（i 行目かつ j 列目）とする．
	int i = 0, j = 0;

	// 拡大行列に対して行基本変形を行い，左側を単位行列にすることを目指す．
	while (i < n && j < m) {
		// 同じ列の下方の行から非 0 成分を見つける．
		int i2 = i;
		while (i2 < n && v[i2][j] == T(0)) i2++;

		// 見つからなかったら全て 0 の列があったので mat は非正則
		if (i2 == n) return Matrix<T>();

		// 見つかったら i 行目とその行を入れ替える．
		if (i != i2) swap(v[i], v[i2]);

		// v[i][j] が 1 になるよう行全体を v[i][j] で割る．
		T vij_inv = T(1) / v[i][j];
		repi(j2, j, m - 1) v[i][j2] *= vij_inv;

		// v[i][j] と同じ列の成分が全て 0 になるよう i 行目を定数倍して減じる．
		rep(i2, n) {
			// i 行目だけは引かない．
			if (i2 == i) continue;

			T mul = v[i2][j];
			repi(j2, j, m - 1) v[i2][j2] -= v[i][j2] * mul;
		}

		// 注目位置を右下に移す．
		i++; j++;
	}

	// 拡大行列の右半分が mat の逆行列なのでコピーする．
	Matrix<T> mat_inv(n, n);
	rep(i, n) rep(j, n) mat_inv[i][j] = v[i][n + j];

	return mat_inv;
}


// 遷移行列の係数を計算し，埋め込み用のコードを出力する．
void embed_coefs(int K) {
	vector<string> ss;

	vector<pii> piv_prv;

	repi(len, 0, INF) {
		dump("----------- len:", len, "--------------");

		// 長さ len の '0', ..., 'K-1' からなる文字列を ss に追加する．
		string s;
		function<void(int)> rf = [&](int i) {
			if (i == len) {
				ss.push_back(s);
				return;
			}

			rep(k, K) {
				s.push_back('0' + k);
				rf(i + 1);
				s.pop_back();
			}
		};
		rf(0);
		dump("ss:"); dump(ss);

		// (i,j) 成分が naive(ss[i] + ss[j]) であるような行列 mat を得る．
		int L = sz(ss);
		Matrix<mint> mat(L, L);
		rep(i, L) rep(j, L) mat[i][j] = naive(ss[i] + ss[j]);
		dump("mat:"); dump(mat);

		// mat に対して行基本変形を行いピボット位置のリスト piv を得る．
		auto piv = row_reduced_form(mat);
		dump("piv:"); dump(piv);

		// rank の更新がなかったら必要な情報は揃ったとみなして打ち切る．
		if (len > 0 && sz(piv) == sz(piv_prv)) {
			int R = sz(piv);
			
			// 選択した行と列をそれぞれ昇順に並べて is, js とする（0 始まり）
			vi is(R), js(R);
			rep(r, R) tie(is[r], js[r]) = piv[r];
			sort(all(js));

			// 基底の変換行列 P を得る．
			Matrix<mint> P(R, R);
			rep(i, R) rep(j, R) P[i][j] = naive(ss[is[i]] + ss[js[j]]);

			// P の逆行列 P_inv を得る．
			auto P_inv = inverse_matrix(P);

			// 各文字に対応する表現行列を得る．
			vector<Matrix<mint>> mats(K, Matrix<mint>(R, R));
			rep(k, K) {
				char c = '0' + k;
				rep(i, R) rep(j, R) mats[k][i][j] = naive(ss[is[i]] + c + ss[js[j]]);
				mats[k] = mats[k] * P_inv;
			}
						
			// 埋め込み用の文字列を出力する．
			auto to_signed_string = [](mint x) {
				int v = x.val();
				int mod = mint::mod();
				if (2 * v > mod) v -= mod;
				return to_string(v);
			};
			string eb = "vector<vector<VTYPE>>matP_ume={";
			rep(i, R) {
				eb += "{";
				rep(j, R) eb += to_signed_string(P[i][j]) + ",";
				eb.pop_back();
				eb += "},";
			}
			eb.pop_back();
			eb += "};\nvector<vector<vector<VTYPE>>>mats_ume={";
			rep(k, K) {
				eb += "{";
				rep(i, R) {
					eb += "{";
					rep(j, R) eb += to_signed_string(mats[k][i][j]) + ",";
					eb.pop_back();
					eb += "},";
				}
				eb.pop_back();
				eb += "},";
			}
			eb.pop_back();
			eb += "};\n";
			cout << eb;

			exit(0);
		}

		piv_prv = move(piv);
	}
}


template <class VTYPE>
VTYPE solve(const string& s) {
	// --------------- embed_coefs() からの出力を貼る ----------------
	vector<vector<VTYPE>>matP_ume = { {1,1,1},{2,4,8},{4,8,18} };
	vector<vector<vector<VTYPE>>>mats_ume = { {{1,0,0},{0,0,1},{-2,-3,4}},{{0,1,0},{-3,0,2},{-6,-2,5}} };
	// --------------------------------------------------------------


	// ここ以降は書き換えなくて良い．
	int R = sz(matP_ume);
	int K = sz(mats_ume);
	Matrix<VTYPE> matP(matP_ume);
	vector<Matrix<VTYPE>> mats(K);
	rep(k, K) mats[k] = Matrix<VTYPE>(mats_ume[k]);

	Matrix<VTYPE> mat(R);
	repe(c, s) mat = mat * mats[c - '0'];
	mat = mat * matP;

	return mat[0][0];
}


int main() {
//	input_from_file("input.txt");
//	output_to_file("output.txt");

	//【方法】
	// 愚直を書いて集めたデータをもとに遷移行列を復元する．

//	embed_coefs(2);

	ll n;
	cin >> n;

	cout << solve<mint>(bitset<60>(n).to_string()) << "\n";
}
