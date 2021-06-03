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
  ll N;
  cin >> N;
  unordered_set<ll> s;
  for(ll i = 2; i <= 100001; i++) {
    for(ll j = 2; j <= 35; j++) {
      ll a = pow(i, j);
      if(a > N) break;
      s.insert(a);
    }
  }
  cout << N - s.size() << endl;
}