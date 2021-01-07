// https://www.cnblogs.com/-Ackerman/p/11162651.html
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    int m, n, k;
    cout << "�����������:";
    cin >> n;
    cout << "�����������:";
    cin >> m;
    int dp[n + 1][m + 1];
    int map[n + 1][m + 1];
    cout << "���������:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }
    memset(dp, 0, sizeof(dp));
    // Ԥ����
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + map[i][j];
        }
    }
    cout << "����������Ĵ���:";
    cin >> k;
    // ���ܲ�ѯ
    for (int i = 1; i <= k; i++) {
        int x1, x2, y1, y2;
        cout << "����������dp[x1,x2]~dp[x2,y2]:";
        cin >> x1 >> y1 >> x2 >> y2;
        cout << "�����:" << (dp[x2][y2] + dp[x1 - 1][y1 - 1] - dp[x1 - 1][y2] - dp[x2][y1 - 1]) << endl;
    }
    return 0;
}