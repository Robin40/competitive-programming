#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> arr;
int n; ll len;

bool isEnough(ll d) {
    if (0 < arr[0] - d) { return false; }

    if (arr[n-1] + d < len) { return false; }

    for (int i = 0; i < n-1; i++) {
        if (arr[i] + d < arr[i+1] - d) { return false; }
    }

    return true;
}

int main() {
    cin >> n >> len;

    arr.resize(n);
    for (ll &x : arr) {
        cin >> x;
    }
    sort(arr.begin(), arr.end());

    len *= 2;
    for (ll &x : arr) {
        x *= 2;
    }

    ll l = 0, r = len;
    while (l != r) {
        ll m = (l + r) / 2;
        if (isEnough(m)) {
            r = m;
        }
        else {
            l = m+1;
        }
    }
    ll doubleOfAnswer = r;

    cout << doubleOfAnswer / 2;
    if (doubleOfAnswer % 2 == 1) {
        cout << ".5";
    }
    cout << '\n';
}