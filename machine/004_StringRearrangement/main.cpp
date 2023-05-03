#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(pair<char, int> &a, pair<char, int> &b) {
    if (a.second > b.second) {
        return true;
    } else if (a.second == b.second) {
        int af{a.first}, bf{b.first};
        if ('A' <= a.first && a.first <= 'Z') {
            af = a.first - 'A' + 'z' + 1;
        }
        if ('A' <= b.first && b.first <= 'Z') {
            bf = b.first - 'A' + 'z' + 1;
        }
        if (af <= bf) {
            return true;
        }
        return false;
    } else {
        return false;
    }
}

int main() {
    string str{"xyxyXX"};
    map<char, int> mp;
    for (auto &ele: str) {
        mp[ele] = mp[ele] + 1;
    }
    vector<pair<char, int>> vecResult(mp.begin(), mp.end());
    sort(vecResult.begin(),vecResult.end(), Compare);
    for(auto &ele:vecResult){
        cout<<ele.first<<':'<<ele.second<<';';
    }

    return 0;
}
