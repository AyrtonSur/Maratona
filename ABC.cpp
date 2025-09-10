#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long A, B, C;

  vector<long long> nums;
  long long aux;
  
  for (long long i = 0; i < 7; i++) {
    cin >> aux;
    nums.push_back(aux);
  }

  long long minimum = 100000000000;
  long long maximum = 0;

  for (long long i: nums) {
    minimum = min(i, minimum);
    maximum = max(i, maximum);
  }

  A = minimum;

  for (long long i = 0; i < 7; i++) {
    if (nums[i] == minimum) {
      nums.erase(nums.begin() + i);
      break;
    }
  }

  minimum = 100000000000;

  for (long long i: nums) {
    minimum = min(i, minimum);
  }

  B = minimum;

  C = maximum - A - B;

  cout << A << " " << B << " " << C;
}