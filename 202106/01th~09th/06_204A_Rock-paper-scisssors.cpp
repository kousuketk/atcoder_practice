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
  vector<int> vec(3,0);
  int x, y;
  cin >> x >> y;
  if(x == y) {
    cout << x << endl;
    return 0;
  }
  vec[x]++;
  vec[y]++;
  for(int i = 0; i < 3; i++) {
    if(vec[i] == 0) {
      cout << i << endl;
      return 0;
    }
  }
}