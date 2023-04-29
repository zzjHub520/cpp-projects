#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

bool compare(tuple<int, int, int> a, tuple<int, int, int> b) {
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

int main() {
    vector<tuple<int, int, int>> vecTuple;
    int taskNum{0};
    cin >> taskNum;
    for (int i = 0; i < taskNum; ++i) {
        int startTime;
        int endTime;
        int paralleism;

        cin >> startTime >> endTime >> paralleism;
        tuple<int, int, int> tmp = make_tuple(startTime, endTime, paralleism);
        vecTuple.emplace_back(tmp);
    }

    sort(vecTuple.begin(), vecTuple.end(), compare);

    for (auto ele: vecTuple) {
        cout << get<0>(ele) << "  " << get<1>(ele) << "  " << get<2>(ele) << endl;
    }


    return 0;
}
