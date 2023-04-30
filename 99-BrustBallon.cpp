#include <bits/stdc++.h>
using namespace std;

int maxCoins(vector<int> &a) {
    int n = a.size();
    a.push_back(1);
    a.insert(a.begin(), 1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            if (i > j) continue;
            int maxi = INT_MIN;
            for (int ind = i; ind <= j; ind++) {
                int cost = a[i - 1] * a[ind] * a[j + 1] +
                           dp[i][ind - 1] + dp[ind + 1][j];
                maxi = max(maxi, cost);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][n];
}

int main() {

    vector<int> a = {3, 1, 5, 8};
    int ans = maxCoins(a);
    cout << ans << "\n";
}