#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> lines) {
    // if (lines.size() == 1) return 1;
    vector<pair<int, int> > times;

    int answer = 0;
    char buf[25];
    int hh, mm, ss, sss;
    double dur;
    
    int beginTime, endTime; //ms
    
    for (string line : lines) {
        sscanf(line.c_str(), "%s %d:%d:%d.%d %lfs", buf, &hh, &mm, &ss, &sss, &dur);
        endTime = ((hh*60+mm)*60+ss)*1000+sss;
        beginTime = endTime - dur*1000.0+0.5 + 1;
        times.push_back({beginTime, -1});
        times.push_back({endTime+999, +1}); // 1초를 붙인다.
    }
    
    sort(times.begin(), times.end());
    
    int cnt=0;
    int t_size = times.size();
    for (auto t : times) {
        cnt -= t.second;
        answer = answer<cnt?cnt:answer;
    }
    
    return answer;
}
