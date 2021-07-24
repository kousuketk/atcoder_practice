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

int main() {
  int N, M, T; cin >> N >> M >> T;
  vector<P> vec(M);
  rep(i,M) cin >> vec[i].first >> vec[i].second;
  int battery = N;
  int before_b = 0;
  bool flag = true;
  rep(i,M) {
    battery -= (vec[i].first - before_b);
    if(battery <= 0) {
      flag = false;
      break;
    }
    battery += (vec[i].second-vec[i].first);
    if(battery > N) battery = N;
    before_b = vec[i].second;
  }
  battery -= T - before_b;
  if(battery <= 0) flag = false;
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}