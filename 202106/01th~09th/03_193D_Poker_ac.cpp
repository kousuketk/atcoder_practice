#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

ll f(string s) {
  map<int, int> dic_tmp = {{1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}, {7,0}, {8,0}, {9,0}};
  for(int i = 0; i <= 4; i++) {
    dic_tmp[(s[i] - '0')]++;
  }
  auto itr = dic_tmp.begin();
  ll score = 0;
  while(itr != dic_tmp.end()) {
    if(itr->second > 0) score += itr->first * pow(10, itr->second);
    else score += itr->first;
    itr++;
  }
  return score;
}

int main() {
  int K;
  string s, t;
  cin >> K >> s >> t;
  s.erase(4);
  t.erase(4);
  map<int, int> dic {{1,K}, {2,K}, {3,K}, {4,K}, {5,K}, {6,K}, {7,K}, {8,K}, {9,K}}; 
  for(int i = 0; i < 4; i++) {
    dic[(s[i] - '0')]--;
    dic[(t[i] - '0')]--;
  }
  ll all_count_a = 9*K-8;
  ll all_count_b = 9*K-9;
  ll cnt = 0;
  for(int i = 1; i <= 9; i++) {
    for(int j = 1; j <= 9; j++) {
      if(dic[i] <= 0 || dic[j] <= 0) continue;
      if(i == j && dic[i] <= 1) continue;
      string tmp_s = s + to_string(i);
      string tmp_t = t + to_string(j);
      if((f(tmp_s) > f(tmp_t))) {
        if(i == j) cnt += (ll)dic[i]*(dic[i]-1);
        else cnt += (ll)dic[i]*dic[j];
      }
    }
  }
  double ans = (double)cnt/(all_count_a*all_count_b);
  cout << ans << endl;
}