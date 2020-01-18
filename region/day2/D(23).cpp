#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define all(a) a.begin(),a.end()
#define $ '\n'
#define MAX LONG_LONG_MAX
#define MIN LONG_LONG_MIN
typedef vector<int> veci;
template <class T> ostream &operator << (ostream &o, const vector<T> &a) {
    for (const T &x : a) o << x << ' ';
    return o;
}
template <class T> istream &operator >> (istream &i, vector<T> &a) {
    for (T &x : a) i >> x;
    return i;
}
inline void solve();
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    try {
        //for(;;)
        solve();
    } catch (...) {}
    return 0;
}
 
int n, q;
veci a, e;
 
int psn(int ps) {
    if (ps >= 0) return ps % n;
    else return n - ps;
}
 
bool freepos(int p) {
    int sum1 = 0, sum2 = 0;
    for (int i = p - 3; i < p; i++) sum1 += !!e[psn(i)];
    for (int i = p + 1; i <= p + 3; i++) sum2 += !!e[psn(i)];
    return (sum1 != 3 && sum2 != 3) && !e[psn(p)];
}
 
bool bit (int x, int p){
    return (x >> p) & 1;
}
 
int sol(veci &a) {
    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        int cur = 0;
        for (int i = 0; i < n; i++)
            cur += bit(mask, i) * a[i];
        bool ok = true;
        for (int i = 0; i < n; i++) {
            int s = 0;
            for (int j = 0; j < 4; j++)
                s += bit(mask, psn(i + j));
            if (s > 3) ok = false;
        }
        if (ok)
            ans = max(ans, cur);
    }
    return ans;
}
 
inline void solve() {
    cin >> n;
    a = veci(n);
    cin >> a;
    cin >> q;
    cout << sol(a) << $;
    while (q--) {
        int s, v;
        cin >> s >> v;
        a[s - 1] = v;
        cout << sol(a) << $;
    }
}
