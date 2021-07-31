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
  vector<ll> vec;
  ll add_count = 0;
  priority_queue<ll, vector<ll>, greater<ll>> q;
  rep(i,N) {
    int a, b; cin >> a;
    if(a == 1) {
      cin >> b;
      ll tmp = b - add_count;
      // vecにlowwer_boundでtmpを追加するvec.insert(itr, tmp)
      q.push(tmp);
    } else if(a == 2) {
      cin >> b;
      add_count += b;
    } else {
      ll tmp = q.top() + add_count;
      cout << tmp << endl;
      q.pop();
    }
  }
  return 0;
}