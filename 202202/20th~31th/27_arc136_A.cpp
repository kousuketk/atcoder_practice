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
  string s; cin >> s;
  auto itr = s.begin();
  // AがあったらBBにして
  while(itr != s.end()) {
    if(*itr == 'A') {
      *itr = 'B';
      itr = s.insert(itr, 'B');
    }
    itr++;
  }
  // BBがあったらAにする(貪欲法)
  auto itr2 = s.begin();
  int cnt = 0;
  while(itr2 != s.end()) {
    if(*itr2 == 'B' && cnt == 0) {
      cnt++;
    } else if(*itr2 == 'B' && cnt == 1) {
      itr2 = s.erase(itr2-1);
      *itr2 = 'A';
      cnt = 0;
    } else if(*itr2 != 'B') {
      cnt = 0;
    }
    itr2++;
  }
  cout << s << endl;
}