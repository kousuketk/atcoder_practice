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
  string s; cin >> s;
  int N = s.size();
  ll sum = 0;
  for(ll tmp = 0; tmp < (1 << N-1); tmp++) {
    bitset<10> bit(tmp);
    string tmp_s = ""; tmp_s = tmp_s + s[0];
    rep(i,N-1) {
      if(bit.test(i)) {
        sum += stoll(tmp_s);
        tmp_s = ""; tmp_s = tmp_s + s[i+1];
      } else {
        tmp_s = tmp_s + s[i+1];
      }
    }
    sum += stoll(tmp_s);
  }
  cout << sum << endl;
}