/**
 *    author:  mackerel38
 *    created: 29.11.2025 22:39:19
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
template<class T>using pairs=pair<T, T>;
template<class T>using pq=priority_queue<T,vector<T>>;
template<class T>using pqg=priority_queue<T,vector<T>,greater<T>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define loop(i, l, r) for (int i=(int)(l); i<(int)(r); i++)
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
template<class T>ostream&operator<<(ostream&s,vector<T>&v){for(int i=0;i<(int)v.size();i++){s<<v[i];if(i!=(int)v.size()-1)s<<' ';}s<<'\n';return s;}
const int dxy[5]={0,1,0,-1,0};
const int dx[8]={0,1,0,-1,1,1,-1,-1};
const int dy[8]={1,0,-1,0,1,-1,1,-1};
const char nl='\n';
const char sp=' ';
const int inf=(1<<30)-(1<<15);
const ll INF=1LL<<61;
const ll mod=998244353;
const ll MOD=1000000007;
const ld EPS=1e-9;
const ld PI=acos(-1);

void IO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(30);
}

void solve();
// poe
#line 3 "library/structure/segtree.hpp"
using namespace std;
// op(op(a, b), c) = op(a, op(b, c)) が成り立つ必要がある(結合律)
template<class S, auto op, auto e>
struct segtree {
    int _n, size;
    vector<S> data;
    segtree() = default;
    // 大きさn のセグ木を構築 O(n)
    explicit segtree(int n) : _n(n) { build(vector<S>(n, e())); }
    // 大きさv.size() のセグ木を構築 O(n)
    explicit segtree(const vector<S>& v) : _n(v.size()) { build(v); }
    void build(const vector<S>& v) {
        size = __bit_ceil((unsigned int)_n);
        data.assign(2 * size, e());
        for (int i=0; i<_n; i++) data[size+i] = v[i];
        for (int i=size-1; 0<i; i--) update(i);
    }
    // p 番目の要素をx にする O(log n)
    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        data[p] = x;
        for (p>>=1; 0<p; p>>=1) update(p);
    }
    // p 番目の要素を取得する O(1)
    S get(int p) const {
        assert(0 <= p && p < _n);
        return data[size+p];
    }
    // p 番目の要素を取得する O(1)
    S operator[](int p) const { return get(p); }
    // [l, r) の区間クエリに答える O(log n)
    S prod(int l, int r) const {
        assert(0<=l && l<=r && r<=_n);
        S ll = e(), rr = e();
        l += size;
        r += size;
        while (l < r) {
            if (l & 1) ll = op(ll, data[l++]);
            if (r & 1) rr = op(data[--r], rr);
            l >>= 1;
            r >>= 1;
        }
        return op(ll, rr);
    }
    // [0, _n) のクエリに答える O(1)
    S all_prod() const { return data.size() > 1 ? data[1] : e(); }
    // [0, _n) の区間の値を取得する O(n)
    vector<S> values() const {
        vector<S> re(_n);
        for (int i=0; i<_n; i++) re[i] = data[size+i];
        return re;
    }
    void update(int p) { data[p] = op(data[2*p], data[2*p+1]); }
    // f(op([l, r)))==true となる最大のr を返す
    template <class F>
    int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, data[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, data[l]))) {
                        sm = op(sm, data[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, data[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }
    // f(op([l, r)))==true となる最小のl を返す
    template <class F>
    int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(data[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(data[r], sm))) {
                        sm = op(data[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(data[r], sm);
        } while ((r & -r) != r);
        return 0;
    }
};
#line 3 "library/math/modint.hpp"
using namespace std;

template <long long modint_MOD>
struct modint {
    long long val;
    constexpr modint(long long x=0) noexcept {
        x %= modint_MOD;
        if (x < 0) x += modint_MOD;
        val = x;
    }
    explicit constexpr operator long long() const noexcept { return val; }
    template<typename Int>
    static constexpr long long adjust(Int x) noexcept {
        static_assert(std::is_integral<Int>::value, "Int must be integral");
        __int128 t = static_cast<__int128>(x);
        __int128 m = static_cast<__int128>(modint_MOD);
        t %= m;
        if (t < 0) t += m;
        return static_cast<long long>(t);
    }
    constexpr modint operator+(const modint& x) const noexcept { return modint(*this) += x; }
    constexpr modint operator-(const modint& x) const noexcept { return modint(*this) -= x; }
    constexpr modint operator*(const modint& x) const noexcept { return modint(*this) *= x; }
    constexpr modint operator/(const modint& x) const noexcept { return modint(*this) /= x; }
    constexpr modint& operator+=(const modint& x) noexcept {
        if (modint_MOD <= (val += x.val)) val -= modint_MOD;
        return *this;
    }
    constexpr modint& operator-=(const modint& x) noexcept {
        if ((val -= x.val) < 0) val += modint_MOD;
        return *this;
    }
    constexpr modint& operator*=(const modint& x) noexcept {
        __int128 t = (__int128)val * x.val;
        val = (long long)(t % modint_MOD);
        if (val < 0) val += modint_MOD;
        return *this;
    }
    constexpr modint& operator/=(modint x) noexcept {
        *this *= x.inv();
        return *this;
    }
    constexpr modint operator-() const noexcept { return modint() - *this; }
    constexpr modint& operator++() noexcept { return *this += 1; }
    constexpr modint& operator--() noexcept { return *this -= 1; }
    constexpr modint operator++(int) noexcept { modint tmp = *this; ++*this; return tmp; }
    constexpr modint operator--(int) noexcept { modint tmp = *this; --*this; return tmp; }
    constexpr bool operator==(const modint& x) const noexcept { return val == x.val; }
    constexpr bool operator!=(const modint& x) const noexcept { return val != x.val; }
    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>
    constexpr modint& operator+=(Int x) noexcept {
        long long y = adjust<Int>(x);
        if (modint_MOD <= (val += y)) val -= modint_MOD;
        return *this;
    }
    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>
    constexpr modint& operator-=(Int x) noexcept {
        long long y = adjust<Int>(x);
        if ((val -= y) < 0) val += modint_MOD;
        return *this;
    }
    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>
    constexpr modint& operator*=(Int x) noexcept {
        long long y = adjust<Int>(x);
        __int128 t = (__int128)val * y;
        val = (long long)(t % modint_MOD);
        if (val < 0) val += modint_MOD;
        return *this;
    }
    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>
    constexpr modint& operator/=(Int x) noexcept {
        modint t = modint(adjust<Int>(x));
        *this /= t;
        return *this;
    }
    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>
    friend constexpr modint operator+(const modint& a, Int b) noexcept { modint t = a; t += b; return t; }
    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>
    friend constexpr modint operator+(Int a, const modint& b) noexcept { modint t = b; t += a; return t; }
    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>
    friend constexpr modint operator-(const modint& a, Int b) noexcept { modint t = a; t -= b; return t; }
    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>
    friend constexpr modint operator-(Int a, const modint& b) noexcept { modint t = modint(adjust<Int>(a)); t -= b; return t; }
    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>
    friend constexpr modint operator*(const modint& a, Int b) noexcept { modint t = a; t *= b; return t; }
    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>
    friend constexpr modint operator*(Int a, const modint& b) noexcept { modint t = b; t *= a; return t; }
    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>
    friend constexpr modint operator/(const modint& a, Int b) noexcept { modint t = a; t /= b; return t; }
    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>
    friend constexpr modint operator/(Int a, const modint& b) noexcept { modint t = modint(adjust<Int>(a)); t /= b; return t; }
    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>
    friend constexpr bool operator==(const modint& a, Int b) noexcept { return a.val == adjust<Int>(b); }
    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>
    friend constexpr bool operator==(Int a, const modint& b) noexcept { return adjust<Int>(a) == b.val; }
    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>
    friend constexpr bool operator!=(const modint& a, Int b) noexcept { return !(a == b); }
    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>
    friend constexpr bool operator!=(Int a, const modint& b) noexcept { return !(a == b); }
    friend constexpr istream& operator>> (istream& i, modint& x) { long long y; i >> y; x = modint(y); return i; }
    friend constexpr ostream& operator<< (ostream& o, const modint& x) { o << x.val; return o; }
    constexpr modint pow(long long n) const noexcept {
        if (n < 0) return inv().pow(-n);
        modint x = *this, re = 1;
        while (0 < n){
            if (n & 1) re *= x;
            x *= x;
            n >>= 1;
        }
        return re;
    }
    constexpr modint inv() const noexcept { return pow(modint_MOD - 2); }
};

template <long long modint_MOD>
struct factor {
    vector<modint<modint_MOD>> fac, ifac;
    factor(int n) : fac(n+1), ifac(n+1) {
        fac[0] = 1;
        for (int i=1; i<=n; i++) fac[i] = fac[i-1] * i;
        ifac[n] = fac[n].inv();
        for (int i=n; 1<=i; i--) ifac[i-1] = ifac[i] * i;
    }
    modint<modint_MOD> P(int n, int r) const noexcept { return (r<0 || n<r) ? 0 : fac[n] * ifac[n-r]; }
    modint<modint_MOD> C(int n, int r) const noexcept { return (r<0 || n<r) ? 0 : P(n, r) * ifac[r]; }
    modint<modint_MOD> H(int n, int r) const noexcept { return (n==0 && r==0) ? 1 : C(n+r-1, r); }
};
#line 4 "contests/abc434/g/main.cpp"
using mint = modint<998244353>;
#line 2 "library/Nyaan/rbst/treap.hpp"

#line 2 "library/Nyaan/misc/rng.hpp"

#line 2 "library/Nyaan/internal/internal-seed.hpp"

#line 4 "library/Nyaan/internal/internal-seed.hpp"
using namespace std;

namespace internal {
unsigned long long non_deterministic_seed() {
  unsigned long long m =
      chrono::duration_cast<chrono::nanoseconds>(
          chrono::high_resolution_clock::now().time_since_epoch())
          .count();
  m ^= 9845834732710364265uLL;
  m ^= m << 24, m ^= m >> 31, m ^= m << 35;
  return m;
}
unsigned long long deterministic_seed() { return 88172645463325252UL; }

// 64 bit の seed 値を生成 (手元では seed 固定)
// 連続で呼び出すと同じ値が何度も返ってくるので注意
// #define RANDOMIZED_SEED するとシードがランダムになる
unsigned long long seed() {
#if defined(NyaanLocal) && !defined(RANDOMIZED_SEED)
  return deterministic_seed();
#else
  return non_deterministic_seed();
#endif
}

}  // namespace internal
#line 4 "library/Nyaan/misc/rng.hpp"

namespace my_rand {
using i64 = long long;
using u64 = unsigned long long;

// [0, 2^64 - 1)
u64 rng() {
  static u64 _x = internal::seed();
  return _x ^= _x << 7, _x ^= _x >> 9;
}

// [l, r]
i64 rng(i64 l, i64 r) {
  assert(l <= r);
  return l + rng() % u64(r - l + 1);
}

// [l, r)
i64 randint(i64 l, i64 r) {
  assert(l < r);
  return l + rng() % u64(r - l);
}

// choose n numbers from [l, r) without overlapping
vector<i64> randset(i64 l, i64 r, i64 n) {
  assert(l <= r && n <= r - l);
  unordered_set<i64> s;
  for (i64 i = n; i; --i) {
    i64 m = randint(l, r + 1 - i);
    if (s.find(m) != s.end()) m = r - i;
    s.insert(m);
  }
  vector<i64> ret;
  for (auto& x : s) ret.push_back(x);
  sort(begin(ret), end(ret));
  return ret;
}

// [0.0, 1.0)
double rnd() { return rng() * 5.42101086242752217004e-20; }
// [l, r)
double rnd(double l, double r) {
  assert(l < r);
  return l + rnd() * (r - l);
}

template <typename T>
void randshf(vector<T>& v) {
  int n = v.size();
  for (int i = 1; i < n; i++) swap(v[i], v[randint(0, i + 1)]);
}

}  // namespace my_rand

using my_rand::randint;
using my_rand::randset;
using my_rand::randshf;
using my_rand::rnd;
using my_rand::rng;
#line 4 "library/Nyaan/rbst/treap.hpp"

template <typename Node>
struct TreapBase {
  using Ptr = Node *;
  template <typename... Args>
  inline Ptr my_new(Args... args) {
    return new Node(args...);
  }
  Ptr make_tree() { return nullptr; }

  // for avoiding memory leak, activate below
  /*
  using Ptr = shared_ptr<Node>;
  template <typename... Args>
  inline Ptr my_new(Args... args) {
    return make_shared<Node>(args...);
  }
  Ptr make_tree() {return Ptr();}
  */

  int size(Ptr t) const { return count(t); }

  Ptr merge(Ptr l, Ptr r) {
    if (!l || !r) return l ? l : r;
    if (l->pr >= r->pr) {
      push(l);
      l->r = merge(l->r, r);
      return update(l);
    } else {
      push(r);
      r->l = merge(l, r->l);
      return update(r);
    }
  }

  pair<Ptr, Ptr> split(Ptr t, int k) {
    if (!t) return {nullptr, nullptr};
    push(t);
    if (k <= count(t->l)) {
      auto s = split(t->l, k);
      t->l = s.second;
      return {s.first, update(t)};
    } else {
      auto s = split(t->r, k - count(t->l) - 1);
      t->r = s.first;
      return {update(t), s.second};
    }
  }

  Ptr build(const vector<decltype(Node::key)> &v) {
    int n = v.size();
    vector<Ptr> ps;
    ps.reserve(n);
    for (int i = 0; i < n; i++) ps.push_back(my_new(v[i]));
    vector<int> p(n, -1), st;
    for (int i = 0; i < n; i++) {
      int prv = -1;
      while (!st.empty() && ps[i]->pr > ps[st.back()]->pr) {
        prv = st.back();
        st.pop_back();
      }
      if (prv != -1) p[prv] = i;
      if (!st.empty()) p[i] = st.back();
      st.push_back(i);
    }
    int root = -1;
    for (int i = 0; i < n; i++) {
      if (p[i] != -1) {
        if (i < p[i]) {
          ps[p[i]]->l = ps[i];
        } else {
          ps[p[i]]->r = ps[i];
        }
      } else
        root = i;
    }
    dfs(ps[root]);
    return ps[root];
  }

  template <typename... Args>
  void insert(Ptr &t, int k, const Args &...args) {
    auto x = split(t, k);
    t = merge(merge(x.first, my_new(args...)), x.second);
  }

  void erase(Ptr &t, int k) {
    auto x = split(t, k);
    t = merge(x.first, split(x.second, 1).second);
  }

 protected:
  void dfs(Ptr r) {
    if (r->l) dfs(r->l);
    if (r->r) dfs(r->r);
    update(r);
  }

  inline int count(const Ptr t) const { return t ? t->cnt : 0; }

  virtual void push(Ptr) {}

  virtual Ptr update(Ptr) = 0;
};

