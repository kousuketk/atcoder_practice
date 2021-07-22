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
  int N; cin >> N;
  vector<string> s(N);
  rep(i,N) {
    string tmp; cin >> tmp;
    reverse(tmp.begin(), tmp.end());
    s[i] = tmp;
  }
  sort(s.begin(), s.end());
  for(int i = 1; i < N; i++) {
    if((s[i-1]+'!') == s[i]) {
      reverse(s[i-1].begin(), s[i-1].end());
      cout << s[i-1] << endl;
      return 0;
    }
  }
  cout << "satisfiable" << endl;
}