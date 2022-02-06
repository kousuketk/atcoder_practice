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
  vector<int> vec(N);
  vector<int> vec_new(N);
  rep(i,N) cin >> vec[i];
  int now = 0;
  rep(i,N) {
    int a = vec[i];
    vec_new[i] = (now + a) % 360;
    now += a;
  }
  sort(ALL(vec_new));
  int ans = vec_new[0];
  rep(i,N-1) ans = max(ans, vec_new[i] - vec_new[i-1]);
  ans = max(ans, 360 - vec_new[N-1]);
  cout << ans << endl;
}