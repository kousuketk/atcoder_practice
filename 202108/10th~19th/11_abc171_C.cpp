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
map<int, string> mp{
  {0,"z"},{1,"a"},{2,"b"},{3,"c"},{4,"d"},{5,"e"},
  {6,"f"},{7,"g"},{8,"h"},{9,"i"},{10,"j"},{11,"k"},
  {12,"l"},{13,"m"},{14,"n"},{15,"o"},{16,"p"},{17,"q"},
  {18,"r"},{19,"s"},{20,"t"},{21,"u"},{22,"v"},{23,"w"},{24,"x"},{25,"y"}
};

int main() {
  ll N; cin >> N;
  string ans = "";
  while(N >= 1) {
    int key = N % 26;
    ans = mp[key] + ans;
    N = (ll)(N-1)/26;
  }
  cout << ans << endl;
}