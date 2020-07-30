#include <string>
#include <vector>
using namespace std;
int size; // 계속 반복 사용

int indexSkill(string skill, char find) {
    for (int i=0; i<size; i++) {
        if (skill[i] == find) {
            return i; // 찾은 스킬의 인덱스 반환
        }
    }
    return -1; // 없음
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    size = skill.length();
    int bf = -1;
    int idx;
    for (string sk : skill_trees) {
        bf = -1;
        for (char find : sk) {
            idx = indexSkill(skill, find);
            if (idx == -1) continue;
            else if (idx - bf == 1) {
                bf = idx;
                continue;
            }
            else {
                bf = -2; // 불가능한
                break;
            }
        }
        if (bf != -2) answer++;
    }
    return answer;
}
