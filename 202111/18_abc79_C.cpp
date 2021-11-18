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
  int input; cin >> input;
  vector<int> vec(4);
  rep(i,4) {
    vec[i] = input % 10;
    input = input / 10;
  }
  reverse(ALL(vec));
  string ans = to_string(vec[0]);
  for(int tmp = 0; tmp < (1<<3); tmp++) {
    bitset<3> bit(tmp);
    int sum = vec[0];
    for(int i = 0; i < 3; i++) {
      if(bit.test(i)) sum += vec[i+1];
      else sum -= vec[i+1];
    }
    if(sum == 7) {
      rep(i,3) {
        if(bit.test(i)) ans += "+";
        else ans += "-";
        ans += to_string(vec[i+1]);
      }
      break;
    }
  }
  ans += "=7";
  cout << ans << endl;
}