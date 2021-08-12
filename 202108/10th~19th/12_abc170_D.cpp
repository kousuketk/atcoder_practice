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
  vector<int> vec(N);
  map<int,int> mp;
  rep(i,N) {
    int tmp; cin >> tmp;
    vec[i] = tmp;
    mp[tmp]++;
  }
  sort(ALL(vec));
  int max_val = vec[N-1];
  vector<bool> is_prime(max_val+1);
  rep(i,max_val+1) is_prime[i] = true;
  for(int i = 0; i < N; i++) {
    int tmp = vec[i];
    if(is_prime[tmp]) {
      for(int j = 2*tmp; j <= max_val; j += tmp) is_prime[j] = false;
    }
  }
  // vecを前から見ていって、is_prime[i]=trueのものの個数
  int ans = 0;
  rep(i,N) {
    int tmp = vec[i];
    if(is_prime[tmp] && mp[tmp] == 1) ans++;
  }
  cout << ans << endl;
}

// エラトステネスの篩を使う