#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // freopen("cownomics.in", "r", stdin);
  // freopen("cownomics.out", "w", stdout);

  int n, m;

  cin >> n >> m;

  string gen;

  string initial_vec_chars_spotty[n];
  string initial_vec_chars_plain[n];

  for (int i = 0; i < n; i++) {
    cin >> initial_vec_chars_spotty[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> initial_vec_chars_plain[i];
  }

  int total_m = (m * (m - 1) * (m - 2)) / 6;

  set<char> vec_chars_spotty[total_m];
  set<char> vec_chars_plain[total_m];

  int idx = 0;
  for (int i = 0; i < m - 2; i++) {
    for (int j = i + 1; j < m - 1; j++) {
      for (int k = j + 1; k < m; k++) {
        for (int w = 0; w < n; w++) {
          vec_chars_spotty[idx].emplace(initial_vec_chars_spotty[w][w] + initial_vec_chars_spotty[w][w] + initial_vec_chars_spotty[k][w]);
        }

        idx++;
      }
    }
  }

  idx = 0;
  for (int i = 0; i < m - 2; i++) {
    for (int j = i + 1; j < m - 1; j++) {
      for (int k = j + 1; k < m; k++) {
        vec_chars_plain[idx].insert(initial_vec_chars_plain[i].begin(), initial_vec_chars_plain[i].end());
        vec_chars_plain[idx].insert(initial_vec_chars_plain[j].begin(), initial_vec_chars_plain[j].end());
        vec_chars_plain[idx].insert(initial_vec_chars_plain[k].begin(), initial_vec_chars_plain[k].end());

        idx++;
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

  cout << res;

  return 0;
}