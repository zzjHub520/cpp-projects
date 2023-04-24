#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

bool compare(tuple<int,int,int> a, tuple<int,int,int> b){
    if(get<0>(a) < get<0>(b)){
        return true;
    } else if(get<0>(a) == get<0>(b)){
        if(get<1>(a) < get<1>(b)){
            return true;
        } else{
            return false;
        }
    } else{
        return false;
    }
}

int main() {
    vector<tuple<int,int,int>> vecTuple;
    int taskNum{0};
    cin>>taskNum;
    for (int i = 0; i < taskNum; ++i) {
        int startTime;
        int endTime;
        int paralleism;

        cin >> startTime >> endTime >> paralleism;
        tuple<int,int,int> tmp =  make_tuple(startTime, endTime, paralleism);
        vecTuple.emplace_back(tmp);
    }

    sort(vecTuple.begin(), vecTuple.end(), compare);

    for(auto ele : vecTuple){
        cout << get<0>(ele) << "  " << get<1>(ele) << "  " << get<2>(ele) << endl;
    }



    return 0;
}


//public static ArrayList<ArrayList<Integer>> cal_public_range(ArrayList<ArrayList<Integer>> ranges) {
//    //先排序
//    Comparator<ArrayList<Integer>> myComparator = new Comparator<ArrayList<Integer>>() {
//        @Override
//        public int compare(ArrayList<Integer> o1, ArrayList<Integer> o2) {
//            if (o1.get(0)!=o2.get(0)){
//                return o1.get(0)-o2.get(0);
//            }else {
//                return o1.get(1)-o2.get(2);
//            }
//        }
//    };
//    Collections.sort(ranges, myComparator);
//
//    //求交集
//    ArrayList<ArrayList<Integer>> public_range = new ArrayList<ArrayList<Integer>> ();
//    for (int i=0;i<ranges.size();i++) {
//        for (int j=i+1;j<ranges.size();j++) {
//            int left = Math.max(ranges.get(i).get(0), ranges.get(j).get(0));
//            int right = Math.min(ranges.get(i).get(1), ranges.get(j).get(1));
//            if (left <= right) {
//                ArrayList<Integer> temp = new ArrayList<Integer>();
//                temp.add(left);
//                temp.add(right);
//                temp.add(ranges.get(i).get(2)+ ranges.get(j).get(2));
//                public_range.add(temp);
//                if (ranges.get(i).get(2)+ ranges.get(j).get(2) > max_machine) {
//                    max_machine = ranges.get(i).get(2)+ ranges.get(j).get(2);
//                }
//            }
//        }
//    }
//    return public_range;
//}