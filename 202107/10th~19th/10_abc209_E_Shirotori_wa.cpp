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
  vector<string> vec(N);
  vector<string> vec_dic(N);
  rep(i,N) {
    string s;
    cin >> s;
    vec[i] = s;
    vec_dic[i] = s;
  }
  sort(vec_dic.begin(), vec_dic.end());
  for(int i = 0; i < N; i++) {
    string str = vec[i].substr(vec[i].length()-3, 3);
    int j = 0;
    while(true) {
      auto itr = lower_bound(vec_dic.begin(), vec_dic.end(), str);
      if(j > 10) {
        cout << "Draw" << endl;
        break;
      }
      int idx = itr - vec_dic.begin();
      if(itr == vec_dic.end() || str != vec_dic[idx].substr(0, 3)) {
        if(j % 2 == 0) {
          cout << "Takahashi" << endl;
          break;
        } else {
          cout << "Aoki" << endl;
          break;
        }
      }
      // itrのvec_dicの最初の3文字が合ってる検証
      str = vec_dic[idx].substr(vec_dic[idx].length()-3, 3);
      j++;
    }
  }
}

// N<=10^5だから、O(NlogN)な気がするけど、logNでどちらが勝つかわからない