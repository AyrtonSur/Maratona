#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;

  cin >> n;

  int xvec[n], yvec[n];

  for (int i = 0; i < n; i++) {
    cin >> xvec[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> yvec[i];
  }

  long long res;
  long long maximum = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      res = pow(xvec[i] - xvec[j], 2) + pow(yvec[i] - yvec[j], 2);

      maximum = max(res, maximum);
    }
  }

  cout << maximum;

  return 0;
}