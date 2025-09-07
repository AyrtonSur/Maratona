#include <bits/stdc++.h>

using namespace std;

set<int> trips;

void trip(int n, int fill, vector<int> buckets1, vector<int> buckets2) {
  if (n == 0) {
    trips.insert(fill);
    return;
  }
  
  if (n % 2 == 0) {
    for (int i = 0; i < buckets1.size(); i++) {
      int bucket = buckets1[i];
      vector<int> new_b1 = buckets1;
      vector<int> new_b2 = buckets2;
      new_b1.erase(new_b1.begin() + i);
      new_b2.push_back(bucket);
      trip(n - 1, fill - bucket, new_b1, new_b2);
    }
  } else {
    for (int i = 0; i < buckets2.size(); i++) {
      int bucket = buckets2[i];
      vector<int> new_b1 = buckets1;
      vector<int> new_b2 = buckets2;
      new_b2.erase(new_b2.begin() + i);
      new_b1.push_back(bucket);
      trip(n - 1, fill + bucket, new_b1, new_b2);
    }
  }
}

int main() {
  int input;
  vector<int> buckets1, buckets2;

  for (int i = 0; i < 10; i++) {
    cin >> input;
    buckets1.push_back(input);
  }

  for (int i = 0; i < 10; i++) {
    cin >> input;
    buckets2.push_back(input);
  }

  trip(4, 1000, buckets1, buckets2);
  cout << trips.size() << endl;

  return 0;
}