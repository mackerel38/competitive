/**
 *    author:  mackerel38
 *    created: 28.06.2025 09:48:32
**/

#line 2 "/workspaces/competitive/library/util/template.hpp"
#ifdef poe
#define debug(x) cerr<<#x<<": "<<x<<endl
#else
#define debug(x)
// #pragma GCC target("arch=skylake-avx512")
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
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
#line 3 "/workspaces/competitive/library/graph/graphtemplate.hpp"
using namespace std;
// 辺の構造体 edge(from, to, cost, id)
template<class T = int>
struct edge {
    int from, to;
    T cost;
    int id;
};
// 頂点の構造体 vector<edge<T>>
template<class T = int>
using edges = vector<edge<T>>;
// グラフの構造体 graph<T, directed, weighted> 
template <class T = int, bool directed = false, bool weighted = false>
struct graph {
    bool isdirected, isweighted;
    edges<T> _edges;
    vector<edges<T>> data;
    T sumcost;
    graph() = default;
    // 頂点数 n のグラフを作成する
    graph(int n) : isdirected(directed), isweighted(weighted), data(n), sumcost(T{}) {}
    // from から to へ辺を追加する
    void add_edge(int from, int to, T cost = 1, int id = -1) {
        if (id == -1) id = _edges.size();
        data[from].push_back(edge<T>(from, to, cost, id));
        _edges.push_back(edge<T>(from, to, cost, id));
        if (!isdirected) {
            data[to].push_back(edge<T>(to, from, cost, id));
        }
        sumcost += cost;
    }
    // 辺を追加する
    void add_edge(edge<T> _e) {
        add_edge(_e.from, _e.to, _e.cost, _e.id);
    }
    // 標準入力から辺を読み込む
    void read(int m, int indexed = 1) {
        for (int i=0; i<m; i++) {
            int from, to;
            T cost = 1;
            cin >> from >> to;
            if (isweighted) cin >> cost;
            add_edge(from - indexed, to - indexed, cost);
        }
    }
    // 頂点数を返す
    int size() {
        return data.size();
    }
    // 頂点を返す
    edges<T> operator[](int k) {
        return data[k];
    }
    vector<int> path_to_vertex(edges<T>& _e) {
        vector<int> re;
        if (_e.size() == 0) {
            return re;
        }
        if (_e.size() == 1) {
            re.push_back(_e[0].from);
            re.push_back(_e[0].to);
            return re;
        }
        int x=_e[0].from,y=_e[0].to;
        if (x==_e[1].to || x == _e[1].from) swap(x, y);
        re.push_back(x);
        for (int i=1; i<_e.size(); i++) {
            re.push_back(y);
            x = _e[i].to;
            if (x == y) x = _e[i].from;
            swap(x, y);
        }
        return re;
    }
    edges<T> vetex_to_path (vector<int>& v){
        edges<T> re;
        for (int i=0; i+1<v.size(); i++) {
            for (auto& _e : this[v[i]]) {
                if (_e.to == v[i+1]) {
                    re.push_back(_e);
                    break;
                }
            }
        }
        return re;
    }
};
#line 4 "/workspaces/competitive/library/graph/warshallfloyd.hpp"
using namespace std;
// グラフの全点間最短経路を求める O(n^3)
template <class T>
vector<vector<T>> warshallfloyd(vector<vector<T>>& g) {
    vector<vector<T>> d = g;
    for (int k=0; k<(int)g.size(); k++) {
        for (int i=0; i<(int)g.size(); i++) {
            for (int j=0; j<(int)g.size(); j++) {
                if (d[i][k] < numeric_limits<T>::max()/2 && d[k][j] < numeric_limits<T>::max()/2) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
    return d;
}
// グラフの全点間最短経路を求める O(n^3)
template<class T = int, bool directed = false, bool weighted = true>
vector<vector<T>> warshallfloyd(graph<T, directed, weighted>& g) {
    vector<vector<T>> d(g.size(), vector<T>(g.size(), numeric_limits<T>::max()));
    for (int i=0; i<(int)g.size(); i++) {
        d[i][i] = T{};
        for (auto& _e : g[i]) {
            d[i][_e.to] = _e.cost;
        }
    }
    return warshallfloyd(d);
}
#line 3 "main.cpp"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    ll n, m, l; cin >> n >> m >> l;
    graph<ll, false, true> g(n); g.read(m);
    vvll d = warshallfloyd(g);
    graph<ll, false, false> g2(n);
    rep(i, n) rep(j, n) {
        if (d[i][j] <= l) {
            g2.add_edge(i, j);
        }
    }
    vvll d2 = warshallfloyd(g2);
    int q; cin >> q;
    while (q--) {
        int x, y; cin >> x >> y; x--; y--;
        if (INF <= d2[x][y]) cout << -1 << nl;
        else cout << d2[x][y]-1 << nl;
    }
}
