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

ll vec[18][18];
int arrayv[18];
bool used[18];
ll ans = 0;
int min_val = 1;

void dfs(int pos, int n) {
  if(pos == 2*n) {
    // arrayvの順番で処理する
    vector<ll> tmp_vec;
    rep(i,n) {
      int idx_i = arrayv[2*i];
      int idx_j = arrayv[2*i+1];
      idx_i--, idx_j--;
      ll a = vec[idx_i][idx_j];
      tmp_vec.push_back(a);
    }
    ll tmp_val = tmp_vec[0];
    rep(i,n-1) tmp_val = tmp_val ^ tmp_vec[i+1];
    ans = max(ans, tmp_val);
    return;
  }
  // ここのpos%2==0の時に、min_valで固定してacした...
  if(pos%2==0) {
    arrayv[pos] = min_val;
    used[min_val] = true;
    int tmp_min_val = min_val;
    for(int i = 1; i <= 2*n; i++) {
      if(!used[i]) {
        min_val = i;
        break;
      }
    }
    dfs(pos + 1, n);
    min_val = tmp_min_val;
    used[min_val] = false;
    return;
  }
  for(int i = 1; i <= 2*n; i++) {
    if(!used[i]) {
      if(pos == 0 && i != 1) continue;
      if((pos>1) && (pos%2==0) && (arrayv[pos-2]>i)) continue;
      if((pos%2==1) && (arrayv[pos-1]>i)) continue;
      arrayv[pos] = i;
      used[i] = true;
      if(i == min_val) {
        for(int j = i; j <= 2*n; j++) {
          if(!used[j]) {
            min_val = j;
            break;
          }
        }
      }
      dfs(pos + 1, n);
      if(i < min_val) min_val = i;
      used[i] = false;
    }
  }
}

int main() {
  int N; cin >> N;
  rep(i,2*N) {
    rep(j,2*N) {
      if(j <= i) vec[i][j] = 0;
      else cin >> vec[i][j];
    }
  }
  dfs(0, N);
  cout << ans << endl;
}

// →普通にやると、16!通りでtleだけど、min_valを指定してあげることで、15*13*11*9*7*5*3*1→10^6となり、間に合う