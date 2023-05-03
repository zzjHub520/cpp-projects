#include <iostream>
#include <list>
#include <map>

using namespace std;

int main() {
    map<int, pair<int, int>> inputMap;
    int headerAddress{100};
    int num{4};
    inputMap[0] = make_pair(4, -1);
    inputMap[100] = make_pair(1, 12309);
    inputMap[33218] = make_pair(3, 0);
    inputMap[12309] = make_pair(2, 33218);
    list<int> flist;
    for (int i = 0; i < num; ++i) {
        flist.push_back(inputMap[headerAddress].first);
        headerAddress=inputMap[headerAddress].second;
    }

    auto iIntermediate=flist.begin();
    int i=0;
    for (auto iter = flist.begin(); iter !=flist.end() ; ++iter) {
        if(i%2==1){
            iIntermediate++;
        }


        i++;
    }
    cout<< *iIntermediate;

    return 0;
}
