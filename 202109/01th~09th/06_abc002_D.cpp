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
  int N; cin >> N;
  vector<int> vec_p(N);
  rep(i,N) cin >> vec_p[i];
  vector<int> vec_q(N);
  rep(i,N) cin >> vec_q[i];

  vector<int> vec(N);
  rep(i,N) vec[i] = i+1;
  int num = 0;
  int a, b;
  do {
    num++;
    int cnt_p = 0;
    int cnt_q = 0;
    rep(i,N) {
      if(vec[i] == vec_p[i]) cnt_p++;
      if(vec[i] == vec_q[i]) cnt_q++;
    }
    if(cnt_p == N) a = num;
    if(cnt_q == N) b = num;
  }while(next_permutation(ALL(vec)));
  cout << abs(a-b) << endl;
}