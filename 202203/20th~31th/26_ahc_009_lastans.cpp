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

string hj[20];
string vi[19];
int dist[20][20];

void calc_min_cost(int si, int sj) {
  queue<P> que;
  dist[si][sj] = 0;
  que.push(P(si, sj));
  while(!que.empty()) {
    P tmp = que.front();
    que.pop();
    int i = tmp.first;
    int j = tmp.second;
    if(i != 0 && vi[i-1][j] != '1' && dist[i-1][j] == -1) {  // 上にいく
      dist[i-1][j] = dist[i][j] + 1;
      que.push(P(i-1, j));
    }
    if(i != 19 && vi[i][j] != '1' && dist[i+1][j] == -1) {  // 下にいく
      dist[i+1][j] = dist[i][j] + 1;
      que.push(P(i+1, j));
    }
    if(j != 0 && hj[i][j-1] != '1' && dist[i][j-1] == -1) {  // 左にいく
      dist[i][j-1] = dist[i][j] + 1;
      que.push(P(i, j-1));
    }
    if(j != 19 && hj[i][j+1] != '1' && dist[i][j+1] == -1) {  // 右にいく
      dist[i][j+1] = dist[i][j] + 1;
      que.push(P(i, j+1));
    }
  }
}

int cnt_kabe(int ti, int tj) {
  int cost = dist[ti][tj];
  int nowi = ti;
  int nowj = tj;
  int res = 0;
  for(int _ = cost; _ >= 0; _--) {
    if(nowi != 0 && dist[nowi-1][nowj] == cost-1) nowi--;
    else if(nowi != 19 && dist[nowi+1][nowj] == cost-1) nowi++;
    else if(nowj != 0 && dist[nowi][nowj-1] == cost-1) nowj--;
    else if(nowj != 19 && dist[nowi][nowj+1] == cost-1) nowj++;
    cost--;
    if(nowi == 0 || vi[nowi-1][nowj] == '1') res += 1;
    else if(nowi == 19 || vi[nowi+1][nowj] == '1') res += 1;
    else if(nowj == 0 || vi[nowi][nowj-1] == '1') res += 1;
    else if(nowj == 19 || vi[nowi][nowj+1] == '1') res += 1;
  }
  return res;
}

string create_str(int ti, int tj, int cnt_kabe_per = 0, int cnt_kabe_surplus = 0) {
  int cost = dist[ti][tj];
  int nowi = ti;
  int nowj = tj;
  string res = "";
  for(int _ = cost; _ >= 0; _--) {
    if(nowi != 0 && dist[nowi-1][nowj] == cost-1) res += "D", nowi--;
    else if(nowi != 19 && dist[nowi+1][nowj] == cost-1) res += "U", nowi++;
    else if(nowj != 0 && dist[nowi][nowj-1] == cost-1) res += "R", nowj--;
    else if(nowj != 19 && dist[nowi][nowj+1] == cost-1) res += "L", nowj++;
    cost--;
    // 壁があったら指定の回数当たる
    if(nowi == 0 || vi[nowi-1][nowj] == '1') {
      if(cnt_kabe_surplus > 0) res += string(cnt_kabe_per+1, 'U'), cnt_kabe_surplus--;
      else res += string(cnt_kabe_per, 'U');
    } else if(nowi == 19 || vi[nowi+1][nowj] == '1') {
      if(cnt_kabe_surplus > 0) res += string(cnt_kabe_per, 'D'), cnt_kabe_surplus--;
      else res += string(cnt_kabe_per, 'D');
    } else if(nowj == 0 || vi[nowi][nowj-1] == '1') {
      if(cnt_kabe_surplus > 0) res += string(cnt_kabe_per, 'L'), cnt_kabe_surplus--;
      else res += string(cnt_kabe_per, 'L');
    } else if(nowj == 19 || vi[nowi][nowj+1] == '1') {
      if(cnt_kabe_surplus > 0) res += string(cnt_kabe_per, 'R'), cnt_kabe_surplus--;
      else res += string(cnt_kabe_per, 'R');
    }
  }
  reverse(ALL(res));
  return res;
}

int main() {
  int si, sj, ti, tj; cin >> si >> sj >> ti >> tj;
  double p; cin >> p;
  rep(i,20) cin >> hj[i];
  rep(i,19) cin >> vi[i];
  rep(i,20) rep(j,20) dist[i][j] = -1;
  calc_min_cost(si, sj);  // 最短経路距離を求める
  // cout << dist[ti][tj] << endl;
  string min_str = create_str(ti, tj);
  int cnt_min_kabe = cnt_kabe(ti, tj);
  int cnt_rest = 200 - (int)min_str.size();
  int cnt_kabe_per = cnt_rest / cnt_min_kabe;
  int cnt_kabe_surplus = cnt_rest % cnt_min_kabe;
  string ans = create_str(ti, tj, cnt_kabe_per, cnt_kabe_surplus);
  cout << ans << endl;
}


// 余剰を使ってあまりの部分まで壁の方向を埋めたのにスコアが上がらなかったのなんでだ.....