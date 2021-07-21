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
  ll C; cin >> C;
  vector<P> vec(2*N);
  rep(i,N) {
    int a, b, c; cin >> a >> b >> c;
    vec[i*2].first = a;
    vec[i*2].second = c;
    vec[i*2+1].first = b+1;
    vec[i*2+1].second = -c;
  }
  sort(vec.begin(), vec.end());
  ll sum = 0;
  int before_first = 1;
  ll pay = 0;
  rep(i,2*N) {
    if(before_first == vec[i].first) {
      pay += vec[i].second;
    } else {
      sum += min(C, pay) * (vec[i].first-before_first);
      pay += vec[i].second;
    }
    before_first = vec[i].first;
  }
  cout << sum << endl;
}