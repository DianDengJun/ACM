// https://www.cnblogs.com/-Ackerman/p/11162651.html
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    int m, n, k;
    cout << "输入矩阵行数:";
    cin >> n;
    cout << "输入矩阵列数:";
    cin >> m;
    int dp[n + 1][m + 1];
    int map[n + 1][m + 1];
    cout << "请输入矩阵:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }
    memset(dp, 0, sizeof(dp));
    // 预处理
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + map[i][j];
        }
    }
    cout << "请输入操作的次数:";
    cin >> k;
    // 接受查询
    for (int i = 1; i <= k; i++) {
        int x1, x2, y1, y2;
        cout << "请输入区间dp[x1,x2]~dp[x2,y2]:";
        cin >> x1 >> y1 >> x2 >> y2;
        cout << "结果是:" << (dp[x2][y2] + dp[x1 - 1][y1 - 1] - dp[x1 - 1][y2] - dp[x2][y1 - 1]) << endl;
    }
    return 0;
}