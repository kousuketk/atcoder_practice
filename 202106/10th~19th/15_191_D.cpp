#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  long double x, y, r; cin >> x >> y >> r;
  r += (1e-14);
  long double start = ceil(x-r); long double end = floor(x+r);
  ll ans = 0;
  for(long double i = start; i <= end; i++) {
    long double p = (long double)(sqrt((long double)(pow(r,2)) - (long double)(pow((x-i),2))));
    ll bottom = ceil(y-p);
    ll top = floor(y+p);
    ans += top - bottom + 1;
  }
  cout << ans << endl;
}