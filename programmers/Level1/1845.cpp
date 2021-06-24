#include <vector>
using namespace std; 

int var[200001];

int solution(vector<int> nums)
{
    int answer = 0;
    int N = nums.size();
    for (int i=0; i<N; i++) {
        if (!var[nums[i]]) {
            var[nums[i]] = 1;
            ++answer;
            
            if (answer >= N/2) break;
        }
    }
    
    return answer;
}
