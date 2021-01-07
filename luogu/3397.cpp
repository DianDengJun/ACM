//https://www.luogu.com.cn/problem/P3397 地毯
//二维前缀和

#include <cstdio>

using namespace std;
int arr[1000][1000];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int x1, y1, x2, y2;
    while (m--) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for (int i = x1 - 1; i < x2; i++)
            for (int j = y1 - 1; j < y2; j++)
                arr[i][j]++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}