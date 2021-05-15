#include<bits/stdc++.h>
using namespace std;
int main(){
  int N; cin >> N;
  vector<pair<int,string>> data(N);
  for(int i=0; i<N; i++) cin >> data[i].second >> data[i].first;
  sort(data.begin(),data.end(),greater());
  cout << data[1].second << endl;
}