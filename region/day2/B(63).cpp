#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
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
        solve();
    } catch (...) {}
    return 0;
}
 
 
int f;
bool ok(int a, int b, int c, int d) {
    if (a == f || f == b)
        return false;
    return (c < a) && (d < b);
}
 
inline void solve() {
    int ans = 0, n;
    cin >> n >> f;
    for (int x = 1; x < n; x++) {
        for (int y = 1; y < n - x; y++) {
            for (int p = 1; p <= n / 2; p++) {
                int up = n - p * x;
                int down = y + p;
                if (up % down == 0) {
                    int q = up / down;
                    ans += ok(x + q, y + p, x, y);
                }
            }
        }
    }
    cout << ans << $;
}
