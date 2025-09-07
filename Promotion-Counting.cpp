#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  freopen("promote.in", "r", stdin);
  freopen("promote.out", "w", stdout);

  int sb, eb;
  int ss, es;
  int sg, eg;
  int sp, ep;

  cin >> sb >> eb;
  cin >> ss >> es;
  cin >> sg >> eg;
  cin >> sp >> ep;

  int prom_plat, prom_gold, prom_silv;

  prom_plat = ep - sp;
  prom_gold = prom_plat + eg - sg;
  prom_silv = prom_gold + es - ss;
  
  cout << prom_silv << "\n" << prom_gold << "\n" << prom_plat;
}