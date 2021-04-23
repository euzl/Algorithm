#include <string>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> lines) {
    if (lines.size() == 1) return 1;
    vector<pair<int, int> > times;

    int answer = 0;
    char buf[25];
    int hh, mm, ss, sss;
    double dur;
    
    int beginTime, endTime; //ms
    
    for (string line : lines) {
        sscanf(line.c_str(), "%s %d:%d:%d.%d %lfs", buf, &hh, &mm, &ss, &sss, &dur);
        endTime = ((hh*60+mm)*60+ss)*1000+sss;
        beginTime = endTime - dur*1000 + 1;
        times.push_back({beginTime, endTime});
    }
    
    int bound = times.size()-1, logStart, cnt;
    int start = bound;
    
    while(1) {
        if (bound == 0) break;
        // count
        cnt = 0;
        for (int i = start; i>=0; i--) {
            if (times[bound].second - times[i].second < 1000) ++cnt;
            else break;
        }
        answer = answer < cnt ? cnt : answer;
        
        // Init bound
        if (times[bound].first >= times[bound-1].second) {
            cnt = 0, logStart = times[bound].first-999;
            for (int i = start; i>=0; i--) {            
                if (times[bound].second - times[i].second < 1000) ++cnt;
                else break;
            }
            start = bound-1;
        }
        answer = answer < cnt ? cnt : answer;
        
        --bound;
        
        // Init last log (for count)
        if (times[bound].second < times[start].first) {
            start = bound;
        }
    }
    
    return answer;
}
