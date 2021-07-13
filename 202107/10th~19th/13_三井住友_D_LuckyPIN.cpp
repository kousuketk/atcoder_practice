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

int main() {
  int N; cin >> N;
  string s; cin >> s;
  int ans = 0;
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      for(int k = 0; k < 10; k++) {
        // sを前から見てi, j, kがあればans++していく
        int flag = 0;
        for(int l = 0; l < s.size(); l++) {
          if(flag == 0 && s[l] == i + '0') {
            flag = 1;
          } else if(flag == 1 && s[l] == j + '0') {
            flag = 2;
          } else if(flag == 2 && s[l] == k + '0') {
            ans++;
            break;
          }
        }
      }
    }
  }
  cout << ans << endl;
}