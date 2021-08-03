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
  int count = 0;
  bool ans = false;
  rep(i,N) {
    int a, b; cin >> a >> b;
    if(a == b) count++;
    else count = 0;
    if(count >= 3) ans = true;
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}