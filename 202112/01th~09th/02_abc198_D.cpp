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
  string s1, s2, s3; cin >> s1 >> s2 >> s3;
  string all_s;
  int size_s1 = s1.size();
  int size_s2 = s2.size();
  int size_s3 = s3.size();
  rep(i,size_s1) all_s += s1[i];
  rep(i,size_s2) all_s += s2[i];
  rep(i,size_s3) all_s += s3[i];
  sort(all_s.begin(), all_s.end());
  all_s.erase(unique(all_s.begin(), all_s.end()), all_s.end());
  if(all_s.size() > 10) {
    cout << "UNSOLVABLE" << endl;
    return 0;
  }
  // all_sが10個数ないときは、関係ない要素を足していく必要がある。
  int num = 48;
  while(all_s.size() < 10) {
    all_s += char(num++);
  }
  sort(all_s.begin(), all_s.end());
  do {
    string new_s1, new_s2, new_s3;
    rep(i,size_s1) {
      int idx = all_s.find(s1[i]);
      new_s1 += to_string(idx);
    }
    if(new_s1[0] == '0') continue;
    ll n1 = stoll(new_s1);
    rep(i,size_s2) {
      int idx = all_s.find(s2[i]);
      new_s2 += to_string(idx);
    }
    if(new_s2[0] == '0') continue;
    ll n2 = stoll(new_s2);
    rep(i,size_s3) {
      int idx = all_s.find(s3[i]);
      new_s3 += to_string(idx);
    }
    if(new_s3[0] == '0') continue;
    ll n3 = stoll(new_s3);
    if((n1 + n2) == n3) {
      cout << n1 << endl;
      cout << n2 << endl;
      cout << n3 << endl;
      return 0;
    }
  }while(next_permutation(all_s.begin(), all_s.end()));
  cout << "UNSOLVABLE" << endl;
  return 0;
}
// →なんでTLEするのかわからない...