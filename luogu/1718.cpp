// https://www.luogu.com.cn/problem/P1781 宇宙总统
// STL sort
// 本题要注意的是，票数会有100位数字，用long long也不行，可以考虑用C++的string类解决
// 查看long long最大/小值：头文件limits.h中的LLMAX和LLMIN

#include <algorithm>
#include <array>
#include <iostream>
using namespace std;

class President {
private:
    int id{0};
    string polls{"0"};

public:
    President() = default;
    President(int id, string polls) {
        this->id = id;
        this->polls = polls;
    }
    bool operator<(const President &right) const {
        if (polls.size() > right.polls.size() || (polls > right.polls && polls.size() >= right.polls.size()))
            return true;
        else
            return false;
    }
    string toString() {
        return to_string(id) + '\n' + polls;
    }
};


int main() {
    auto n{0};
    cin >> n;
    array<President, 20> p;
    string polls{"0"};
    for (int i = 0; i < n; i++) {
        cin >> polls;
        p[i] = President{i + 1, polls};
    }
    sort(p.begin(), p.begin() + n);
    cout << p.at(0).toString() << endl;
    return 0;
}