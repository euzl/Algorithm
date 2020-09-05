#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    int place = 0;
    for (int i; i<seoul.size(); i++) {
        if (seoul[i] == "Kim") {
            place = i;
            break;
        }
    }
    return "김서방은 " + to_string(place) + "에 있다";
}
