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
  int N, X, Y; cin >> N >> X >> Y;
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  ll ans = 0;
  for(int i = 0; i < N; i++) {
    map<int, int> mp;  // 数字valは、何個cntあるか
    int a = vec[i];
    mp[a]++;
    int max_val = a;
    int min_val = a;
    for(int j = i; j < N; j++) {
      int b = vec[j];
      mp[b]++;
      max_val = max(max_val, b);
      min_val = min(min_val, b);
      if(max_val == X && min_val == Y) ans++;
      if(max_val > X || min_val < Y) break;
    }
  }
  cout << ans << endl;
  return 0;
}