#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> nums(N);
  vector<int> P(N);
  vector<int> Q(N);
  rep(i, N) nums.at(i) = i+1;
  rep(i, N) cin >> P.at(i);
  rep(i, N) cin >> Q.at(i);
  int count = 1;
  int a, b;
  do {
    if(equal(nums.cbegin(), nums.cend(), P.cbegin())) a = count;
    if(equal(nums.cbegin(), nums.cend(), Q.cbegin())) b = count;
    count++;
  } while (next_permutation(nums.begin(), nums.end()));
  cout << abs(a-b) << endl;
}