#include <string>
#include <vector>

using namespace std;
pair<int, int> left;
pair<int, int> right;
string mainHand;
    
string getHand(pair<int, int> o) {
    int ld, rd; // distance (left, right)
    ld = abs(left.first - o.first) + abs(left.second - o.second);
    rd = abs(right.first - o.first) + abs(right.second - o.second);
    if (ld < rd) {
        left = o;
        return "L";
    }
    else if (ld > rd) {
        right = o;
        return "R";
    }
    else {
        if (mainHand == "L") left = o;
        else right = o;
        return mainHand;
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    mainHand = hand == "left" ? "L" : "R";
    vector<pair<int, int>> coord = {{3,1}, {0,0}, {0,1}, {0,2}, {1,0}, {1,1}, {1,2}, {2,0}, {2,1}, {2,2}, {3,0}, {3,2}};
    left = make_pair(3, 0);
    right = make_pair(3, 2);
    
    for (int i=0; i<numbers.size(); i++) {
        if ((numbers[i] == 0) || (numbers[i]%3 == 2)) {
            answer += getHand(coord[numbers[i]]);
        } else if (numbers[i]%3 == 1) {
            answer += "L";
            left = coord[numbers[i]];
        } else {
            answer += "R";
            right = coord[numbers[i]];
        }
    }
    return answer;
}
