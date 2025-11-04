#pragma once
#include "autodp/template.hpp"
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