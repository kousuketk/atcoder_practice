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

int main() {
  int tmp_a, tmp_b; cin >> tmp_a >> tmp_b;
  bitset<8> a(tmp_a);
  bitset<8> b(tmp_b);
  for(int tmp_i = 0; tmp_i <= 256; tmp_i++) {
    bitset<8> c(tmp_i);
    if((a ^ c) == b) {
      cout << tmp_i << endl;
      return 0;
    }
  }
}