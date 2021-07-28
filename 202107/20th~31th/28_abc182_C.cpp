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
  string s; cin >> s;
  int N = s.size();

  int ans = INF;
  for(int tmp = 0; tmp < (1<<N); tmp++) {
    bitset<18> bit_s(tmp);

    string tmp_s = "";
    int rm_count = 0;
    for(int i = 0; i < N; i++) {
      if(bit_s.test(N-1-i)) {
        tmp_s += s[N-1-i];
      } else {
        rm_count++;
      }
    }
    if(tmp_s == "") continue;
    ll num = stoll(tmp_s);
    if(num % 3 == 0) ans = min(ans, rm_count);
  }
  if(ans == INF) cout << "-1" << endl;
  else cout << ans << endl;
}