template <typename T, typename E>
struct LazyReversibleTreapNode {
  using Treap = TreapBase<LazyReversibleTreapNode>;
  typename Treap::Ptr l, r;
  T key, sum;
  E lazy;
  int cnt;
  uint32_t pr;
  bool rev;

  LazyReversibleTreapNode(const T &t = T(), const E &e = E())
      : l(),
        r(),
        key(t),
        sum(t),
        lazy(e),
        cnt(1),
        pr(my_rand::rng()),
        rev(false) {}
};

template <typename T, typename E, T (*f)(T, T), T (*g)(T, E), E (*h)(E, E),
          T (*ts)(T)>
struct LazyReversibleTreap : TreapBase<LazyReversibleTreapNode<T, E>> {
  using Node = LazyReversibleTreapNode<T, E>;
  using base = TreapBase<LazyReversibleTreapNode<T, E>>;
  using base::merge;
  using base::split;
  using typename base::Ptr;

  LazyReversibleTreap() = default;

  void toggle(Ptr t) {
    if (!t) return;
    swap(t->l, t->r);
    t->sum = ts(t->sum);
    t->rev ^= true;
  }

  T fold(Ptr &t, int a, int b) {
    auto x = split(t, a);
    auto y = split(x.second, b - a);
    auto ret = sum(y.first);
    t = merge(x.first, merge(y.first, y.second));
    return ret;
  }

