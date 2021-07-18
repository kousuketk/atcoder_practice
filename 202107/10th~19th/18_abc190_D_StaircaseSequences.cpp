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
  ll N; cin >> N;
  int count = 0;
  for(ll i = 1; i*i <= (2*N); i++) {
    if((2*N) % i == 0) {
      ll x = i;
      ll y = (2*N)/i;
      if((x+y-1) % 2 != 0) continue;
      count++;
    }
  }
  int ans = count*2;
  cout << ans << endl;
}