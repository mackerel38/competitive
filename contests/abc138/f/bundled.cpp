/**
 *    author:  mackerel38
 *    created: 05.11.2025 12:14:30
**/

#line 2 "library/util/template.hpp"
#ifdef poe
#define debug(x) cerr<<#x<<": "<<x<<endl
#else
#define debug(x)
#endif
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
using pi=pair<int,int>;
using pll=pair<ll,ll>;
using str=string;
template<class T>using vec=vector<T>;
using vi=vec<int>;using vvi=vec<vi>;using vvvi=vec<vvi>;using vvvvi=vec<vvvi>;using vvvvvi=vec<vvvvi>;
using vll=vec<ll>;using vvll=vec<vll>;using vvvll=vec<vvll>;using vvvvll=vec<vvvll>;using vvvvvll=vec<vvvvll>;
using vpi=vec<pi>;using vvpi=vec<vpi>;using vvvpi=vec<vvpi>;using vvvvpi=vec<vvvpi>;using vvvvvpi=vec<vvvvpi>;
using vpll=vec<pll>;using vvpll=vec<vpll>;using vvvpll=vec<vvpll>;using vvvvpll=vec<vvvpll>;using vvvvvpll=vec<vvvvpll>;
template<class T>using pq=priority_queue<T,vector<T>>;
template<class T>using pqg=priority_queue<T,vector<T>,greater<T>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define per(i,n) for(int i=(int)(n)-1;0<=i;i--)
#define per1(i,n) for(int i=(int)(n);0<i;i--)
#define range(i,x) for(auto&i:x)
#define range2(i,j,x) for(auto&[i,j]:x)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define Sort(x) sort((x).begin(),(x).end())
#define troS(x) sort((x).rbegin(),(x).rend())
#define Reverse(x) reverse((x).begin(),(x).end())
#define uniq(x) sort((x).begin(),(x).end());(x).erase(unique((x).begin(),(x).end()),(x).end())
#define nextp(x) next_permutation((x).begin(),(x).end())
#define nextc(x,k) next_combination((x).begin(),(x).end(),k)
#define bit(x,i) (((x)>>(i))&1)
#define pf push_front
#define pb push_back
#define df pop_front
#define db pop_back
#define fi first
#define se second
#define elif else if
#define Yes cout<<"Yes"<<'\n'
#define No cout<<"No"<<'\n'
#define YN(x) cout<<((x)?"Yes":"No")<<'\n'
#define O(x) cout<<(x)<<'\n'
#define ismid(a,b,c) ((a)<=(b)&&(b)<(c))
template<class S,class T>bool chmin(S&a,T b){if(a>b){a=b;return true;}return false;}
template<class S,class T>bool chmax(S&a,T b){if(a<b){a=b;return true;}return false;}
template<class T>bool next_combination(T l,T r,int k){T m=l+k;if(l==r||l==m||r==m)return false;T t=m;while(l!=t){t--;if(*t<*(r-1)){T d=m;while(*t>=*d)d++;iter_swap(t,d);rotate(t+1,d+1,r);rotate(m,m+(r-d)-1,r);return true;}}rotate(l,m,r);return false;}
template<class T>T Min(T a,T b){return a<b?a:b;}
template<class T,class...Args>T Min(T a,T b,Args...args){return Min(Min(a,b),args...);}
template<class T>T Max(T a,T b){return a>b?a:b;}
template<class T,class...Args>T Max(T a,T b,Args...args){return Max(Max(a,b),args...);}
template<class T>T Sum(T a){return a;}
template<class T,class... Args>T Sum(T a,Args... args){return a+Sum(args...);}
template<class T>T Max(const vector<T>&v){return *max_element(all(v));}
template<class T>T Min(const vector<T>&v){return *min_element(all(v));}
template<class T>T Sum(const vector<T>&v){return accumulate(all(v),T(0));}
template<class S,class T>T Max(const pair<S,T>&p){return max(p.first,p.second);}
template<class S,class T>T Min(const pair<S,T>&p){return min(p.first,p.second);}
template<class S,class T>T Sum(const pair<S,T>&p){return p.first+p.second;}
template<class S,class T>istream&operator>>(istream&s,pair<S,T>&p){s>>p.first>>p.second;return s;}
template<class S,class T>ostream&operator<<(ostream&s,pair<S,T>&p){s<<p.first<<' '<<p.second<<'\n';return s;}
template<class T>istream&operator>>(istream&s,vector<T>&v){for(auto&i:v)s>>i;return s;}
template<class T>ostream&operator<<(ostream&s,vector<T>&v){for(int i=0;i<(int)v.size();i++)s<<v[i]<<" \n"[i==(int)v.size()-1];return s;}
const int dxy[5]={0,1,0,-1,0};
const int dx[8]={0,1,0,-1,1,1,-1,-1};
const int dy[8]={1,0,-1,0,1,-1,1,-1};
#define nl '\n'
#define sp ' '
const int inf = (1<<30)-(1<<15);
const ll INF = 1LL<<61;
const ll mod = 998244353;
const ll MOD = 1000000007;
const ld EPS = 1e-9;
const ld PI = acos(-1);

