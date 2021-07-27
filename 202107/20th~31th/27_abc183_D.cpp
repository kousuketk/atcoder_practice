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

int M = 200100;

int main() {
  int N, W; cin >> N >> W;
  vector<ll> S(M+1);
  rep(i,N) {
    int s, t, p; cin >> s >> t >> p;
    S[s] += p;
    S[t] -= p;
  }
  bool flag = true;
  if(S[0] > W) flag = false;
  rep(i,M) {
    S[i+1] += S[i];
    if(S[i+1] > W) flag = false;
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}