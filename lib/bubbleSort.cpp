#include <iostream>
using namespace std;

int main() {
    // 例 2: バブルソートによって、{c[1], c[2], ..., c[N]} を小さい順に並び替え、出力する
    int N, c[1009];
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> c[i];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N - i; j++) {
            if (c[j] > c[j + 1]) swap(c[j], c[j + 1]);
        }
    }
    for (int i = 1; i <= N; i++) cout << c[i] << endl;
    return 0;
}
