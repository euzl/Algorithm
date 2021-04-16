#include <iostream>
#include <string>
#include <vector>
using namespace std;
string king;
int a, b;
struct Person {
    string name;
    string mom, dad;
};

vector<Person> people;

int getIndex(string p) {
    for (int i=0;i<a;i++) {
        if (people[i].name == p) {
            return i;
        }
    }
    return -1;
}

double isLoyal(string p) {
    if (p == king) return 1;
    int idx = getIndex(p);
    if (idx == -1) {
        return 0;
    }
    double mommy = isLoyal(people[idx].mom);
    double daddy = isLoyal(people[idx].dad);
    return (mommy+daddy)/2;
}

int main() {
    cin >> a >> b;
    cin >> king;

    string p1, p2, p3;
    for (int i=0; i<a; i++) {
        cin >> p1 >> p2 >> p3;
        people.push_back({p1, p2, p3});
    }
    string wanna;
    double percent;
    string son;
    double max = 0;
    for (int i=0; i<b; i++) {
        cin >> wanna;
        percent = isLoyal(wanna);
        if (percent > max) {
            son = wanna;
            max = percent;
        }
    }

    cout << son;

    return 0;
}