  void reverse(Ptr &t, int a, int b) {
    auto x = split(t, a);
    auto y = split(x.second, b - a);
    toggle(y.first);
    t = merge(x.first, merge(y.first, y.second));
  }

  void apply(Ptr &t, int a, int b, const E &e) {
    auto x = split(t, a);
    auto y = split(x.second, b - a);
    propagate(y.first, e);
    t = merge(x.first, merge(y.first, y.second));
  }

 protected:
  inline T sum(const Ptr t) const { return t ? t->sum : T(); }

  Ptr update(Ptr t) override {
    push(t);
    t->cnt = 1;
    t->sum = t->key;
    if (t->l) t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);
    if (t->r) t->cnt += t->r->cnt, t->sum = f(t->sum, t->r->sum);
    return t;
  }

  void push(Ptr t) override {
    if (t->rev) {
      if (t->l) toggle(t->l);
      if (t->r) toggle(t->r);
      t->rev = false;
    }
    if (t->lazy != E()) {
      if (t->l) propagate(t->l, t->lazy);
      if (t->r) propagate(t->r, t->lazy);
      t->lazy = E();
    }
  }

  void propagate(Ptr t, const E &x) {
    t->lazy = h(t->lazy, x);
    t->key = g(t->key, x);
    t->sum = g(t->sum, x);
  }
};

