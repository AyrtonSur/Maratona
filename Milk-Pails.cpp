#include <bits/stdc++.h>

using namespace std;

void fast_io()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int main() {
  fast_io();

  freopen("pails.in", "r", stdin);
  freopen("pails.out", "w", stdout);

  int x, y, m;

  cin >> x >> y >> m;

  bool dp[m + 1];

  for (int i = 1; i <= m; i++) {
    dp[i] = false;
  }

  dp[0] = true;

  for (int i = 1; i <= m; i++) {
    if ((i - x >= 0) && dp[i - x]) {
      dp[i] = true;
    }
    
    if ((i - y) >= 0 && dp[i - y]) {
      dp[i] = true;
    }
  }

  int res;

  for (int i = m; i >= 0; i--) {
    if (dp[i]) {
      res = i;
      break;
    }
  }

  cout << res;

  return 0;
}