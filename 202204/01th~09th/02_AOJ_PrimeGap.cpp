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

const int MAX_N = 1299709;
bool is_prime[MAX_N+1];  // 素数かどうか
void sieve(int n) {
  for(int i = 0; i <= n; i++) is_prime[i] = true;
  is_prime[0] = is_prime[1] = false;
  for(int i = 2; i <= n; i++) {
    if(is_prime[i]) {
      for(int j = 2*i; j <= n; j += i) is_prime[j] = false;
    }
  }
}

int low_prime(int a) {  // aより小さい素数を返す
  a--;
  while(true) {
    if(is_prime[a]) return a;
    a--;
  }
}

int up_prime(int a) {  // aより大きい素数を返す
  a++;
  while(true) {
    if(is_prime[a]) return a;
    a++;
  }
}

int main() {
  sieve(MAX_N);
  int a; cin >> a;
  while(a != 0) {
    if(is_prime[a]) {
      cout << 0 << endl;
    } else {
      int l = low_prime(a);
      int r = up_prime(a);
      cout << (r-l) << endl;
    }
    cin >> a;
  }
  return 0;
}