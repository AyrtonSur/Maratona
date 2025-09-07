#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int solved_problems = 0;

  int frnd1, frnd2, frnd3;

  for (int i = 0; i < n; i++) {
    cin >> frnd1 >> frnd2 >> frnd3;

    if ((frnd1 + frnd2 + frnd3) >= 2) solved_problems++;    
  }

  cout << solved_problems;

  return 0;
}