#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using Graph = vector<vector<int>>;
 
int main() {
  vector<int> vec(3);
  rep(i,3) cin >> vec.at(i);
  sort(vec.begin(), vec.end());
  int a = vec.at(1) - vec.at(0);
  int b = vec.at(2) - vec.at(1);
  if(a == b) cout << "Yes" << endl;
  else cout << "No" << endl;
}