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

  freopen("gymnastics.in", "r", stdin);
  freopen("gymnastics.out", "w", stdout);

  int k, n;

  cin >> k >> n;

  vector<vector<int>> mat_sessions_cows;

  set<tuple<int, int>> preprocessing_vec;

  for (int i = 0; i < k; i++) {
    vector<int> aux_vec;
    for (int j = 0; j < n; j++) {
      int aux;
      cin >> aux;
      aux_vec.push_back(aux);
    }

    mat_sessions_cows.push_back(aux_vec);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      preprocessing_vec.emplace(tuple(i, j));
    }
  }

  int consistent_pairs = 0;

  for (auto [i, j] : preprocessing_vec) {
    bool balanced = true;

    auto it1 = find(mat_sessions_cows[0].begin(), mat_sessions_cows[0].end(), i);
    auto it2 = find(mat_sessions_cows[0].begin(), mat_sessions_cows[0].end(), j);
    auto pos1 = (it1 - mat_sessions_cows[0].begin());
    auto pos2 = (it2 - mat_sessions_cows[0].begin());

    if (pos1 < pos2) {
      for (int w = 1; w < k; w++) {
        auto it3 = find(mat_sessions_cows[w].begin(), mat_sessions_cows[w].end(), i);
        auto it4 = find(mat_sessions_cows[w].begin(), mat_sessions_cows[w].end(), j);
        auto pos3 = (it3 - mat_sessions_cows[w].begin());
        auto pos4 = (it4 - mat_sessions_cows[w].begin());

        if (pos4 < pos3) {
          balanced = false;
          break;
        }
      }

    } else if (pos2 < pos1) {
      for (int w = 1; w < k; w++) {
        auto it3 = find(mat_sessions_cows[w].begin(), mat_sessions_cows[w].end(), i);
        auto it4 = find(mat_sessions_cows[w].begin(), mat_sessions_cows[w].end(), j);
        auto pos3 = (it3 - mat_sessions_cows[w].begin());
        auto pos4 = (it4 - mat_sessions_cows[w].begin());

        if (pos3 < pos4) {
          balanced = false;
          break;
        }
      }
    }

    if (balanced) consistent_pairs++;
  }

  cout << consistent_pairs << endl;

  return 0;
}