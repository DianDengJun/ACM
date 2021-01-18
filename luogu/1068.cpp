// https://www.luogu.com.cn/problem/P1068 [NOIP2009 普及组] 分数线划定
// STL sort
#include <algorithm>
#include <cstdio>

struct Player {
    int k;
    int s;
    bool operator<(const Player &right) const {
        if (s > right.s) {
            return true;
        } else if (s == right.s) {
            if (k < right.k)
                return true;
            else
                return false;
        } else
            return false;
    }
};

Player p[9005];

using namespace std;
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    m = m * 1.5;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &p[i].k, &p[i].s);
    }
    sort(p, p + n);

    // 找分数、最大人数
    printf("%d ", p[m - 1].s);
    for (int i = m - 1; i < n; i++) {
        if (p[i].s == p[m-1].s) {
            continue;
        } else {
            printf("%d\n", i);
            break;
        }
    }

    // 输出相应信息
    for (int i = 0; i < n; i++) {
        if (i < m) {
            printf("%d %d\n", p[i].k, p[i].s);
        } else if (p[i].s == p[m - 1].s) {
            printf("%d %d\n", p[i].k, p[i].s);
        } else {
            break;
        }
    }
    return 0;
}