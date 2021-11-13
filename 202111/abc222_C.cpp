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
  int N, M; cin >> N >> M;
  vector<string> vec(2*N);
  rep(i,2*N) {
    string s;
    rep(j,M) {
      char c; cin >> c;
      if(c == 'G') c = '0';
      if(c == 'C') c = '1';
      if(c == 'P') c = '2';
      s += c;
    }
    vec[i] = s;
  }
  vector<P> cnt_win(2*N); // 勝った回数, i番目(-番目)
  rep(i,2*N) cnt_win[i] = P(0, (-1)*i);
  rep(i,M) {
    rep(k,N) {
      int a = (-1)*cnt_win[2*k].second;
      int b = (-1)*cnt_win[2*k+1].second;
      int output_a = vec[a][i] - '0';
      int output_b = vec[b][i] - '0';
      int judge = (output_a-output_b+3) % 3;
      if(judge == 1) cnt_win[2*k+1].first++;
      else if(judge == 2) cnt_win[2*k].first++;
    }
    sort(ALL(cnt_win), greater());
  }
  rep(i,2*N) cout << (-1)*cnt_win[i].second + 1 << endl;
}