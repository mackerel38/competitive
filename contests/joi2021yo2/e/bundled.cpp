/**
 *    author:  mackerel38
 *    created: 06.12.2025 16:49:39
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
#line 2 "library/util/fast.hpp"
#pragma GCC target("arch=skylake-avx512")
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#line 3 "contests/joi2021yo2/e/main.cpp"
#line 2 "math/sat-solver.hpp"

#line 7 "contests/joi2021yo2/e/main.cpp"
using namespace std;

// https://github.com/not522/CompetitiveProgramming/blob/master/old2/include/math/sat.hpp
class SatSolver {
 private:
  int n, qi;
  vector<vector<pair<int, bool>>> cl;
  vector<vector<int>> w[2];
  vector<int> reason, level, que, activity;

  void enqueue(int v, bool a, int r = -1) {
    assigns[v] = a;
    reason[v] = r;
    level[v] = (que.empty() ? 1 : level[que.back()]);
    que.emplace_back(v);
  }

  void add(const vector<pair<int, bool>> &clause) {
    for (auto l : clause) w[l.second][l.first].emplace_back(cl.size());
    cl.emplace_back(clause);
  }

  void analyze(int confl) {
    int i = que.size(), lv = 1;
    unordered_set<int> used;
    vector<pair<int, bool>> learnt;
    for (int cnt = 0; cnt || used.empty(); --cnt) {
      for (auto q : cl[confl]) {
        if (!used.emplace(q.first).second) continue;
        activity[q.first] += 1e5;
        if (level[q.first] == level[que.back()]) {
          ++cnt;
        } else {
          learnt.emplace_back(q);
          lv = max(lv, level[q.first]);
        }
      }
      while (!used.count(que[--i]))
        ;
      confl = reason[que[i]];
    }
    learnt.emplace_back(que[i], !assigns[que[i]]);
    for (; !que.empty() && level[que.back()] > lv; que.pop_back()) {
      level[que.back()] = 0;
    }
    qi = que.size();
    enqueue(learnt.back().first, learnt.back().second, cl.size());
    add(learnt);
  }

  int propagate() {
    for (; qi < int(que.size()); ++qi) {
      for (int cr : w[!assigns[que[qi]]][que[qi]]) {
        int cnt = 0;
        for (auto &lit : cl[cr]) {
          if (level[lit.first] == 0) {
            activity[lit.first] += 1e3;
            swap(lit, cl[cr][0]);
            ++cnt;
          } else if (assigns[lit.first] == lit.second) {
            swap(lit, cl[cr][0]);
            cnt = -1;
            break;
          }
        }
        if (cnt == 0) return cr;
        if (cnt == 1) enqueue(cl[cr][0].first, cl[cr][0].second, cr);
      }
    }
    return -1;
  }

 public:
  vector<bool> assigns;

  SatSolver(int _n)
      : n(_n), qi(0), reason(n), level(n), activity(n), assigns(n) {
    w[0].resize(n), w[1].resize(n);
  }

  void add_clause(const vector<pair<int, bool>> &clause) { add(clause); }

  void if_then(int v1, bool a1, int v2, bool a2) {
    add(vector{make_pair(v1, !a1), make_pair(v2, a2)});
  }
  void set_val(int v, bool a) { add(vector{make_pair(v, a)}); }

  bool solve() {
    while (true) {
      int confl = propagate();
      if (confl != -1) {
        if (level[que.back()] == 1u) return false;
        for (auto &a : activity) a /= 1.05;
        analyze(confl);
      } else {
        int k = -1;
        for (int i = 0; i < n; ++i) {
          if (level[i] == 0 && (k == -1 || activity[k] < activity[i])) k = i;
        }
        if (k == -1) return true;
        enqueue(k, assigns[k]);
        ++level[k];
      }
    }
  }
};
int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    vi t(n); cin >> t;
    vi a(m), b(m), c(m);
    rep(i, m) { cin >> a[i] >> b[i] >> c[i]; a[i]--; b[i]--; c[i]--; }
    SatSolver sat(n);
    rep(i, n) {
        if (t[i] == 1) sat.set_val(i, true);
        elif (t[i] == 2) sat.set_val(i, false);
    }
    rep(i, m) sat.add_clause({{a[i], false}, {b[i], false}, {c[i], true}});
    bool flag = sat.solve();
    if (!flag) {
      cout << -1 << '\n';
    } else rep(i, n) cout << 2 - sat.assigns[i] << nl;
}
