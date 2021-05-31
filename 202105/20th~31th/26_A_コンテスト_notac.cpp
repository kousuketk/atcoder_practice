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
  cout << "";
  for (auto itr = vec.begin(); itr != vec.end(); itr++) {
    cout << *itr << " "; 
  }
  cout << endl;
}

int dp[110];

int main() {
  ll N;
  cin >> N;
  vector<ll> vec(N);
  vector<ll> ans_vec;
  rep(i,N) cin >> vec.at(i);
  for(ll tmp = 0; tmp < 1.267650600228229401497E+30; tmp++) {
    bitset<100> bit(tmp);

    ll sum = 0;
    for(ll i = 0; i < N; i++) {
      if(bit.test(i)) sum += vec.at(i);
    }
    auto result = find(ans_vec.begin(), ans_vec.end(), sum);
    if(result == ans_vec.end()) ans_vec.push_back(sum);
  }
  cout << ans_vec.size() << endl;
}