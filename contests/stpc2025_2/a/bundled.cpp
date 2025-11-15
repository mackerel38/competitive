/**
 *    author:  mackerel38
 *    created: 08.11.2025 17:44:18
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
#line 2 "contests/stpc2025_2/a/main.cpp"

int main() {
    IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    int n, k; cin >> n >> k;
    if (false) {
        if (n == 1) {
            Yes;
        } elif (n == 2 && k == 1) {
            Yes;
            cout << 1 << sp << 2 << nl;
        } elif (n == 3 && k == 2) {
            Yes;
            cout << 1 << sp << 2 << nl;
            cout << 2 << sp << 3 << nl;
        } elif (n == 4 && k == 2) {
            Yes;
            cout << 1 << sp << 2 << nl;
            cout << 2 << sp << 3 << nl;
            cout << 3 << sp << 4 << nl;
        } elif (n == 5 && k == 2) {
            Yes;
            cout << 1 << sp << 2 << nl;
            cout << 1 << sp << 3 << nl;
            cout << 1 << sp << 4 << nl;
            cout << 1 << sp << 5 << nl;
        } elif (n == 5 && k == 3) {
            Yes;
            cout << 1 << sp << 2 << nl;
            cout << 2 << sp << 3 << nl;
            cout << 3 << sp << 4 << nl;
            cout << 4 << sp << 5 << nl;
        } else {
            No;
        }
        return;
    }
    if (n == 1) {
        Yes;
        return;
    }
    if (n == 2 && k == 1) {
        Yes;
        cout << 1 << sp << 2 << nl;
        return;
    }
    if (k == 1) {
        No;
        return;
    }
    if (n == k) {
        if (n < 7) {
            No;
        } else {
            Yes;
            cout << 1 << sp << 4 << nl;
            cout << 2 << sp << 3 << nl;
            cout << 3 << sp << 4 << nl;
            rep(i, n-4) {
                cout << i+4 << sp << i+5 << nl;
            }
        }
        return;
    }
    if (k == 2) {
        Yes;
        rep1(i, n-1) {
            cout << 1 << sp << i+1 << nl;
        }
        return;
    }
    if (n == 4 && k == 3) {
        No;
        return;
    }
    if (k == 3) {
        if (n%2 == 0) {
            Yes;
            cout << 1 << sp << n/2+1 << nl;
            rep(t, 2) {
                int T = t * (n/2);
                cout << T+1 << sp << T+2 << nl;
                rep(i, n/2-2) {
                    cout << T+2 << sp << T+i+3 << nl;
                }
            }
        } else {
            Yes;
            rep(i, n/2) {
                cout << 1 << sp << 2*i+2 << nl;
                cout << 2*i+2 << sp << 2*i+3 << nl;
            }
        }
        return;
    }
    Yes;
    rep1(i, k-1) {
        cout << i << sp << i+1 << nl;
    }
    rep1(i, n-k) {
        cout << 2 << sp << i+k << nl;
    }
}
