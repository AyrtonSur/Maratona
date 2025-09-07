#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  freopen("teleport.in", "r", stdin);
  freopen("teleport.out", "w", stdout);

  int a, b, x, y;

  cin >> a >> b >> x >> y;

  int bx = abs(b - x);
  int by = abs(b - y);
  int ax = abs(a - x);
  int ay = abs(a - y);
  int ab = abs(b - a);

  if (ab <= (bx + ay) && ab <= (by + ax)) {
    cout << ab;
  } else if ((bx + ay) <= (by + ax)) {
    cout << (bx + ay);
  } else {
    cout << (by + ax);
  }

  return 0;
}