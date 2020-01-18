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
    solve();
    return 0;
}
 
inline void solve() {
    int n, m = 0, p = 0;
    cin >> n;
    veci a(n); cin >> a;
    int sum1 = 0, sum2 = 0;
    for (int &x : a)
        sum2 += x;
    m = MAX;
    for (int i = 0; i < n; i++) {
        sum1 += a[i];
        sum2 -= a[i];
        if (abs(sum1 - sum2) < m) {
            m = abs(sum1 - sum2);
            p = i;
        }
    }
    cout << p + 1 << $;
}
