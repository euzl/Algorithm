#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    switch (a) {
        case 1:
            break;
        case 12:
            b += 30;
        case 11:
            b += 31;
        case 10:
            b += 30;
        case 9:
            b += 31;
        case 8:
            b += 31;
        case 7:
            b += 30;
        case 6:
            b += 31;
        case 5:
            b += 30;
        case 4:
            b += 31;
        case 3:
            b += 29;
        case 2:
            b += 31;
            break;
    }
    switch (b%7) {
        case 0:
            answer = "THU";
            break;
        case 1:
            answer = "FRI";
            break;
        case 2:
            answer = "SAT";
            break;
        case 3:
            answer = "SUN";
            break;
        case 4:
            answer = "MON";
            break;
        case 5:
            answer = "TUE";
            break;
        case 6:
            answer = "WED";
            break;
        case 7:
            answer = "THU";
            break;
    }
    return answer;
}
