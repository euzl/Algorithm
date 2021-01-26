#include <iostream>
#include <string>
#include <vector>
using namespace std;

void merging(vector<pair<int, string>>& userList, int start, int end) {
    vector<pair<int, string>> temp;

    int l, r;
    int barrier = (start + end) / 2;
    l = start; // 왼쪽배열
    r = barrier + 1; // 오른쪽 배열

    while (l <= barrier && r <= end) {
//        cout << userList[l].first << ',' << userList[l].second << endl;
//        cout << userList[r].first << ',' << userList[r].second << endl;
        temp.push_back(userList[l].first <= userList[r].first ? userList[l++] : userList[r++]);
//        cout << temp.back().first << ',' << temp.back().second << endl << endl;
    }

    while (l <= barrier) {
        temp.push_back(userList[l++]);
    }
    while (r <= end) {
        temp.push_back(userList[r++]);
    }

    for (int i=0; i <= end-start; i++) {
        userList[i + start] = temp[i]; // 원래 리스트 변
    }
}

void mergeSort(vector<pair<int, string>>& userList, int start, int end) {
    if (start == end) return;
    int barrier = (start + end)/2;
    mergeSort(userList, start, barrier);
    mergeSort(userList, barrier + 1, end);
    merging(userList, start, end);
}

int main() {
    int size = 0;
    cin >> size;

    vector<pair<int, string>> userList;

    int a;
    string n;
    for (int i=0; i<size; i++) {
        cin >> a >> n;
        userList.push_back({a, n});
    }

    mergeSort(userList, 0, size-1);

    for (int i = 0; i<size; i++) {
        cout << userList[i].first << ' ' << userList[i].second << '\n';
    }

    return 0;
}
