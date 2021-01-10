#include <algorithm>
#include <iostream>
using namespace std;

class Score {
private:
    int chinese{0};
    int math{0};
    int english{0};
    int total{0};

public:
    Score() = default;
    Score(int chinese, int math, int english) {
        this->chinese = chinese;
        this->math = math;
        this->english = english;
        total = chinese + math + english;
    }
    int getChinese() const {
        return chinese;
    }
    int getMath() const {
        return math;
    }
    int getEnglish() const {
        return english;
    }
    int getTotal() const {
        return total;
    }
};

class Student {
private:
    int ID{1};
    Score s{0, 0, 0};

public:
    Student() = default;
    Student(int ID, int chinese, int math, int english)
        : s{chinese, math, english} {
        this->ID = ID;
    }
    int getID() const {
        return ID;
    }
    Score getScore() const {
        return s;
    }
};

bool cmp(Student s1, Student s2) {
    if (s1.getScore().getTotal() > s2.getScore().getTotal())
        return true;
    else if (s1.getScore().getTotal() < s2.getScore().getTotal())
        return false;
    else {
        if (s1.getScore().getChinese() > s2.getScore().getChinese())
            return true;
        else if (s1.getScore().getChinese() < s2.getScore().getChinese())
            return false;
        else {
            if (s1.getID() > s2.getID())
                return false;
            else
                return true;
        }
    }
}

int main() {
    auto n{0};
    cin >> n;
    Student su[305];
    for (int i = 1; i <= n; i++) {
        auto chinese{0}, math{0}, english{0};
        cin >> chinese >> math >> english;
        su[i] = {i, chinese, math, english};
    }
    sort(su + 1, su + 1 + n, cmp);
    for (int i = 1; i <= 5; i++) {
        cout << su[i].getID() << " " << su[i].getScore().getTotal() << endl;
    }
    return 0;
}