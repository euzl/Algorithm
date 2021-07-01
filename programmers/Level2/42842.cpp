#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int width=1, height;
    brown -= 4;
    while(1) {
        if (yellow%width==0) {
            height = yellow/width;
            if (width+height == brown/2) break;
        }
        ++width;
    }
    answer.push_back(height+2);
    answer.push_back(width+2);
    return answer;
}
