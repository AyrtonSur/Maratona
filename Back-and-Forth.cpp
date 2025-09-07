#include <bits/stdc++.h>

using namespace std;

vector<int> buckets1;
vector<int> buckets2;
set<int> trips;

void trip(int n, int fill) {
  if (n <= 0) {
    trips.insert(fill);
    return;
  }

  int step = n - 1;

  if(n % 2 == 0) {
    int size_b1 = buckets1.size();

    for (int i = 0; i < size_b1; i++) {
      fill -= buckets1[i];
      buckets2.insert(buckets2.begin(), buckets1[i]);
      buckets1.erase(buckets1.begin() + i);
      trip(step, fill);
      fill += buckets2[0];
      buckets1.insert(buckets1.begin(), buckets2[0]);
      buckets2.erase(buckets2.begin());
    }
  } else if (n % 2 != 0) {
    int size_b2 = buckets2.size();

    for (int i = 0; i < size_b2; i++) {
      fill += buckets2[i];
      buckets1.insert(buckets1.begin(), buckets2[i]);
      buckets2.erase(buckets2.begin() + i);
      trip(step, fill);
      fill -= buckets1[0];
      buckets2.insert(buckets2.begin(), buckets1[0]);
      buckets1.erase(buckets1.begin());
    }
  }
}

int main() {
  int input;

  for (int i = 0; i < 10; i++) {
    cin >> input;

    buckets1.push_back(input);
  }

  for (int i = 0; i < 10; i++) {
    cin >> input;

    buckets2.push_back(input);  
  }

  trip(4, 1000);

  cout << trips.size();

  cout << "{ ";
  for (int x : trips) {
    cout << x << " ";
  }
  cout << "}";

  return 0;
}