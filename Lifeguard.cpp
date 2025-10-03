#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  freopen("lifeguards.in", "r", stdin);
  freopen("lifeguards.out", "w", stdout);

  int n;

  cin >> n;

  vector<pair<int, int>> shifts(n);

  vector<int> dp(1001);

  int max_shifts = 0;

  for (int i = 0; i < n; i++) {
    cin >> shifts[i].first >> shifts[i].second;

    for (int j = shifts[i].first; j < shifts[i].second; j++) {
      dp[j] += 1;
    }
  }

  for (int i = 0; i < n; i++) {
    int aux = 0;

    for (int j = shifts[i].first; j < shifts[i].second; j++) {
      dp[j] -= 1;
    }

    for (int j = 0; j < 1001; j++) {
      if (dp[j] > 0) {
        aux++;
      }
    }

    max_shifts = max(max_shifts, aux);

    for (int j = shifts[i].first; j < shifts[i].second; j++) {
      dp[j] += 1;
    }
  }

  cout << max_shifts << endl;

  return 0;
}