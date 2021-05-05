#include <cstdio>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<bool, string> > enter;
    map<string, string> id;
    map<string, string>::iterator it;
    char cmd[8], uid[11], name[11];
    for (string r : record) {
        sscanf(r.c_str(), "%s %s %s", cmd, uid, name);
        if (cmd[0] == 'C') {
            id[uid] = name;
        } else {
            if (cmd[0] == 'E') {
                id[uid] = name;
                enter.push_back({true, uid});
            } else {
                enter.push_back({false, uid});
            }
        }
    }
    
    for (auto e : enter) {
        if (e.first == true) {
            answer.push_back(id[e.second] + "님이 들어왔습니다.");
        } else {
            answer.push_back(id[e.second]+ "님이 나갔습니다.");
        }
    }
    
    return answer;
}