void IO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(30);
}

void solve();
// poe
#line 3 "library/autodp/string/construct.hpp"
using namespace std;
#line 3 "library/autodp/matrix.hpp"
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
#line 1 "library/atcoder/modint.hpp"



#line 6 "library/atcoder/modint.hpp"
#include <type_traits>

#ifdef _MSC_VER
#include <intrin.h>
#endif

#line 1 "library/atcoder/internal_math.hpp"



#line 5 "library/atcoder/internal_math.hpp"

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param m `1 <= m`
// @return x mod m
constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

// Fast modular multiplication by barrett reduction
// Reference: https://en.wikipedia.org/wiki/Barrett_reduction
// NOTE: reconsider after Ice Lake
struct barrett {
    unsigned int _m;
    unsigned long long im;

    // @param m `1 <= m`
    explicit barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

    // @return m
    unsigned int umod() const { return _m; }

    // @param a `0 <= a < m`
    // @param b `0 <= b < m`
    // @return `a * b % m`
    unsigned int mul(unsigned int a, unsigned int b) const {
        // [1] m = 1
        // a = b = im = 0, so okay

        // [2] m >= 2
        // im = ceil(2^64 / m)
        // -> im * m = 2^64 + r (0 <= r < m)
        // let z = a*b = c*m + d (0 <= c, d < m)
        // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64 + c*r + d*im
        // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64 + m * (m + 1) < 2^64 * 2
        // ((ab * im) >> 64) == c or c + 1
        unsigned long long z = a;
        z *= b;
#ifdef _MSC_VER
        unsigned long long x;
        _umul128(z, im, &x);
#else
        unsigned long long x =
            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);
#endif
        unsigned long long y = x * _m;
        return (unsigned int)(z - y + (z < y ? _m : 0));
    }
};

// @param n `0 <= n`
// @param m `1 <= m`
// @return `(x ** n) % m`
constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    unsigned long long y = safe_mod(x, m);
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}

// Reference:
// M. Forisek and J. Jancina,
// Fast Primality Testing for Integers That Fit into a Machine Word
// @param n `0 <= n`
constexpr bool is_prime_constexpr(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = pow_mod_constexpr(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}
template <int n> constexpr bool is_prime = is_prime_constexpr(n);

// @param b `1 <= b`
// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g
constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};

    // Contracts:
    // [1] s - m0 * a = 0 (mod b)
    // [2] t - m1 * a = 0 (mod b)
    // [3] s * |m1| + t * |m0| <= b
    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b

        // [3]:
        // (s - t * u) * |m1| + t * |m0 - m1 * u|
        // <= s * |m1| - t * u * |m1| + t * (|m0| + |m1| * u)
        // = s * |m1| + t * |m0| <= b

        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    // by [3]: |m0| <= b/g
    // by g != b: |m0| < b/g
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}

