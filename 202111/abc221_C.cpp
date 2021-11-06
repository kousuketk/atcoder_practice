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
  // 大きい順に並べて、小さい数字の方に足していく
  sort(s.begin(), s.end(), greater());
  int a = 0, b = 0;
  rep(i,N) {
    if(a <= b) a = a*10 + (s[i] - '0');
    else b = b*10 + (s[i] - '0');
  }
  cout << a*b << endl;
}