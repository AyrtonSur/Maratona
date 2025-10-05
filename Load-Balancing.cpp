#include <bits/stdc++.h>
#include <string.h>

using namespace std;

void fast_io()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int max_num_cows(int a, int b, vector<pair<int, int>> points) {
  vector<pair<int, int>> left, right;

  for (pair<int, int> p : points) {
    if (p.first < a) {
      left.push_back(p);
    } else {
      right.push_back(p);
    }
  }

  vector<pair<int, int>> topl, topr, botl, botr;

  for (pair<int, int> p : left) {
    if (p.second < b) {
      botl.push_back(p);
    } else {
      topl.push_back(p);
    }
  }

  for (pair<int, int> p : right) {
    if (p.second < b) {
      botr.push_back(p);
    } else {
      topr.push_back(p);
    }
  }

  int max1 = max(botr.size(), topr.size());
  int max2 = max(botl.size(), topl.size());
  return max(max1, max2);
}

int main()
{
  fast_io();

  freopen("balancing.in", "r", stdin);
  freopen("balancing.out", "w", stdout);

  int n, B;

  cin >> n >> B;

  vector<int> xs;
  vector<int> ys;
  vector<pair<int, int>> points;
  int x_median;
  int y_median;

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;

    points.push_back(pair(x, y));
  }

  int res = INT32_MAX;

  for (auto &[a, b] : points) {
    for (auto &[c, d] : points) {
      res = min(max_num_cows(a + 1, d + 1, points), res);
    }
  }

  cout << res << endl;

  return 0;
}