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
        //for(;;)
        solve();
    } catch (...) {}
    return 0;
}
 
bool powof2(int x) {
    while (x % 2 == 0) x /= 2;
    return x == 1;
}
 
bool bit(int x, int p) {
    return (p >> x) & 1;
}
 
inline int get(veci &a, int x) {
    int ans = 0;
    for (int i = a.size(); x && i >= 0; i--)
        if (a[i] <= x) {
            ans += x / a[i];
            x %= a[i];
        }
    return ans;
}
 
inline void solve() {
    int n; cin >> n;
    veci a(n); cin >> a;
    int q; cin >> q;
    veci m(q); cin >> m;
 
    bool _2i = true;
    for (int x : a) if (!powof2(x)) _2i = false;
    //_2i = false;
    if (_2i) {
        for (int b : m) {
            int lbit = 0;
            int sum = 0, cnt = 0;
            while ((1ll << lbit) <= b && lbit < n)
                lbit++;
            if (lbit == n) {
                sum = a[n - 1] - 1;
                cnt = n - 1 + (b - sum) / a[n - 1];
                sum += ((b - sum) / a[n - 1]) * a[n - 1];
            } else {
                if (b + 1 != 1 << lbit) lbit--;
                sum = (1ll << lbit) - 1;
                cnt = lbit;
            }
            cout << sum << ' ' << cnt << $;
        }
    } else {
        for (int b : m) {
            int cnt = 0;
            int sum = 0;
            for (int i = 1; i <= b; i++) {
                int cur = get(a, i);
                if (cnt < cur) {
                    cnt = cur;
                    sum = i;
                }
            }
            cout << sum << " " << cnt << $;
        }
    }
}
