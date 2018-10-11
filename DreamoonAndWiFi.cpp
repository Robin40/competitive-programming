#include <bits/stdc++.h>
using namespace std;

int finalPosition(string &sequence) {
    int position = 0;
    for (char c : sequence) {
        assert(c == '+' or c == '-');
        position += (c == '+') - (c == '-');
    }
    return position;
}

string intended, received;
int backtracking(string &current) {
    if (current.length() == intended.length()) {
        return finalPosition(current) == finalPosition(intended);
    }

    int iNext = (int) current.length();
    int ans = 0;

    if (received[iNext] == '?') {
        current += '+';
        ans += backtracking(current);
        current.pop_back();

        current += '-';
        ans += backtracking(current);
        current.pop_back();
    }
    else {
        current += received[iNext];
        ans += backtracking(current);
        current.pop_back();
    }

    return ans;
}

int main() {
    cin >> intended >> received;

    int possibleStrings = 1;
    for (char c : received) {
        if (c == '?') { possibleStrings *= 2; }
    }

    string current;
    int count = backtracking(current);
    double ans = (double) count / possibleStrings;

    cout << setprecision(99) << ans << '\n';
}