// Compile time primitive root
// @param m must be prime
// @return primitive root (and minimum in now)
constexpr int primitive_root_constexpr(int m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; (long long)(i)*i <= x; i += 2) {
        if (x % i == 0) {
            divs[cnt++] = i;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        divs[cnt++] = x;
    }
    for (int g = 2;; g++) {
        bool ok = true;
        for (int i = 0; i < cnt; i++) {
            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = primitive_root_constexpr(m);

// @param n `n < 2^32`
// @param m `1 <= m < 2^32`
// @return sum_{i=0}^{n-1} floor((ai + b) / m) (mod 2^64)
unsigned long long floor_sum_unsigned(unsigned long long n,
                                      unsigned long long m,
                                      unsigned long long a,
                                      unsigned long long b) {
    unsigned long long ans = 0;
    while (true) {
        if (a >= m) {
            ans += n * (n - 1) / 2 * (a / m);
            a %= m;
        }
        if (b >= m) {
            ans += n * (b / m);
            b %= m;
        }

        unsigned long long y_max = a * n + b;
        if (y_max < m) break;
        // y_max < m * (n + 1)
        // floor(y_max / m) <= n
        n = (unsigned long long)(y_max / m);
        b = (unsigned long long)(y_max % m);
        std::swap(m, a);
    }
    return ans;
}

}  // namespace internal

}  // namespace atcoder


#line 1 "library/atcoder/internal_type_traits.hpp"



#line 7 "library/atcoder/internal_type_traits.hpp"

namespace atcoder {

namespace internal {

#ifndef _MSC_VER
template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;

#else

template <class T> using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;

#endif

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  // namespace internal

}  // namespace atcoder


#line 14 "library/atcoder/modint.hpp"

namespace atcoder {
namespace internal {

struct modint_base {};
struct static_modint_base : modint_base {};

template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

}  // namespace internal

template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
struct static_modint : internal::static_modint_base {
    using mint = static_modint;

  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    static_modint() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    static_modint(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    static_modint(T v) {
        _v = (unsigned int)(v % umod());
    }

    int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        if (prime) {
            assert(_v);
            return pow(umod() - 2);
        } else {
            auto eg = internal::inv_gcd(_v, m);
            assert(eg.first == 1);
            return eg.second;
        }
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static constexpr unsigned int umod() { return m; }
    static constexpr bool prime = internal::is_prime<m>;
};

template <int id> struct dynamic_modint : internal::modint_base {
    using mint = dynamic_modint;

  public:
    static int mod() { return (int)(bt.umod()); }
    static void set_mod(int m) {
        assert(1 <= m);
        bt = internal::barrett(m);
    }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    dynamic_modint() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    dynamic_modint(T v) {
        long long x = (long long)(v % (long long)(mod()));
        if (x < 0) x += mod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    dynamic_modint(T v) {
        _v = (unsigned int)(v % mod());
    }

    int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v += mod() - rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        _v = bt.mul(_v, rhs._v);
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        auto eg = internal::inv_gcd(_v, mod());
        assert(eg.first == 1);
        return eg.second;
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static internal::barrett bt;
    static unsigned int umod() { return bt.umod(); }
};
template <int id> internal::barrett dynamic_modint<id>::bt(998244353);

using modint998244353 = static_modint<998244353>;
using modint1000000007 = static_modint<1000000007>;
using modint = dynamic_modint<-1>;

namespace internal {

template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<dynamic_modint<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  // namespace internal

}  // namespace atcoder


#line 6 "library/autodp/string/construct.hpp"
using namespace atcoder;

template <class CTYPE, auto NAIVE>
void embed_coefs(int K, int len_max=1001001001, int lb_max=1001001001)
{
	if (len_max == -1) len_max = 1001001001;
	if (lb_max == -1) lb_max = 1001001001;
	vector<string> ss{""};
	int idx = 0;
	vector<pair<int, int>> piv_prv;
	for (int len = int(0), len_end = int(1001001001); len <= len_end; ++len)
	{
		int L = ((int)(ss).size());
		int LB = min(L, lb_max);
		Matrix<CTYPE> mat(L, LB);
		for (int i = 0, i_len = int(L); i < i_len; ++i)
			for (int j = 0, j_len = int(LB); j < j_len; ++j)
				mat[i][j] = NAIVE(ss[i] + ss[j]);
		auto piv = row_reduced_form(mat);
		if (len == len_max || (((int)(piv).size()) > 0 && ((int)(piv).size()) == ((int)(piv_prv).size())))
		{
			int R = ((int)(piv).size());
			vector<int> is(R), js(R);
			for (int r = 0, r_len = int(R); r < r_len; ++r)
				tie(is[r], js[r]) = piv[r];
			sort((js).begin(), (js).end());
			Matrix<CTYPE> P(R, R);
			for (int i = 0, i_len = int(R); i < i_len; ++i)
				for (int j = 0, j_len = int(R); j < j_len; ++j)
					P[i][j] = NAIVE(ss[is[i]] + ss[js[j]]);
			auto P_inv = inverse_matrix(P);
			vector<Matrix<CTYPE>> mats(K, Matrix<CTYPE>(R, R));
			for (int k = 0, k_len = int(K); k < k_len; ++k)
			{
				char c = '0' + k;
				for (int i = 0, i_len = int(R); i < i_len; ++i)
					for (int j = 0, j_len = int(R); j < j_len; ++j)
						mats[k][i][j] = NAIVE(ss[is[i]] + c + ss[js[j]]);
				mats[k] = mats[k] * P_inv;
			}
			auto to_signed_string = [](CTYPE x)
			{
				int v = x.val();
				int mod = CTYPE::mod();
				if (2 * v > mod)
					v -= mod;
				return to_string(v);
			};
			ofstream ofs("/home/mackerel38/competitive/library/autodp/string/generated.hpp");
			string eb = "";
			eb += "#pragma once\n";
			eb += "#include <bits/stdc++.h>\n";
			eb += "using namespace std;\n";
			eb += "\n";
			eb += "template <class VTYPE>\n";
			eb += "VTYPE solvedp(const string &s) {\n";
			eb += "\tconstexpr int DIM = ";
			eb += to_string(R);
			eb += ";\n";
			eb += "\tconstexpr int COL = ";
			eb += to_string(K);
			eb += ";\n";
			eb += "\tVTYPE matAs[COL][DIM][DIM] = {";
			for (int k = 0, k_len = int(K); k < k_len; ++k)
			{
				eb += "{";
				for (int i = 0, i_len = int(R); i < i_len; ++i)
				{
					eb += "{";
					for (int j = 0, j_len = int(R); j < j_len; ++j)
						eb += to_signed_string(mats[k][i][j]) + ",";
					eb.pop_back();
					eb += "},";
				}
				eb.pop_back();
				eb += "},";
			}
			eb.pop_back();
			eb += "};\n";
			eb += "\tVTYPE vecQ[DIM] = {";
			for (int i = 0, i_len = int(R); i < i_len; ++i)
				eb += to_signed_string(P[i][0]) + ",";
			eb.pop_back();
			eb += "};\n";
			eb += "\tarray<VTYPE, DIM> dp;\n";
			eb += "\tdp[0] = 1;\n";
			eb += "\tfor (int i=1; i<DIM; i++) dp[i] = 0;\n";
			eb += "\tauto apply = [&](const array<VTYPE, DIM> &x, int col) {\n";
			eb += "\t\tarray<VTYPE, DIM> z;\n";
			eb += "\t\tfor (int j=0; j<DIM; j++) {\n";
			eb += "\t\t\tz[j] = 0;\n";
			eb += "\t\t\tfor (int i=0; i<DIM; i++) z[j] += x[i]*matAs[col][i][j];\n";
			eb += "\t\t}\n";
			eb += "\t\treturn z;\n";
			eb += "\t};\n";
			eb += "\tfor (const auto &c : s) dp = apply(dp, c-'0');\n";
			eb += "\tVTYPE res = 0;\n";
			eb += "\tfor (int i=0; i<DIM; i++) res += vecQ[i]*dp[i];\n";
			eb += "\treturn res;\n";
			eb += "}\n";
			ofs << eb << endl;
			exit(0);
		}
		int nidx = ((int)(ss).size());
		for (int i = int(idx), i_end = int(nidx - 1); i <= i_end; ++i)
			for (int k = 0, k_len = int(K); k < k_len; ++k)
			{
				ss.push_back(ss[i]);
				ss.back().push_back('0' + k);
			}
		idx = nidx;
		piv_prv = move(piv);
	}
}
#line 3 "library/autodp/string/generated.hpp"
using namespace std;

template <class VTYPE>
VTYPE solvedp(const string &s) {
	constexpr int DIM = 6;
	constexpr int COL = 4;
	VTYPE matAs[COL][DIM][DIM] = {{{1,0,0,0,0,0},{0,0,0,1,0,0},{0,0,1,0,0,0},{0,-3,0,4,0,0},{0,-2,0,3,2,-1},{0,-5,0,5,0,1}},{{0,0,0,0,0,0},{0,0,0,0,1,0},{0,0,0,0,0,0},{0,-3,0,3,1,0},{0,0,0,0,1,0},{0,-5,0,4,1,1}},{{0,1,0,0,0,0},{0,0,0,0,0,1},{0,0,1,0,1,0},{0,-3,0,3,0,1},{0,-2,0,2,2,0},{0,-5,0,3,0,3}},{{0,0,1,0,0,0},{0,0,0,-1,1,1},{0,0,1,0,0,0},{0,-3,0,2,1,1},{0,0,0,-1,1,1},{0,-5,0,2,1,3}}};
	VTYPE vecQ[DIM] = {0,1,1,2,2,4};
	array<VTYPE, DIM> dp;
    dp[0] = 1;
	for (int i=1; i<DIM; i++) dp[i] = 0;
	auto apply = [&](const array<VTYPE, DIM> &x, int col) {
		array<VTYPE, DIM> z;
		for (int j=0; j<DIM; j++) {
			z[j] = 0;
			for (int i=0; i<DIM; i++) z[j] += x[i]*matAs[col][i][j];
		}
		return z;
	};
	for (const auto &c : s) dp = apply(dp, c-'0');
	VTYPE res = 0;
	for (int i=0; i<DIM; i++) res += vecQ[i]*dp[i];
	return res;
}

#line 3 "contests/abc138/f/main.cpp"
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
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
	// embed_coefs<mint, naive>(4, -1, -1);
	long long l, r; cin >> l >> r;
    string s;
    for (int i=60; 0<=i; i--) {
        s += '0' + (((l>>i)&1) + ((r>>i)&1)*2);
    }
    cout << solvedp<mint>(s).val() << '\n';
}
