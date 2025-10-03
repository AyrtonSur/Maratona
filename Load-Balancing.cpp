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
    if (p.first < b) {
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

  // freopen("bcount.in", "r", stdin);
  // freopen("bcount.out", "w", stdout);

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

    int xs_size = xs.size();
    int ys_size = ys.size();

    for (int j = 0; j <= xs_size; j++) {
      if (j == xs_size || xs[j] <= x) {
        xs.emplace(xs.begin() + j, x);
        break;
      }
    }

    for (int j = 0; j <= ys_size; j++) {
      if (j == ys_size || ys[j] <= y) {
        ys.emplace(ys.begin() + j, y);
        break;
      }
    }

    points.push_back(pair(x, y));
  }

  int size_x = xs.size();
  int size_y = ys.size();

  if (size_x % 2 != 0){
    int index = floor(size_x / 2);
    x_median = xs[index];
  } else {
    int ind1 = size_x / 2, ind2 = ind1 - 1;

    x_median = (xs[ind1] + xs[ind2]) / 2;
  }

  if (size_y % 2 != 0){
    int index = floor(size_y / 2);
    y_median = ys[index];
  } else {
    int ind1 = size_y / 2, ind2 = ind1 - 1;

    y_median = (ys[ind1] + ys[ind2]) / 2;
  }

  int a1, a2, b1, b2;

  if (x_median % 2 == 0) {
    a1 = x_median;
    a2 = x_median;
  } else {
    a1 = x_median + 1;
    a2 = (x_median - 1) > 0 ? x_median - 1 : x_median + 1;
  }

  if (y_median % 2 == 0) {
    b1 = y_median;
    b2 = y_median;
  } else {
    b1 = y_median + 1;
    b2 = (y_median - 1) > 0 ? y_median - 1 : y_median + 1;
  }

  int res = INT32_MAX;

  res = min(max_num_cows(a1, b1, points), res);
  res = min(max_num_cows(a1, b2, points), res);
  res = min(max_num_cows(a2, b1, points), res);
  res = min(max_num_cows(a2, b2, points), res);

  cout << res;

  return 0;
}