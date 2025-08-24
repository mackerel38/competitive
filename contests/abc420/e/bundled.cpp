/**
 *    author:  mackerel38
 *    created: 24.08.2025 22:08:40
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
template<class T>ostream&operator<<(ostream&s,vector<T>&v){for(auto&i:v)s<<i<<' ';s<<'\n';return s;}
template<class F>long long bsearch(long long ok,long long ng,F&f){while(abs(ok-ng)>1){long long mid=(ok+ng)/2;if(f(mid))ok=mid;else ng=mid;}return ok;}
const int dxy[5]={0,1,0,-1,0};
const int dx[8]={0,1,0,-1,1,1,-1,-1};
const int dy[8]={1,0,-1,0,1,-1,1,-1};
#define nl '\n'
#define sp ' '
#define inf ((1<<30)-(1<<15))
#define INF (1LL<<61)
#define mod 998244353

void IO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(30);
}

void solve();
// poe
#line 3 "library/structure/UnionFind.hpp"
using namespace std;
struct UnionFind {
    int _n;
    vector<int> data;
    UnionFind() = default;
    // n 個の要素からなるUnionFind を構築 O(n)
    UnionFind(int n) : _n(n), data(n, -1) {}
    // 2 つの要素を併合 O(α(n))
    bool merge(int p, int q) {
        p = root(p);
        q = root(q);
        if (p == q) return false;
        if (q < p) swap(p, q);
        data[p] += data[q];
        data[q] = p;
        return true;
    }
    // 親要素を取得 O(α(n))
    int root(int p) {
        assert(0 <= p && p < _n);
        if (data[p] < 0) {
            return p;
        } else {
            data[p] = root(data[p]);
            return data[p];
        }
    }
    // 親要素を取得 O(α(n))
    int operator[](int p) {
        return root(p);
    }
    // 2 つの要素が同じ集合に含まれるか判定 O(α(n))
    bool same(int p, int q) {
        return root(p) == root(q);
    }
    // 要素が属する集合の大きさを返す O(α(n))
    int size(int p) {
        return -data[root(p)];
    }
    // UnionFind の連結成分のvector を返す O(n α(n))
    vector<vector<int>> groups() {
        vector<vector<int>> re(_n);
        for (int i=0; i<_n; i++) re[root(i)].push_back(i);
        re.erase(remove_if(re.begin(), re.end(), [](vector<int>& v){ return v.empty(); }), re.end());
        return re;
    }
};
#line 3 "contests/abc420/e/main.cpp"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    UnionFind uf(n);
    vi a(n);
    vi b(n, 1);
    while (q--) {
        int x; cin >> x;
        if (x == 1) {
            int y, z; cin >> y >> z; y--; z--;
            if (uf.same(y, z)) continue;
            int t = a[uf.root(y)] + a[uf.root(z)];
            uf.merge(y, z); a[uf.root(y)] = t;
        } elif (x == 2) {
            int y; cin >> y; y--;
            a[uf.root(y)] += b[y];
            b[y] *= -1;
        } else {
            int y; cin >> y; y--;
            YN(a[uf.root(y)]);
        }
        debug(a);
    }
}
