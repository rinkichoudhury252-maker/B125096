#include <iostream>
using namespace std;

class Score {
    int score;

public:
    Score(int s = 0) : score(s) {}

    Score operator++() {
        ++score;
        return *this;
    }

    Score operator++(int) {
        Score temp = *this;
        score++;
        return temp;
    }

    void display() const {
        cout << score << endl;
    }
};

int main() {
    Score s1(10);

    Score prefixResult = ++s1;
    cout << "Prefix result: ";
    prefixResult.display();

    Score s2(10);

    Score postfixResult = s2++;
    cout << "Postfix result: ";
    postfixResult.display();

    cout << "Score after postfix: ";
    s2.display();

    return 0;
}