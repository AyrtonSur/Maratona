#include <bits/stdc++.h>
#include <string.h>

using namespace std;

void fast_io()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int max_num_cows(int a, int b, vector<pair<int, int>> points) {
  int topl = 0, topr = 0, botl = 0, botr = 0;

  for (pair<int, int> p : points) {
    if (p.first < a && p.second < b) {
      botl++;
    } else  if (p.first < a) {
      topl++;
    } else if (p.first > a && p.second < b) {
      botr++;
    } else {
      topr++;
    }
  }

  int max1 = max(botr, topr);
  int max2 = max(botl, topl);
  return max(max1, max2);
}

int main()
{
  fast_io();

  freopen("balancing.in", "r", stdin);
  freopen("balancing.out", "w", stdout);

  int n;

  cin >> n;

  vector<pair<int, int>> points;
  set<tuple<int, int>> set_of_points;

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;

    points.push_back(pair(x, y));
  }

  int res = INT32_MAX;

  for (auto &[a, b] : points) {
    for (auto &[c, d] : points) {
      set_of_points.emplace(a + 1, d + 1);
    }
  }

  for (auto [a, b] : set_of_points) {
    res = min(max_num_cows(a, b, points), res);    
  }

  cout << res << endl;

  return 0;
}