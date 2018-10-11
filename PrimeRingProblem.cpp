#include <bits/stdc++.h>
using namespace std;

int n;

bool isPrime(int x) {
    for (int d = 2; d*d <= x; d++) {
        if (x % d == 0) { return false; }
    }
    return true;
}

bool isValidSolution(vector<int> &solution) {
    for (int i = 0; i < n; i++) {
        if (not isPrime(solution[i] + solution[(i + 1) % n])) {
            return false;
        }
    }
    return true;
}

void printVector(vector<int> &solution) {
    for (int i = 0; i < n; i++) {
        if (i != 0) { cout << ' '; }
        cout << solution[i];
    }
    cout << '\n';
}

void backtracking(vector<int> &current, set<int> &used) {
    if (current.size() == n) {
        if (isValidSolution(current)) {
            printVector(current);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (not isPrime(current.back() + i)) {
            continue;
        }

        if (not used.count(i)) {
            current.push_back(i);
            used.insert(i);

            backtracking(current, used);

            current.pop_back();
            used.erase(i);
        }
    }
}

int main() {
    for (int caseNumber = 1; cin >> n; caseNumber++) {
        if (caseNumber != 1) { cout << '\n'; }
        cout << "Case " << caseNumber << ":\n";

        vector<int> current; current.push_back(1);
        set<int> used; used.insert(1);
        backtracking(current, used);
    }
}