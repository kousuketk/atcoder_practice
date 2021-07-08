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

string X; 
ll M;

bool check(ll x) {
  ll tmp = 0;
  if(x > M) return false;
  for(ll i = 0; i < X.size(); i++) {
    ll a = pow(x, i);
    // cout << a << " " << endl;
    if(a > M || a < 0) return false;
    tmp += (X[X.size()-1-i]-'0') * a;
    if(tmp > M || tmp < 0) return false;
  }
  return tmp <= M;
}

int main() {
  cin >> X;
  cin >> M;
  if(X.size() == 1) {
    if(stoi(X) <= M) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
  }
  string Y = X;
  sort(Y.rbegin(), Y.rend());
  ll d = Y[0] - '0';
  ll ans = 0;
  ll left = d;
  ll right = M+1;
  while(right - left > 1) {
    ll mid = (left + right) / 2;
    if(check(mid)) left = mid;
    else right = mid;
  }
  cout << left - d << endl;
}