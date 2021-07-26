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

double memo[110][110][110];

double rec(int x, int y, int z) {
  if(memo[x][y][z] != -1) {
    // cout << x << y << z << endl;
    return memo[x][y][z];
  }
  if(x == 100 || y == 100 || z == 100) return 0;
  double ans = 0;
  ans = rec(x+1, y, z)*((double)x/(x+y+z)) + 
        rec(x, y+1, z)*((double)y/(x+y+z)) + 
        rec(x, y, z+1)*((double)z/(x+y+z)) + 1;
  return memo[x][y][z] = ans;
}

int main() {
  double a, b, c; cin >> a >> b >> c;
  rep(i,110)rep(j,110)rep(k,110) memo[i][j][k] = -1;
  cout << fixed << setprecision(8) << rec(a,b,c) << endl;
}