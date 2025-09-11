#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, q;

  cin >> n >> q;

  long long nums[n];
  long long sum_sequence[n];

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    sum_sequence[i] = i == 0 ? nums[i] : nums[i] + sum_sequence[i - 1];
  }

  int a, b;

  for (int i = 0; i < q; i++) {
    cin >> a >> b;

    long long res = sum_sequence[b - 1] - sum_sequence[a] + nums[a];

    res == q - 1 ? cout << res : cout << res << "\n";
  }
} 