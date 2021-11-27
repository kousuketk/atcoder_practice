#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<double,double>;
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
  int N; cin >> N;
  vector<P> vec(N);
  rep(i,N) cin >> vec[i].first >> vec[i].second;
  set<double> trend;
  bool flag_x = false;
  for(int i = 0; i < N; i++) {
    for(int j = i+1; j < N; j++) {
      // vec[i], vec[j]を見る
      double x1 = vec[i].first;
      double y1 = vec[i].second;
      double x2 = vec[j].first;
      double y2 = vec[j].second;
      if(x1 == x2) {
        flag_x = true;
      } else {
        double t = (y1-y2)/(x1-x2);
        trend.insert(t);
      }
    }
  }
  int ans = 2*trend.size();
  if(flag_x) ans += 2;
  cout << ans << endl;
}