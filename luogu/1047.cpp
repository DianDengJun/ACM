// https://www.luogu.com.cn/problem/P1047 P1047 校门外的树
// 模拟

#include <cstdio>
#include <cstring>

using namespace std;
int flag[10005];

int main() {
    auto l{0},m{0};
    scanf("%d %d",&l,&m);
    auto u{0},v{0};
    // 将flag[u~v]设为-1,表明它是要挖掉的树
    while (m--) {
        scanf("%d %d",&u,&v);
        memset(flag+u,-1,(v-u+1)*sizeof(int));
    }
    auto leave{0};
    // flag[i] == 0, 那么就是留下的树
    for (int i = 0; i <= l; i++) {
        if (flag[i] == 0)
            leave++;
    }
    printf("%d\n",leave);
    return 0;
}