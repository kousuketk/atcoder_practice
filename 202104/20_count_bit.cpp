#include <bits/stdc++.h>
using namespace std;
 
int main() {
  bitset<3> a;
  cin >> a;
  int count = 0;
  for(int i=0; i<3; i++) {
    if(a.test(i)) {
      count += 1;
    }
  }
  cout << count << endl;
}