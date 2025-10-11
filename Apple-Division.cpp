#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void fast_io()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

vector<long long> gp;

long long calc_div(int ind, long long total_gp1, long long total_gp2, int n) {
  if (ind >= n) {
    return abs(total_gp1 - total_gp2);
  }

  return min(
    calc_div(ind + 1, total_gp1 + gp[ind], total_gp2, n), 
    calc_div(ind + 1, total_gp1, total_gp2 + gp[ind], n)
  );
}

int main()
{
  fast_io();

  int n;

  cin >> n;
  
  for (int i = 0; i < n; i++) {
    long long aux;

    cin >> aux;

    gp.push_back(aux);
  }

  long long res = calc_div(0, 0, 0, n);

  cout << res;

  return 0;
}