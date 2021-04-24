#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for(int i = 0; i < N; i++) {
    cin >> a.at(i);
  }

  int alice_sum = 0;
  int bob_sum = 0;
  int max_val;
  for(int i = 0; i < N; i++) {
    max_val = *max_element(a.begin(), a.end());
    if(i % 2 == 0) {
      alice_sum += max_val;
    } else {
      bob_sum += max_val;
    }
    auto itr = find(a.begin(), a.end(), max_val);
    a.erase(itr, itr+1);
  }
  cout << (alice_sum - bob_sum) << endl;
  return 0;
}