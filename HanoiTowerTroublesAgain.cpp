#include <bits/stdc++.h>
using namespace std;

bool isSquare(int x) {
    int root = int(sqrt(x) + 0.5 + 1e-8);
    return root * root == x;
}

int greedy(vector<int> &towers, int biggest) {
    int next = biggest + 1;
    for (int &highest : towers) {
        if (not highest or isSquare(highest + next)) {
            highest = next;
            return greedy(towers, next);
        }
    }
    return biggest;
}

int main() {
    int nCases;
    cin >> nCases;
    for (int i = 0; i < nCases; i++) {
        int nTowers;
        cin >> nTowers;

        vector<int> towers(nTowers, 0);
        int ans = greedy(towers, 0);
        cout << ans << '\n';
    }
}