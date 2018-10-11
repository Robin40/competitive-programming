#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll inf = 1e18;

int main() {
    int n;
    cin >> n;

    vector<ll> prices(n);
    for (ll &x : prices) {
        cin >> x;
    }
    sort(prices.begin(), prices.end());
    prices.push_back(inf);

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int money;
        cin >> money;

        int l = 0, r = n;
        while (l != r) {
            int m = (l + r) / 2;
            if (money < prices[m]) {
                r = m;
            }
            else {
                l = m+1;
            }
        }
        int ans = r;

        cout << ans << '\n';
    }
}