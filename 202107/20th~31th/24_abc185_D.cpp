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
  ll N, M; cin >> N >> M;
  vector<ll> vec(M);
  rep(i,M) cin >> vec[i];
  if(M == 0) {
    cout << "1" << endl;
    return 0;
  }

  sort(ALL(vec));
  ll k = N;
  ll before = 0;
  int flag = 0;
  rep(i,M) {
    if(vec[i] == before+1) {
      before = vec[i];
      flag++;
      continue;
    }
    k = min(k, vec[i]-before-1);
    before = vec[i];
  }
  if(N == before+1) flag++;
  else if(N != vec[M-1]) k = min(k, N-vec[M-1]);
  if(flag == M) {
    cout << "0" << endl;
    return 0;
  }
  before = 0;
  ll ans = 0;
  rep(i,M) {
    if(vec[i] == before+1) {
      before = vec[i];
      continue;
    }
    ll tmp = (vec[i]-before-1)/k;
    if(tmp*k == (vec[i]-before-1)) ans += tmp;
    else ans += tmp+1;
    before = vec[i];
  }
  ll tmp2 = (N-vec[M-1])/k;
  if(tmp2*k == (N-vec[M-1])) ans += tmp2;
  else ans += tmp2+1;
  cout << ans << endl;
}