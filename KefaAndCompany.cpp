#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Friend {
    ll money, factor;
};

ll d;
vector<Friend> friends;

bool hasInferiorityFeelings(int i, int k) {
    if (k == 0) { return false; }
    return friends[i+k - 1].money - friends[i].money >= d;
}

int main() {
    int n;
    cin >> n >> d;

    friends.resize(n);
    for (Friend &f : friends) {
        cin >> f.money >> f.factor;
    }

    sort(friends.begin(), friends.end(), [](Friend a, Friend b) {
        return a.money < b.money;
    });

    vector<ll> partialSums(n + 1, 0);
    for (int i = 0; i < n; i++) {
        partialSums[i+1] = partialSums[i] + friends[i].factor;
    }

    ll maxFriendship = 0;
    for (int i = 0; i < n; i++) {
        int l = 0, r = n - i;
        while (l != r) {
            int m = (l + r + 1) / 2;
            if (!hasInferiorityFeelings(i, m)) {
                l = m;
            }
            else {
                r = m-1;
            }
        }
        ll totalFriendship = partialSums[i + r] - partialSums[i];

        maxFriendship = max(maxFriendship, totalFriendship);
    }

    cout << maxFriendship << '\n';
}