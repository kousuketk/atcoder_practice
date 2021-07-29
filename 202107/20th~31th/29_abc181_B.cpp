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
  int N; cin >> N;
  int M = 1000010;
  vector<ll> S(M);
  S[0] = 0;
  rep(i,M-1) {
    S[i+1] = S[i] + i;
  }
  ll ans = 0;
  rep(i,N) {
    int a, b; cin >> a >> b;
    ans += S[b+1] - S[a];
  }
  cout << ans << endl;
}



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
  string s = "13421421551129";
  sort(s.begin(), s.end());
  char c = '9';
  auto itr = lower_bound(s.begin(), s.end(), c);
  cout << s << endl;
  cout << (*itr==c) << endl;
}



int main() {
  string s = "13421421551129";
  sort(s.begin(), s.end());
  char c = '5';
  auto itr = lower_bound(s.begin(), s.end(), c);
  cout << s << endl;
  s.erase(itr, itr+1);
  cout << s << endl;
}