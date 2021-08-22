#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 2001001001;
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

vector<P> vec;
vector<P> vec_sorted;
vector<int> vec_x;
vector<P> vec_y; // それまでの(min, max)
int N;

// 最大値をaより大きくすることはできるか？
bool check(int a) {
  rep(i,N) {
    int x1 = vec[i].first;
    int y1 = vec[i].second;
    int tmp_x = x1 - a;
    auto itr = lower_bound(ALL(vec_x), tmp_x);
    int idx = itr - vec_x.begin();
    if(*itr != tmp_x && idx != 0) idx = idx-1;
    // vec_y[idx].first, secondを見て, y1-a >= first, y1+a <= secondのどちらかになればok
    int min_y = vec_y[idx].first;
    int max_y = vec_y[idx].second;
    if(y1-a >= min_y || y1+a <= max_y) return true;
  }
  return false;
}

int main() {
  cin >> N;
  vec.resize(N);
  vec_sorted.resize(N);
  vec_x.resize(N);
  vec_y.resize(N);
  rep(i,N) {
    int x, y; cin >> x >> y;
    vec[i].first = x; vec[i].second = y;
    vec_sorted[i].first = x; vec_sorted[i].second = y;
  }
  sort(ALL(vec_sorted));
  rep(i,N) {
    vec_x[i] = vec_sorted[i].first;
    if(i == 0) {
      vec_y[i].first = vec_sorted[i].second;
      vec_y[i].second = vec_sorted[i].second;
    } else {
      vec_y[i].first = min(vec_y[i-1].first, vec_sorted[i].second);
      vec_y[i].second = max(vec_y[i-1].second, vec_sorted[i].second);
    }
  }
  int left = 0;
  int right = INF;
  while(left+1 < right) {
    int mid = (left+right)/2;
    if(check(mid)) left = mid;
    else right = mid;
  }
  cout << left << endl;
  return 0;
}