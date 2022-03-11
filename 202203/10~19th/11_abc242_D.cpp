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

string s;

// S(t)のｋ文字目を返す
char rev(ll t, ll k) {
  if(t == 0) return s[k];
  if(k == 0) return ('A'+(s[0]-'A'+t)%3);
  char tmp = rev(t-1, k/2);
  int add = 1;
  if(k % 2 == 1) add++; // 奇数だったら2進む
  return ('A'+(tmp-'A'+add)%3);
}

int main() {
  cin >> s;
  int Q; cin >> Q;
  rep(i,Q) {
    ll t, k; cin >> t >> k;
    k--;
    char ans = rev(t, k);
    cout << ans << endl;
  }
  return 0;
}