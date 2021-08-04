#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<ll,ll>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
// const int INF = 1001001001;
const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

bool is_prime[MAX_L];  // 素数判定する区間の長さ(例, b-a+1)
bool is_prime_small[MAX_SORT_B];  // Bまでの素数を求めるとき√bまでの値を見れば、Bまでの素数判定ができる

// Nまでの素数をans_vecに入れていく
void eratosthenes(int N) {
  for(int i = 0; i*i <= b; i++) is_prime_small[i] = true;  // とりあえず全部trueにしておく
  for(int i = 0; i < b-a; i++) is_prime[i] = true;  // とりあえず全部trueにしておく
  
  for(int i = 2; i*i < b; i++) {
    if(is_prime_small[i]) {
      for(int j = 2*i; j*j < b; j += i) is_prime_small[j] = false;  // 倍数をfalseにしていく
      for(int j = max(2LL, (a+i-1)/i)*i; j < b; j += i) is_prime[j-a] = false;  // 倍数をfalseにしていく
    }
  }
}

// 蜂本p113, 区間篩