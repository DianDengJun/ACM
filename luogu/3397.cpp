// https://www.luogu.com.cn/problem/P3397 地毯
// 差分前缀和

#include <cstdio>

using namespace std;
int arr[1000][1000];// 原始数组
int dp[1005][1005];// 前缀和

// 简单的思路是对每一行进行差分
void update(int x1, int y1, int x2, int y2) {
    for (int i = x1; i <= x2; i++) {
        dp[i][y1]++;
        dp[i][y2 + 1]--;
    }
}

// 二维差分前缀和做法
// void update(int x1, int y1, int x2, int y2) {
//     dp[x1][y1]++;
//     dp[x2 + 1][y1]--;
//     dp[x1][y2 + 1]--;
//     dp[x2 + 1][y2 + 1]++;
// }

int main() {
    int array[] = {1, 2, 3};
    int n, m;
    scanf("%d %d", &n, &m);
    int x1, y1, x2, y2;
    while (m--) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        update(x1, y1, x2, y2);
    }
    for (int i = 1; i <= n; i++) {
        auto sum{0};
        for (int j = 1; j <= n; j++) {
            sum += dp[i][j];
            arr[i][j] = sum;
            printf("%d%c", arr[i][j], j == n ? '\n' : ' ');
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++)
    //         printf("%d%c", dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1], j == n ? '\n' : ' ');
    // }
}