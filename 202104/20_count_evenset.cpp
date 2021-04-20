#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int count = 0;
  cin >> N;
  vector<int> v(N);
  for(int i = 0; i < N; i++) {
    cin >> v.at(i);
  }
  while(true) {
    for(int i = 0; i < N; i++) {
      if(v.at(i) % 2 == 0) {
        v.at(i) = v.at(i)/2;
      } else {
        cout << count << endl;
        return 0;
      }
    }
    count += 1;
  }
}