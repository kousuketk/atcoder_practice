#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#include<math.h>
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
static const double pi = 3.141592653589793;

int main() {
  double a, b, h, m; cin >> a >> b >> h >> m;
  double t = double(30*h+m/2-6*m)/180 * pi;
  double ans = sqrt(a*a + b*b - 2*a*b*cos(t));
  cout << std::fixed << std::setprecision(11) << ans << endl;
}
// 最初、問題を理解していなかった→自分でサンプル作って吟味