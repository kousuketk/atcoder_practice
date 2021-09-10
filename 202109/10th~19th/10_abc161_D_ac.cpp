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
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

int main() {
  int K; cin >> K;
  set<ll> vec;
  ll ans;
  bool flag = false;
  rep(i,9) {
    vec.insert(i+1);
    K--;
    if(K == 0) {
      ans = i+1;
      flag = true;
    }
  }
  int keta = 1;
  while(K > 0 && !flag) {
    // keta-1~keta
    ll s = pow(10, keta-1);
    ll g = pow(10, keta);
    auto itr_s = vec.lower_bound(s);
    auto itr_g = vec.lower_bound(g);
    while(itr_s != itr_g) {
      ll tmp = *itr_s;
      int last = tmp % 10;
      for(int i = last-1; i <= last+1; i++) {
        if(i >= 0 && i <= 9) {
          ll val = tmp*10+i;
          vec.insert(val);
          K--;
          if(K==0) {
            ans = val;
            flag = true;
            break;
          }
        }
      }
      if(flag) break;
      itr_s++;
    }
    keta++;
  }
  cout << ans << endl;
}

// setを使ってacしたやつ