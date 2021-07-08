#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, a, b;
  cin >> N >> a >> b;
  int answer_sum = 0;
  for(int i = 1; i <= N; i++) {
    int sum = 0;
    int num = i;
    while(num) {
      sum += num % 10;
      num = num / 10;
    }
    if(sum >= a && sum <= b) {
      answer_sum += i;
    }
  }
  cout << answer_sum << endl;
  return 0;
}