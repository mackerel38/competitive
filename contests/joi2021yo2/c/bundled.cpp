/**
 *    author:  mackerel38
 *    created: 06.12.2025 15:36:19
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
#line 3 "contests/joi2021yo2/c/main.cpp"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; ll d, k; cin >> n >> d >> k;
    vec<pair<ll, int>> s;
    rep(i, n) {
        ll x; int y; cin >> y >> x;
        s.pb({x, y});
    }
    Sort(s);
    vll s2(n); rep(i, n) s2[i] = s[i].fi;
    vvll t(2);
    rep(i, n) t[s[i].se-1].pb(i);
    vll dp(n, 1); // dp[i]:= i番目のイベントに必ず参加するとしたときの参加回数の最大値
    vvll t2(2);
    rep(i, n) t2[s[i].se-1].pb(s[i].fi);
    rep(i, n) {
        debug(s[i].fi);
        debug(s[i].se);
        if (s[i].se == 1) {
            { // 移動
                ll T = s[i].fi + 1 + d + k * dp[i];
                debug(T);
                int j = lower_bound(all(t2[1]), T) - t2[1].begin();
                if (j < t2[1].size()) chmax(dp[lower_bound(all(s2), t2[1][j]) - s2.begin()], dp[i]+1);
            }
            { // 待機
                ll T = s[i].fi + 1;
                debug(T);
                int j = lower_bound(all(t2[0]), T) - t2[0].begin();
                if (j < t2[0].size()) chmax(dp[lower_bound(all(s2), t2[0][j]) - s2.begin()], dp[i]+1);
            }
        } else {
            { // 移動
                ll T = s[i].fi + 1 + d + k * dp[i];
                debug(T);
                int j = lower_bound(all(t2[0]), T) - t2[0].begin();
                if (j < t2[0].size()) chmax(dp[lower_bound(all(s2), t2[0][j]) - s2.begin()], dp[i]+1);
            }
            { // 待機
                ll T = s[i].fi + 1;
                debug(T);
                int j = lower_bound(all(t2[1]), T) - t2[1].begin();
                if (j < t2[1].size()) chmax(dp[lower_bound(all(s2), t2[1][j]) - s2.begin()], dp[i]+1);
            }
        }
    }
    debug(dp);
    cout << Max(dp) << nl;
}
