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
  int K;
  string s, t;
  cin >> K >> s >> t;
  map<int, int> dic_s {{1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}, {7,0}, {8,0}, {9,0}};
  map<int, int> dic_t {{1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}, {7,0}, {8,0}, {9,0}};
  map<int, int> dic_all {{1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}, {7,0}, {8,0}, {9,0}};
  for(int i = 0; i < 4; i++) {
    dic_s[(s[i] - '0')]++;
    dic_t[(t[i] - '0')]++;
    dic_all[(s[i] - '0')]++;
    dic_all[(t[i] - '0')]++;
  }
  auto itr_all = dic_all.begin();
  vector<int> vec;
  while(itr_all != dic_all.end()) {
    if(K - itr_all->second == 1) vec.push_back(itr_all->first); 
    else if(K - itr_all->second >= 2) {
      vec.push_back(itr_all->first);
      vec.push_back(itr_all->first);
    }
    itr_all++;
  }

  ll score_s = 0, score_t = 0;
  ll count = 0, count_s = 0;
  for(int i = 0; i < vec.size(); i++) {
    for(int j = 0; j < vec.size(); j++) {
      if(i == j) continue;
      int tmp_s = vec[i];
      int tmp_t = vec[j];
      // tmp_t番目
      // dic_sにtmp_sを反映する, tも
      dic_s[tmp_s]++;
      dic_t[tmp_t]++;
      auto itr_s = dic_s.begin();
      while(itr_s != dic_s.end()) {
        if(itr_s->second > 0) score_s += itr_s->first * pow(10, itr_s->second);
        else score_s += itr_s->first;
        itr_s++;
      }
      auto itr_t = dic_t.begin();
      while(itr_t != dic_t.end()) {
        if(itr_t->second > 0) score_t += itr_t->first * pow(10, itr_t->second);
        else score_t += itr_t->first;
        itr_t++;
      }
      count++;
      // if(score_s > score_t)
      // 反映を戻す
    }
  }
  // auto itr_s = dic_s.begin();
  // while(itr_s != dic_s.end()) {
  //   if(itr_s->second > 0) score_s += itr_s->first * pow(10, itr_s->second);
  //   else score_s += itr_s->first;
  //   itr_s++;
  // }
  // auto itr_t = dic_t.begin();
  // while(itr_t != dic_t.end()) {
  //   if(itr_t->second > 0) score_t += itr_t->first * pow(10, itr_t->second);
  //   else score_t += itr_t->first;
  //   itr_t++;
  // }
  // dic_allについて、K以下のものを検討する(90通り)
  // K-(itr_t->second) = 0 だったら無視, 1だったら1つ, 2以上だったら2つ
  // 重複ありのvecに入れて
  // cout << score_s << " " << score_t << endl;
  // cout << dic_s[1] << endl;
  // cout << dic_t[2] << endl;
}