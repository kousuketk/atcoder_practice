#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

int main() {
  int x1, y1, x2, y2, x3, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  map<int, int> mpx;
  mpx[x1]++;
  mpx[x2]++;
  mpx[x3]++;
  int x4;
  if(mpx[x1] == 1) x4 = x1;
  else if(mpx[x2] == 1) x4 = x2;
  else x4 = x3;
  map<int, int> mpy;
  mpy[y1]++;
  mpy[y2]++;
  mpy[y3]++;
  int y4;
  if(mpy[y1] == 1) y4 = y1;
  else if(mpy[y2] == 1) y4 = y2;
  else y4 = y3;
  cout << x4 << " " << y4 << endl;
  return 0;
}