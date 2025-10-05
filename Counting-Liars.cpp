#include <bits/stdc++.h>

using namespace std;

void fast_io()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int main()
{
  fast_io();

  int n;

  cin >> n;

  vector<int> G;
  vector<int> L;

  for (int i =0; i < n; i++) {
    char c;
    int aux;
    cin >> c >> aux;

    if (c == 'G') {
      auto pos = lower_bound(G.begin(), G.end(), aux, greater<int>());

      G.insert(pos, aux);
    } else {
      auto pos = lower_bound(L.begin(), L.end(), aux);

      L.insert(pos, aux);
    }
  }

  int i = 0, j = 0;
  int res = 0;

  int sizeG = G.size(), sizeL = L.size();

  while (i < sizeG && j < sizeL) {
    if (G[i] > L[j]) {
      int countG = 0;
      for (int k = i; k < sizeG; k++) {
        if (G[k] > L[j]) countG++;
        else break;
      }

      int countL = 0;
      for (int k = j; k < sizeL; k++) {
        if (G[i] > L[k]) countL++;
        else break;
      }

      if (countL > countG) i++;
      else j++;

      res++;
    } else {
      break;
    }
  }

  cout << res << endl;
  
  return 0;
}