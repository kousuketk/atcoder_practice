#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  string X; cin >> X;
  ll M; cin >> M;
  string Y = X;
  sort(Y.rbegin(), Y.rend());
  ll d = Y[0] - '0';
  ll ans = 0;
  // dを1ずつfor文, もしM以上になったらbreak
  while(true) {
    d = d + 1;
    ll tmp = 0;
    for(ll i = 0; i < X.size(); i++) {
      ll a = pow(d, i);
      tmp += (X[X.size()-1-i]-'0') * a;
    }
    if(tmp > M) break;
    ans++;
  }
  cout << ans << endl;
}