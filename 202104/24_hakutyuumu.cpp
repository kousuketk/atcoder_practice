#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> &vec) {
  cout << "";
  for (auto itr = vec.begin(); itr != vec.end(); itr++) {
    cout << *itr << " "; 
  }
  cout << endl;
}

int main() {
  string S;
  cin >> S;
  while(S.find("eraser") != string::npos) {
    auto index = S.find("eraser");
    S.erase(index, 6);
  }
  while(S.find("erase") != string::npos) {
    auto index = S.find("erase");
    S.erase(index, 5);
  }
  while(S.find("dreamer") != string::npos) {
    auto index = S.find("dreamer");
    S.erase(index, 7);
  }
  while(S.find("dream") != string::npos) {
    auto index = S.find("dream");
    S.erase(index, 5);
  }
  if(S == "") {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}