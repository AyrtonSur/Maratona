#include <bits/stdc++.h>
#include <string.h>

using namespace std;

void fast_io()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int main()
{
  fast_io();

  freopen("bcount.in", "r", stdin);
  freopen("bcount.out", "w", stdout);

  long long n, q;

  cin >> n >> q;

  int cows[n];
  int prefix[n][3];

  for (int i = 0; i < n; i++)
  {
    prefix[i][0] = 0;
    prefix[i][1] = 0;
    prefix[i][2] = 0;
  }

  for (int i = 0; i < n; i++)
  {
    cin >> cows[i];


    if (i != 0) {
      for (int j = 0; j < 3; j++) {
        prefix[i][j] = prefix[i - 1][j];
      }
    }

    prefix[i][cows[i] - 1] += 1;
  }

  for (int i = 0; i < q; i++)
  {
    int a, b;

    cin >> a >> b;

    for (int j = 0; j < 3; j++) {
      int res = (a - 2) < 0 ? prefix[b - 1][j] : prefix[b - 1][j] - prefix[a - 2][j];

      if (j != 2) {
        cout << res <<  " ";
      } else {
        cout << res;
      }
    }

    cout << "\n";
  }

  return 0;
}