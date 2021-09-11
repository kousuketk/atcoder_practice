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
  int N; cin >> N;
  vector<P> vec(N);
  rep(i,N) {
    int x, y; cin >> x >> y;
    vec[i] = P(x,y);
  }
  sort(ALL(vec));
  double sum = 0;
  ll count = 0;
  do {
    rep(i,N-1) {
      int x1 = vec[i].first;
      int y1 = vec[i].second;
      int x2 = vec[i+1].first;
      int y2 = vec[i+1].second;
      sum += sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
    }
    count++;
  } while (next_permutation(vec.begin(), vec.end()));
  double ans = sum/count;
  cout << fixed << setprecision(8) << ans << endl;
}