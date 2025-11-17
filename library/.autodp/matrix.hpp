#pragma once
#include <bits/stdc++.h>
using namespace std;
template <class T>
struct Matrix
{
	int n, m;
	vector<vector<T>> v;
	Matrix(int n, int m) : n(n), m(m), v(n, vector<T>(m)) {}
	Matrix(int n) : n(n), m(n), v(n, vector<T>(n))
	{
		for (int i = 0, i_len = int(n); i < i_len; ++i)
			v[i][i] = T(1);
	}
	Matrix(const vector<vector<T>> &a) : n(((int)(a).size())), m(((int)(a[0]).size())), v(a) {}
	Matrix() : n(0), m(0) {}
	Matrix(const Matrix &) = default;
	Matrix &operator=(const Matrix &) = default;
	inline vector<T> const &operator[](int i) const { return v[i]; }
	inline vector<T> &operator[](int i)
	{
		return v[i];
	}
	friend istream &operator>>(istream &is, Matrix &a)
	{
		for (int i = 0, i_len = int(a.n); i < i_len; ++i)
			for (int j = 0, j_len = int(a.m); j < j_len; ++j)
				is >> a.v[i][j];
		return is;
	}
	void push_back(const vector<T> &a)
	{
		{
			if (!(((int)(a).size()) == m))
			{
				vector<char> MLE(1 << 30);
				{
					cout << (MLE.back()) << endl;
					exit(0);
				};
			}
		};
		v.push_back(a);
		n++;
	}
	void pop_back()
	{
		{
			if (!(n > 0))
			{
				vector<char> MLE(1 << 30);
				{
					cout << (MLE.back()) << endl;
					exit(0);
				};
			}
		};
		v.pop_back();
		n--;
	}
	void resize(int n_)
	{
		v.resize(n_);
		n = n_;
	}
	void resize(int n_, int m_)
	{
		n = n_;
		m = m_;
		v.resize(n);
		for (int i = 0, i_len = int(n); i < i_len; ++i)
			v[i].resize(m);
	}
	bool empty() const { return min(n, m) == 0; }
	bool operator==(const Matrix &b) const { return n == b.n && m == b.m && v == b.v; }
	bool operator!=(const Matrix &b) const { return !(*this == b); }
	Matrix &operator+=(const Matrix &b)
	{
		for (int i = 0, i_len = int(n); i < i_len; ++i)
			for (int j = 0, j_len = int(m); j < j_len; ++j)
				v[i][j] += b[i][j];
		return *this;
	}
	Matrix &operator-=(const Matrix &b)
	{
		for (int i = 0, i_len = int(n); i < i_len; ++i)
			for (int j = 0, j_len = int(m); j < j_len; ++j)
				v[i][j] -= b[i][j];
		return *this;
	}
	Matrix &operator*=(const T &c)
	{
		for (int i = 0, i_len = int(n); i < i_len; ++i)
			for (int j = 0, j_len = int(m); j < j_len; ++j)
				v[i][j] *= c;
		return *this;
	}
	Matrix operator+(const Matrix &b) const { return Matrix(*this) += b; }
	Matrix operator-(const Matrix &b) const { return Matrix(*this) -= b; }
	Matrix operator*(const T &c) const { return Matrix(*this) *= c; }
	friend Matrix operator*(const T &c, const Matrix<T> &a) { return a * c; }
	Matrix operator-() const { return Matrix(*this) *= T(-1); }
	vector<T> operator*(const vector<T> &x) const
	{
		vector<T> y(n);
		for (int i = 0, i_len = int(n); i < i_len; ++i)
			for (int j = 0, j_len = int(m); j < j_len; ++j)
				y[i] += v[i][j] * x[j];
		return y;
	}
	friend vector<T> operator*(const vector<T> &x, const Matrix &a)
	{
		vector<T> y(a.m);
		for (int i = 0, i_len = int(a.n); i < i_len; ++i)
			for (int j = 0, j_len = int(a.m); j < j_len; ++j)
				y[j] += x[i] * a[i][j];
		return y;
	}
	Matrix operator*(const Matrix &b) const
	{
		Matrix res(n, b.m);
		for (int i = 0, i_len = int(res.n); i < i_len; ++i)
			for (int k = 0, k_len = int(m); k < k_len; ++k)
				for (int j = 0, j_len = int(res.m); j < j_len; ++j)
					res[i][j] += v[i][k] * b[k][j];
		return res;
	}
	Matrix &operator*=(const Matrix &b)
	{
		*this = *this * b;
		return *this;
	}
	Matrix pow(long long d) const
	{
		Matrix res(n), pow2 = *this;
		while (d > 0)
		{
			if (d & 1)
				res *= pow2;
			pow2 *= pow2;
			d >>= 1;
		}
		return res;
	}
};
template <class T>
vector<pair<int, int>> row_reduced_form(Matrix<T> &A)
{
	int n = A.n, m = A.m;
	vector<pair<int, int>> piv;
	piv.reserve(min(n, m));
	list<int> rjs;
	for (int j = 0, j_len = int(m); j < j_len; ++j)
		rjs.push_back(j);
	for (int i = 0, i_len = int(n); i < i_len; ++i)
	{
		auto it = rjs.begin();
		for (; it != rjs.end(); it++)
			if (A[i][*it] != 0)
				break;
		if (it == rjs.end())
			continue;
		int j = *it;
		rjs.erase(it);
		piv.emplace_back(i, j);
		T Aij_inv = T(1) / A[i][j];
		for (int j2 = int(j), j2_end = int(m - 1); j2 <= j2_end; ++j2)
			A[i][j2] *= Aij_inv;
		for (int i2 = 0, i2_len = int(n); i2 < i2_len; ++i2)
			if (A[i2][j] != 0 && i2 != i)
			{
				T mul = A[i2][j];
				for (int j2 = int(j), j2_end = int(m - 1); j2 <= j2_end; ++j2)
					A[i2][j2] -= A[i][j2] * mul;
			}
	}
	return piv;
}
template <class T>
Matrix<T> inverse_matrix(const Matrix<T> &mat)
{
	int n = mat.n;
	vector<vector<T>> v(n, vector<T>(2 * n));
	for (int i = 0, i_len = int(n); i < i_len; ++i)
		for (int j = 0, j_len = int(n); j < j_len; ++j)
		{
			v[i][j] = mat[i][j];
			if (i == j)
				v[i][n + j] = 1;
		}
	int m = 2 * n;
	int i = 0, j = 0;
	while (i < n && j < m)
	{
		int i2 = i;
		while (i2 < n && v[i2][j] == T(0))
			i2++;
		if (i2 == n)
			return Matrix<T>();
		if (i != i2)
			swap(v[i], v[i2]);
		T vij_inv = T(1) / v[i][j];
		for (int j2 = int(j), j2_end = int(m - 1); j2 <= j2_end; ++j2)
			v[i][j2] *= vij_inv;
		for (int i2 = 0, i2_len = int(n); i2 < i2_len; ++i2)
		{
			if (i2 == i)
				continue;
			T mul = v[i2][j];
			for (int j2 = int(j), j2_end = int(m - 1); j2 <= j2_end; ++j2)
				v[i2][j2] -= v[i][j2] * mul;
		}
		i++;
		j++;
	}
	Matrix<T> mat_inv(n, n);
	for (int i = 0, i_len = int(n); i < i_len; ++i)
		for (int j = 0, j_len = int(n); j < j_len; ++j)
			mat_inv[i][j] = v[i][n + j];
	return mat_inv;
}