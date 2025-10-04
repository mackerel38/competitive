/**
 *    author:  mackerel38
 *    created: 04.10.2025 22:15:55
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
#line 2 "contests/abc426/e/main.cpp"

int main() {
    IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}
#define eps 1e-18L
ld dist(pair<ld, ld>&x, pair<ld, ld>& y) { return (x.fi-y.fi)*(x.fi-y.fi)+(x.se-y.se)*(x.se-y.se); }
pair<ld, ld> sim(pair<ld, ld>& x, pair<ld, ld>& y, ld d, ld t) {
    if (d <= t+eps) {
        return y;
    } elif (t <= eps) {
        return x;
    } else {
        return {
            ((d-t)*x.fi + t*y.fi) / d, 
            ((d-t)*x.se + t*y.se) / d
        };
    }
}


void solve() {
    pair<ld, ld> ps, pg, qs, qg; cin >> ps >> pg >> qs >> qg;
    ld d1 = sqrtl(dist(ps, pg));
    ld d2 = sqrtl(dist(qs, qg));
    if (d1 > d2) {
        swap(d1, d2);
        swap(ps, qs);
        swap(pg, qg);
    }
    ld ans = 1e100;
    auto solvemin = [&](ld x, ld y, ld z, ld l, ld r) -> ld {
        ld vL = x*l*l + y*l + z;
        ld vR = x*r*r + y*r + z;
        ld re = min(vL, vR);
        if (fabsl(x) > eps) {
            ld t = -y / (2*x);
            if (t > l+eps && t+eps < r) {
                ld v = x*t*t + y*t + z;
                chmin(re, v);
            }
        }
        return re;
    };
    ld sx = ps.fi - qs.fi;
    ld sy = ps.se - qs.se;
    ld vpx = (pg.fi - ps.fi) / d1;
    ld vpy = (pg.se - ps.se) / d1;
    ld vqx = (qg.fi - qs.fi) / d2;
    ld vqy = (qg.se - qs.se) / d2;
    {
        ld dx = vpx - vqx;
        ld dy = vpy - vqy;
        ans = min(ans, solvemin(dx*dx + dy*dy, 2.L * (sx*dx + sy*dy), sx*sx + sy*sy, .0L, d1));
    }
    if (d1+eps < d2) {
        sx = pg.fi - qs.fi;
        sy = pg.se - qs.se;
        ld dx = -vqx;
        ld dy = -vqy;
        ans = min(ans, solvemin(dx*dx + dy*dy, 2.L * (sx*dx + sy*dy), sx*sx + sy*sy, d1, d2));
    }
    {
        ld d = dist(pg, qg);
        chmin(ans, d);
    }
    cout << sqrtl(ans) << nl;
}
