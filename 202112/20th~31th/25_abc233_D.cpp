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
  ll K; cin >> K;
  vector<ll> vec(N);
  rep(i,N) cin >> vec[i];
  vector<ll> sum(N);
  sum[0] = vec[0];
  rep(i,N-1) sum[i+1] = sum[i] + vec[i+1];
  ll ans = 0;
  map<ll, int> mp;
  rep(i,N) {
    ll tmp = sum[i];
    if(tmp == K) ans++;
    ll search_val = tmp - K;
    int cnt = mp[search_val];
    ans += cnt;
    mp[tmp]++;
  }
  cout << ans << endl;
}