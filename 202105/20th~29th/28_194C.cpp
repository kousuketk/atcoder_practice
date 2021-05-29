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
  ll n;
  cin >> n;
  vector<ll> A(401);
  for(ll i = 0; i < n; i++) {
    ll a;
    cin >> a;
    A[a+200]++;
  }
  ll ans = 0;
  for(ll i = 0; i < 401; i++) {
    for(ll j = i+1; j < 401; j++) {
      if(A[i] > 0 && A[j] > 0) {
        // cout << i << " " << A[i] << " " << j << " " << A[j] << endl;
        // cout << A[i]*A[j]*(i-j)*(i-j) << endl;
        ans += A[i]*A[j]*(i-j)*(i-j);
      }
    }
  }
  cout << ans << endl;
}