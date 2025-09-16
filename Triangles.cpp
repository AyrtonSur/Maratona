#include <bits/stdc++.h>

using namespace std;

int euclidean_dist(pair<int, int> p1, pair<int, int> p2) {
  return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  freopen("triangles.in", "r", stdin);
  freopen("triangles.out", "w", stdout);

  int n;
  cin >> n;

  vector<pair<int, int>> points2;

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;

    points2.push_back(pair(x, y));
  }

  int max_area = INT16_MIN;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (points2[i].first == points2[j].first) {
          if (points2[i].second == points2[k].second) {
            int dist1 = euclidean_dist(points2[i], points2[j]);
            int dist2 = euclidean_dist(points2[i], points2[k]);
            max_area = max(max_area, (dist1 * dist2));
          } else if (points2[j].second == points2[k].second) {
            int dist1 = euclidean_dist(points2[i], points2[j]);
            int dist2 = euclidean_dist(points2[j], points2[k]);
            max_area = max(max_area, dist1 * dist2);
          }
        } else if (points2[i].first == points2[k].first) {
          if (points2[i].second == points2[j].second) {
            int dist1 = euclidean_dist(points2[i], points2[k]);
            int dist2 = euclidean_dist(points2[i], points2[j]);
            max_area = max(max_area, dist1 * dist2);
          } else if (points2[j].second == points2[k].second) {
            int dist1 = euclidean_dist(points2[i], points2[k]);
            int dist2 = euclidean_dist(points2[j], points2[k]);
            max_area = max(max_area, dist1 * dist2);
          }
        } else if (points2[j].first == points2[k].first) {
          if (points2[i].second == points2[k].second) {
            int dist1 = euclidean_dist(points2[j], points2[k]);
            int dist2 = euclidean_dist(points2[i], points2[k]);
            max_area = max(max_area, dist1 * dist2);
          } else if (points2[i].second == points2[j].second) {
            int dist1 = euclidean_dist(points2[j], points2[k]);
            int dist2 = euclidean_dist(points2[i], points2[j]);
            max_area = max(max_area, dist1 * dist2);
          }
        }
      }
    }
  }

  cout << max_area << "\n";

  return 0;
}