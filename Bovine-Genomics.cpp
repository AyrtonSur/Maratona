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

  vector<set<char>> vec_chars_spotty(m);
  vector<set<char>> vec_chars_plain(m);

  for (int i = 0; i < n; i++) {
    cin >> gen;
    int j = 0;
    for (char c: gen) {
      vec_chars_spotty[j].emplace(c);
      j++;
    }
  }

  for (int i = 0; i < n; i++) {
    cin >> gen;
    int j = 0;
    for (char c: gen) {
      vec_chars_plain[j].emplace(c);
      j++;
    }
  }

  int res = 0;
  int size1, size2;

  for (int i = 0; i < m; i++) {
    size1 = vec_chars_plain[i].size();
    size2 = vec_chars_spotty[i].size();

    vec_chars_plain[i].merge(vec_chars_spotty[i]);

    if (vec_chars_plain[i].size() == (size1 + size2)) res++;
  }

  cout << res;

  return 0;
}