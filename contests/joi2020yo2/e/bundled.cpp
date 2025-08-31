/**
 *    author:  mackerel38
 *    created: 31.08.2025 23:15:22
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
#line 3 "library/util/syntax.hpp"
using namespace std;

string syntax(string& s, vector<string>& o, int size=128) {
    vector<int> rankdict(size);
    for (int i=0; i<(int)o.size(); i++) {
        for (auto& j : o[i]) {
            rankdict[j] = i + 1;
        }
    }
    vector<int> ranks(s.size());
    int rank=0;
    for (int i=0; i<(int)s.size(); i++) {
        if (s[i] == '(') {
            rank += (int)o.size() + 1;
            ranks[i] = rank;
        } else if (s[i] == ')') {
            rank -= (int)o.size() + 1;
            ranks[i] = rank;
        } else {
            ranks[i] = rank + rankdict[s[i]];
        }
    }
    string re;
    stack<int> st;
    for (int i=0; i<(int)s.size(); i++) {
        if (s[i]=='(' || s[i]==')') continue;
        if (rankdict[s[i]] == 0) {
            re += s[i];
        } else if (st.empty() || ranks[st.top()]<ranks[i]) {
            st.push(i);
        } else {
            while (!st.empty() && ranks[i]<=ranks[st.top()]) {
                re += s[st.top()];
                st.pop();
            }
            st.push(i);
        }
    }
    while (!st.empty()) {
        re += s[st.top()];
        st.pop();
    }
    return re;
}
#line 3 "contests/joi2020yo2/e/main.cpp"
#define MOD 1'000'000'007
#undef sp
#define rr x.r*y.r
#define rs x.r*y.s
#define rp x.r*y.p
#define sr x.s*y.r
#define ss x.s*y.s
#define sp x.s*y.p
#define pr x.p*y.r
#define ps x.p*y.s
#define pp x.p*y.p
int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

struct rsp {
    ll r, s, p;
};

void solve() {
    int n; cin >> n;
    str s; cin >> s;
    vec<str> op = {"+-", "*"};
    str t = syntax(s, op);
    auto w = [](rsp x, rsp y) -> rsp { return rsp{(rr+rs+sr)%MOD, (ss+sp+ps)%MOD, (pp+pr+rp)%MOD}; };
    auto l = [](rsp x, rsp y) -> rsp { return rsp{(rr+rp+pr)%MOD, (ss+sr+rs)%MOD, (pp+ps+sp)%MOD}; };
    auto d = [](rsp x, rsp y) -> rsp { return rsp{(rr+sp+ps)%MOD, (ss+rp+pr)%MOD, (pp+rs+sr)%MOD}; };
    stack<rsp> st;
    range(i, t) {
        rsp x;
        if (i == 'R') x = {1, 0, 0};
        elif (i == 'S') x = {0, 1, 0};
        elif (i == 'P') x = {0, 0, 1};
        elif (i == '?') x = {1, 1, 1};
        elif (i == '+') {
            rsp y = st.top(); st.pop();
            rsp z = st.top(); st.pop();
            x = w(y, z);
        } elif (i == '-') {
            rsp y = st.top(); st.pop();
            rsp z = st.top(); st.pop();
            x = l(y, z);
        } elif (i == '*') {
            rsp y = st.top(); st.pop();
            rsp z = st.top(); st.pop();
            x = d(y, z);
        }
        st.push(x);
    }
    rsp ans = st.top(); st.pop();
    char tar; cin >> tar;
    if (tar == 'R') cout << ans.r << nl;
    if (tar == 'S') cout << ans.s << nl;
    if (tar == 'P') cout << ans.p << nl;
}
