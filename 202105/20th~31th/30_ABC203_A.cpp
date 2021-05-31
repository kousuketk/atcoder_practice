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
  int a, b, c;
  cin >> a >> b >> c;
  if(a == b) cout << c << endl;
  else if(a == c) cout << b << endl;
  else if(b == c) cout << a << endl;
  else cout << 0 << endl;
}