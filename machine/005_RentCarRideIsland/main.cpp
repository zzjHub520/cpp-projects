#include <iostream>
#include <limits.h>
#include <vector>
#include <set>

using namespace std;

int main() {
    int num{0};
    int m = 6;
    int n = 4;
    multiset<int> mset{6, 5, 4, 3, 2, 1};
    while (!mset.empty()) {
        int a = *mset.begin();
        mset.erase(mset.begin());
        if (!mset.empty()) {
            auto iter = mset.lower_bound(m - a);
            int b = *iter;
            if (b <= m - a) {
                mset.erase(iter);
            }
        }
        num++;
    }
    cout << num;


    return 0;
}
