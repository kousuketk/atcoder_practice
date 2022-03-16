#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#include <math.h>
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
const double pi = acos(-1);

int main() {
  double N; cin >> N;
  double x0, y0, xhlf, yhlf; cin >> x0 >> y0 >> xhlf >> yhlf;
  double xc = (x0+xhlf)/2;
  double yc = (y0+yhlf)/2;
  double new_x0 = x0 - xc;
  double new_y0 = y0 - yc;
  // new_x0, new_y0から角度360/Nを反時計回りに回す。
  double rad = 2*pi/N;
  double new_x1 = new_x0*cos(rad) - new_y0*sin(rad);
  double new_y1 = new_x0*sin(rad) + new_y0*cos(rad);
  double ansx = new_x1 + xc;
  double ansy = new_y1 + yc;
  cout << fixed << setprecision(10) << ansx << " " << fixed << setprecision(10) << ansy << endl;
}