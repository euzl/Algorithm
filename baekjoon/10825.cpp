#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct student {
    string name;
    int korean;
    int english;
    int math;
};

bool compare(student a, student b) {
    if (a.korean > b.korean) return true;
    else if (a.korean < b.korean) return false;

    if (a.english < b.english) return true;
    else if (a.english > b.english) return false;

    if (a.math > b.math) return true;
    else if (a.math < b.math) return false;

    if (a.name < b.name) return true;
    else return false;
}

void init(vector<student> &list)
{
    int size;
    cin >> size;

    string name;
    int k, e, m;
    for (int i=0; i<size; i++) {
        cin >> name >> k >> e >> m;
        list.push_back({name, k, e, m});
    }
}

int main(void)
{
    vector<student> list;

    init(list);
    sort(list.begin(), list.end(), compare);

    for (student s : list) {
        cout << s.name << '\n';
    }

    return 0;
}
