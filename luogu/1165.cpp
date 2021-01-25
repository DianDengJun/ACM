// https://www.luogu.com.cn/problem/P1165 日志分析
// STL Stack
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
stack<int> s1; // 主栈，记录数据
stack<int> s2; // 辅助栈，同时记录第i数据前的最大值
// 
int main() {
    int n;
    scanf("%d", &n);
    int a, b;// a操作:0入库,1出库,2查询,b入库重量
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a == 0) {
            scanf("%d", &b);
            s1.push(b);
            if (s2.empty() || b > s2.top())
                s2.push(b);
            else
                s2.push(s2.top());
        } else if (a == 1) {
            s1.pop();
            s2.pop();
        } else if (a == 2) {
            printf("%d\n", s1.empty() ? 0 : s2.top());
        }
    }
    return 0;
}