/**
 * @brief 遅延伝搬反転可能Treap
 */
#line 6 "contests/abc434/g/main.cpp"

vector<mint> po;
struct T {
    int l;
    mint v;
};
using E = char;
T f(T a, T b) { return T{a.l+b.l, a.v*po[b.l]+b.v}; }
T g(T a, E b) { return a; }
E h(E a, E b) {return E{}; }
T ts(T a) { return T{}; }
using Treap = LazyReversibleTreap<T, E, f, g, h, ts>;
Treap treap;

struct S {
    int B;
    Treap::Ptr root;
};
S op(S a, S b) {
    if (a.root == nullptr && a.B == 0) return b;
    if (b.root == nullptr && b.B == 0) return a;
    S re;
    int A = treap.size(a.root);
    debug(A);
    int d = min(b.B, A);
    Treap::Ptr left, del;
    if (a.root != nullptr) {
        auto p = treap.split(a.root, A - d);
        left = p.fi; del = p.se;
    }
    else left = del = nullptr;
    delete del;
    re.root = treap.merge(left, b.root);
    re.B = a.B + b.B - d;
    return re;
}
S e() { return S{0, nullptr};}

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}
void solve() {
    int n, q; cin >> n >> q;
    str s; cin >> s;
    po.assign(n+10, mint(0)); po[0] = mint(1);
    rep1(i, po.size()-1) po[i] = 10 * po[i-1];
    vector<S> a(n);
    rep(i, n) {
        if (s[i] == 'B') a[i] = S{1, nullptr};
        else a[i] = S{0, treap.build(vec<T>{T{1, s[i]-'0'}})};
    }
    segtree<S, op, e> seg(a);
    while (q--) {
        int x; cin >> x;
        if (x == 1) {
            int y; char c; cin >> y >> c; y--;
            if (c == 'B') seg.set(y, S{1, nullptr});
            else seg.set(y, S{0, treap.build(vec<T>{T{1, c-'0'}})});
        } else {
            int l, r; cin >> l >> r; l--;
            S re = seg.prod(l, r);
            int len = treap.size(re.root);
            if (len == 0) {
                cout << -1 << nl;
            } else {
                cout << re.root->sum.v << nl;
            }
        }
    }
}

// teap のサイズがnより大きくなる...
