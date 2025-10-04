#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  freopen("cownomics.in", "r", stdin);
  freopen("cownomics.out", "w", stdout);

  int n, m;

  cin >> n >> m;

  string gen;

  string initial_vec_chars_spotty[n];
  string initial_vec_chars_plain[n];

  int total_m = (m * (m - 1) * (m - 2)) / 6;

  vector<unordered_set<string>> vec_chars_spotty(total_m);
  vector<unordered_set<string>> vec_chars_plain(total_m);

  for (int w = 0; w < n; w++) {
    cin >> initial_vec_chars_spotty[w];

    int idx = 0;

    for (int i = 0; i < m - 2; i++) {
      for (int j = i + 1; j < m - 1; j++) {
        for (int k = j + 1; k < m; k++) {
          string s(1, initial_vec_chars_spotty[w][i]); 
          s += initial_vec_chars_spotty[w][j];
          s += initial_vec_chars_spotty[w][k];
          vec_chars_spotty[idx].emplace(s);

          idx++;
        }
      }
    }
  }

  for (int w = 0; w < n; w++) {
    cin >> initial_vec_chars_plain[w];

    int idx = 0;

    for (int i = 0; i < m - 2; i++) {
      for (int j = i + 1; j < m - 1; j++) {
        for (int k = j + 1; k < m; k++) {
          string s(1, initial_vec_chars_plain[w][i]); 
          s += initial_vec_chars_plain[w][j];
          s += initial_vec_chars_plain[w][k];
          vec_chars_plain[idx].emplace(s);

          idx++;
        }
      }
    }
  }

  int res = 0;
  int size1, size2;

  for (int i = 0; i < total_m; i++) {
    size1 = vec_chars_plain[i].size();
    size2 = vec_chars_spotty[i].size();

    vec_chars_plain[i].merge(vec_chars_spotty[i]);

    if (vec_chars_plain[i].size() == (size1 + size2)) res++;
  }

  cout << res << endl;

  return 0;
}