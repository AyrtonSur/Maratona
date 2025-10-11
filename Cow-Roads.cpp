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

  freopen("circlecross.in", "r", stdin);
  freopen("circlecross.out", "w", stdout);

  vector<char> alphabets = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

  string word;

  cin >> word;

  set<pair<char, char>> pair_letters;

  for (int i = 0; i < 26; i++) {
    for (int j = i; j < 26; j++) {
      pair_letters.emplace(pair(alphabets[i], alphabets[j]));
    }
  }

  int res = 0;

  for (auto &[let1, let2] : pair_letters) {
    int ind1_let1 = word.find(let1);
    int ind2_let1 = word.rfind(let1);

    int ind1_let2 = word.find(let2);
    int ind2_let2 = word.rfind(let2);

    if (ind1_let1 < ind1_let2 && ind2_let1 > ind1_let2 && ind2_let1 < ind2_let2) {
      res++;
    } else if (ind1_let2 < ind1_let1 && ind2_let2 > ind1_let1 && ind2_let2 < ind2_let1) {
      res++;
    }
  }

  cout << res;

  return 0;
}