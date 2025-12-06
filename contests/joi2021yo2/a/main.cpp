#include "template"

int main()
{
    IO();
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
}

void solve()
{
    int n, a;
    cin >> n >> a;
    a--;
    str s;
    cin >> s;
    stack<int> l;
    queue<int> r;
    rep(i, n)
    {
        if (s[i] == '#')
        {
            if (i < a)
                l.push(i);
            else
                r.push(i);
        }
    }
    bool right = true;
    ll ans = 0;
    while (l.size() + r.size())
    {
        if (right)
        {
            right = false;
            if (r.empty())
            {
                ans += n - a;
                a = n;
            }
            else
            {
                int x = r.front();
                r.pop();
                ans += x - a;
                a = x;
            }
        }
        else
        {
            right = true;
            if (l.empty())
            {
                ans += a - (-1);
                a = -1;
            }
            else
            {
                int x = l.top();
                l.pop();
                ans += a - x;
                a = x;
            }
        }
    }
    cout << ans << nl;
}