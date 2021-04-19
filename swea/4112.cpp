#include<iostream>

using namespace std;
#define MAX_SIZE 10000
pair<int, int> input[2];

void setCoord(int a, int b) {
    int num = 0, idx = 0;
    for (int i=0; i<MAX_SIZE; i++) {
        for (int j=0; j<=i; j++) {
            ++num;
            if (num == a || num == b) {
                input[idx] = make_pair(i, j);
                ++idx;
                if (idx == 2) return;
            }
        }
    }
}

int getTime() {
    int x, y;
    x = input[1].first - input[0].first;
    if (input[1].second > input[0].second) {
        y = input[1].second - input[0].second;
        if (x >= y) y = 0;
        else y -= x;
    } else {
        y = input[0].second - input[1].second;
    }
    return x+y;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
 	int a,b;
    int time;
	for(test_case = 1; test_case <= T; ++test_case)
	{

        scanf("%d %d", &a, &b);
        if (a==b) {
            time = 0;
        } else {
            setCoord(a, b);
            time = getTime();
        }
        printf("#%d %d\n", test_case, time);

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
