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

bool judge(bitset<20> bit, int N) {
  int cnt = 0;
  rep(i,N) {
    if(bit.test(i)) cnt++;
    else cnt--;
    if(cnt < 0) return false;
  }
  if(cnt != 0) return false;
  return true;
}

void inputAns(vector<string> &ans, bitset<20> bit, int N) {
  string s = "";
  rep(i,N) {
    if(bit.test(i)) s = ")" + s;
    else s = "(" + s;
  }
  ans.push_back(s);
  return;
}

int main() {
  int N; cin >> N;
  if(N % 2 == 1) return 0;
  vector<string> ans;
  for(int tmp = 0; tmp < 1<<N; tmp++) {
    bitset<20> bit(tmp);

    bool flag = judge(bit, N);
    if(flag) inputAns(ans, bit, N);
  }
  rep(i,(int)ans.size()) cout << ans[i] << endl;
  return 0;
}