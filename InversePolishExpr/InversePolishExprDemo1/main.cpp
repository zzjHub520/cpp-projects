#include <iostream>

using namespace std;

bool IsDigit(const char &c) {
    if ('0' <= c && c <= '9') {
        return true;
    }
    return false;
}

double Calc(const string &exprStr);

double SubCalc(const string &exprStr, int idx, const char &op) {
    string subStrL = exprStr.substr(0, idx);
    string subStrR = exprStr.substr(idx + 1);
    switch (op) {
        case '+':
            return Calc(subStrL) + Calc(subStrR);
        case '-':
            return Calc(subStrL) - Calc(subStrR);
        case '*':
            return Calc(subStrL) * Calc(subStrR);
        case '/':
            return Calc(subStrL) / Calc(subStrR);
        default:
            return 0.0;
    }
}

double Calc(const string &exprStr) {
    int startIdx = exprStr.find_last_of('(');
    if (startIdx != string::npos) {
        int endIdx = exprStr.substr(startIdx).find_first_of(')') + startIdx;
        string subStrL = exprStr.substr(0, startIdx);
        string subStrR = exprStr.substr(endIdx + 1);
        string subStrData = exprStr.substr(startIdx + 1, endIdx - startIdx - 1);
        return Calc(subStrL + to_string(Calc(subStrData)) + subStrR);
    }

    string opList{"-+*/"};
    for (auto &op: opList) {
        int idx = exprStr.find_first_of(op);
        if (idx != string::npos && idx != 0 && IsDigit(exprStr[idx - 1])) {
            return SubCalc(exprStr, idx, op);
        }
    }

    return stod(exprStr);

}

int main() {
    string str{"((1+2))*(3+4)"};
    cout << Calc(str);
    return 0;
}
