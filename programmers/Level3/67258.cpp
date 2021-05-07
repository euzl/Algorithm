#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int a, b, length=100000;
    map<string, int> list;
    for (string g : gems) {
        list[g]++;
    }
    int total = list.size();
    list.clear();

    int cnt=0;
    int size = gems.size();
    int i=0, j=-1;
    while (1) {
        if (list[gems[i]] > 1) {
            list[gems[i]]--;
            ++i;
        } else {
            ++j;
            if (j >= size) break;
            list[gems[j]]++;
            if (list[gems[j]]==1) {
                ++cnt;
            }
        }
        
        if (cnt == total && (j-i) < length) {
            a=i+1, b=j+1, length=b-a;
        }
    }
    answer.push_back(a);
    answer.push_back(b);
    return answer;
}
