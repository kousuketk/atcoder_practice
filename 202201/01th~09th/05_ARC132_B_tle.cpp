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
string sorted_p;
map<P, int> mp;  // 1, 2番目の要素をペアにする

void dfs(vector<int> &vec, int cnt, bool flag) {
  P tmp;
  if(flag) tmp = P(vec[0], vec[1]);
  else tmp = P(vec[N-1], vec[N-2]);
  if(mp.count(tmp) && mp[tmp] < cnt) return;
  if(cnt > N) return;
  mp[tmp] = cnt;
  // flag=1だったら前から見ていく
  // 全体をひっくり返す.
  dfs(vec, cnt+1, !flag);
  if(flag) {
    // 先頭の項を末尾に移動.
    int a = vec[0];
    vec.erase(vec.begin());
    vec.push_back(a);
    dfs(vec, cnt+1, flag);
    // 戻す
    vec.pop_back();
    vec.insert(vec.begin(), a);
  } else {
    // 末尾を先頭に移動.
    int a = vec[N-1];
    vec.pop_back();
    vec.insert(vec.begin(), a);
    dfs(vec, cnt+1, flag);
    // 戻す
    vec.erase(vec.begin());
    vec.push_back(a);
  }
  return;
}

int main() {
  cin >> N;
  vector<int> vec(N);
  vector<int> vec_soreted(N);
  rep(i,N) {
    int p; cin >> p;
    vec[i] = p;
    vec_soreted[i] = p;
  }
  sort(ALL(vec_soreted));
  mp[P(vec[0], vec[1])] = 0;
  dfs(vec, 0, true);
  int ans = mp[P(vec_soreted[0], vec_soreted[1])];
  cout << ans << endl;
  // cout << "fasd" << endl;
  // for(auto itr = mp.begin(); itr != mp.end(); itr++) {
  //   cout << itr->first.first << " " << itr->first.second << " " << itr->second << endl;
  // }
}

// insertがO(N)かかるから(vec.end()まで1つずつずらしていく)、TLEになった