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
  int a, b, c, d; cin >> a >> b >> c >> d;
  if(b >= c*d) {
    cout << "-1" << endl;
    return 0;
  }
  long long i = 0;
  while(true) {
    long long mizu = a + b*i;
    long long red = c*i;
    if(mizu <= red*d) break;
    i++;
  }
  cout << i << endl;
  return 0;
}