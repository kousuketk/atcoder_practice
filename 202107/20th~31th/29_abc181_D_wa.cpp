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
  string s; cin >> s;
  vector<int> vec_8;
  if(s.size() == 1) {
    if(s == "8") cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
  }
  if(s.size() == 2) {
    if(stoi(s) % 8 == 0) {
      cout << "Yes" << endl;
      return 0;
    }
    swap(s[0], s[1]);
    if(stoi(s) % 8 == 0) {
      cout << "Yes" << endl;
      return 0;
    }
    cout << "No" << endl;
    return 0;
  }
  for(int i = 1; i < 1000; i++) {
    if(i % 8 == 0) vec_8.push_back(i);
  }
  sort(s.begin(), s.end());
  bool ans_flag = false;
  for(int k : vec_8) {
    string tmp_s = s;
    string string_8 = to_string(k);
    bool flag = true;
    for(char c : string_8) {
      // 全てのcがtmp_sにあるか調べる
      auto itr = lower_bound(tmp_s.begin(), tmp_s.end(), c);
      if(c == 0 || *itr != c) {
        flag = false;
        break;
      } else {
        tmp_s.erase(itr, itr+1);
      }
    }
    if(flag) {
      ans_flag = true;
      break;
    }
  }
  if(ans_flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}