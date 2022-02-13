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

int N;
// 数字が7,5,3を含むか
bool check(ll num) {
  bool flag7 = false;
  bool flag5 = false;
  bool flag3 = false;
  while(num > 0) {
    if(num % 10 == 7) flag7 = true;
    else if(num % 10 == 5) flag5 = true;
    else if(num % 10 == 3) flag3 = true;
    num = num/10; 
  }
  if(flag7 && flag5 && flag3) return true;
  else return false;
}

int dfs(ll now) {
  if(now > N) return 0;
  int res = 0;
  if(check(now)) res++;
  // 3を追加
  res += dfs(now*10 + 3);
  // 5を追加
  res += dfs(now*10 + 5);
  // 7を追加
  res += dfs(now*10 + 7);
  
  return res;
}

int main() {
  cin >> N;
  int ans = dfs(0, false);
  cout << ans << endl;
}