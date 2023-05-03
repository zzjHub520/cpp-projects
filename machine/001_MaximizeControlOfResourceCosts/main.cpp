#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <set>
#include <limits>

using namespace std;

int minCosts{0};

bool Compare(tuple<int, int, int> a, tuple<int, int, int> b) {
    if (get<0>(a) < get<0>(b)) {
        return true;
    } else if (get<0>(a) == get<0>(b)) {
        if (get<1>(a) < get<1>(b)) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

vector<tuple<int, int, int>> CalPublicRange(vector<tuple<int, int, int>> &vecRange) {
    set<tuple<int, int, int>> setPublicRange;
    sort(vecRange.begin(), vecRange.end(), Compare);
    for (int i = 0; i < vecRange.size(); ++i) {
        for (int j = i + 1; j < vecRange.size(); ++j) {
            int left = max(get<0>(vecRange[i]), get<0>(vecRange[j]));
            int right = min(get<1>(vecRange[i]), get<1>(vecRange[j]));
            if (left <= right) {
                tuple<int, int, int> tmp = make_tuple(left, right, get<2>(vecRange[i]) + get<2>(vecRange[j]));
                setPublicRange.insert(tmp);
                if (get<2>(vecRange[i]) + get<2>(vecRange[j]) > minCosts) {
                    minCosts = get<2>(vecRange[i]) + get<2>(vecRange[j]);
                }
            }
        }
    }
    vector<tuple<int, int, int>> vecPublicRange(setPublicRange.begin(), setPublicRange.end());
    return vecPublicRange;
}

int main() {
    vector<tuple<int, int, int>> vecTuple;
    int taskNum;
    cin >> taskNum;
    int left{INT32_MAX};
    int right{0};
    for (int i = 0; i < taskNum; ++i) {
        int startTime;
        int endTime;
        int paralleism;

        cin >> startTime >> endTime >> paralleism;
//        if (paralleism > minCosts) {
//            minCosts = paralleism;
//        }
        if (left > startTime) {
            left = startTime;
        }
        if (right < endTime) {
            right = endTime;
        }
        vecTuple.emplace_back(make_tuple(startTime, endTime, paralleism));
    }
    vector<vector<bool>> vecResult;
    int num{right - left + 1};
    sort(vecTuple.begin(), vecTuple.end(), Compare);
    for (auto &ele: vecTuple) {
        for (int i = 0; i < get<2>(ele); ++i) {
            vector<bool> vecBool(num, false);
            for (int idx = left; idx <= right; ++idx) {
                vecBool[idx-left] = true;
            }

        }
    }


    return 0;
}
