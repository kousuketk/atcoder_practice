#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<char,int>;
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
  string s; cin >> s;
  vector<P> vec(N);
  rep(i,N) vec[i] = P(s[i], -i);
  // string s_sorted = s;
  sort(ALL(vec));
  // cout << vec[0].first << endl;
  // cout << s_sorted << endl;
  int i = 0;  // sortedのpointer
  int start = 0;  // 全体文字列のpointer
  int end = N-1;
  while((start < end) && i < N) {
    char c = vec[i].first;
    int idx = vec[i].second*(-1);
    if((idx > end) || (idx < start)) {
      i++;
      continue;
    }
    if(s[start] > c) {
      char tmp = s[start];
      s[start] = c;
      s[idx] = tmp;
      end = idx;
      // cout << start << " " << idx << endl;
      start++;
      i++;
    } else {
      start++;
    }
  }
  cout << s << endl;
}