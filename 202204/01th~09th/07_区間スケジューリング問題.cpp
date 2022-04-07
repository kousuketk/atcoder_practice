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

// 遅く始まるやつから選んでいく→終了時刻が早い予定を優先的に選んで行ってもok
int main() {
  int N; cin >> N;
  vector<P> vec(N);
  rep(i,N) cin >> vec[i].first >> vec[i].second;
  sort(ALL(vec));
  int last = INF;
  int ans = 0;
  for(int i = N-1; i >= 0; i--) {
    int s = vec[i].first;
    int t = vec[i].second;
    if(last < t) continue;
    last = s;
    ans++;
  }
  cout << ans << endl;
  return 0;
}