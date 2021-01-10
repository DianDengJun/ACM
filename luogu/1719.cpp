// https://www.luogu.com.cn/problem/P1719 最大加权矩形
// 二维前缀和

#include <algorithm>
#include <iostream>
using namespace std;

int map[200][200];// 原始数组
int dp[200][200]; // 前缀和

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + map[i][j];
        }
    }
    auto myMax{-1000000};
    for (int x1 = 1; x1 <= n; x1++)
        for (int y1 = 1; y1 <= n; y1++)
            for (int x2 = x1; x2 <= n; x2++)
                for (int y2 = y1; y2 <= n; y2++)
                    myMax = max(myMax, dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]);

    cout << myMax << endl;
    return 0;
}