/* 문제풀이하면서 필요한 기초개념들 기록 - C++ */

@최댓값/최솟값
#include <algorithm>
max(int num1, int num2, ...); //인자 중 최대값 반환. 변수 못넣음. 
min(int num1, int num2, ...); // 최소값

@절댓값
#include <cstdlib> // int 형인 경우
#include <cmath.h> // double, float
abs(int num); // 절대값 반환 (absolute value)

@\ : 역슬래쉬 사용
/*
\t  : tab 효과
\n  : enter 효과(endl) *endl 보다 빠르다.
\', \"  : 따옴표(', ") 표시
\\  : \ 출력 (하나만 하면 출력X)
*/

@문자열 입력
#include <iostream>
char str_input[10];
char k;
cin >> str_input; // 공백, 줄바꿈 기준으로 입력받음
cin.get(k); // 문자 입력받음

cin.getline(str_input, 10); 
// 줄바꿈 기준으로 입력받음 ==> *공백도 문자로 간주!
// 파라미터:(문자열을 저장할 배열이름, 입력받을 최대 문자 개수 + 1) < C언어 문자열의 마지막엔 '\0'이 들어가기 때문!

// string은 이렇게!
#include <string>
string str_input;
getline(cin, str_input); // 두번째 파라미터에 입력받은 스트링을 저장할 이름 
