#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int num_p = 0;
    int num_y = 0;
    for (char c : s) {
        c == 'p' || c == 'P' ? ++num_p : c == 'y' || c == 'Y' ? ++num_y : 0;
    }

    if (num_p - num_y) answer = false;
    return answer;
}
