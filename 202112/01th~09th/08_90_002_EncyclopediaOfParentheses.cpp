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
  int N; cin >> N;
  if(N % 2 == 1) return 0;
  vector<string> ans;
  for(int i = 0; i < (1 << N); i++) {
    bitset<20> bit(i);

    int cnt_1 = 0;
    int cnt_2 = 0;
    bool flag = true;
    string s = "";
    for(int j = N-1; j >= 0; j--) {
      if(bit.test(j)) {
        cnt_1++;
        s += "(";
      } else {
        cnt_2++;
        if(cnt_2 > cnt_1) {
          flag = false;
          break;
        }
        s += ")";
      }
    }
    if(cnt_1 != cnt_2) flag = false;
    if(!flag) continue;
    ans.push_back(s);
  }
  sort(ALL(ans));
  for(string s : ans) cout << s << endl;
}