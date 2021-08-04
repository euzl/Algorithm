package problemsolving;

import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{	
	static int r=0;
	static int c=0;
	static int [] passwords = new int[8];
	static int [] number = new int[10];
	public static void main(String args[]) throws Exception
	{
		initNumber();
		
		System.setIn(new FileInputStream("res/sinput.txt"));
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		sc.nextLine();
		
		for(int test_case = 1; test_case <= T; test_case++)
		{
			r = sc.nextInt();
			c = sc.nextInt();
			sc.nextLine();
			
			char [][] arr = new char[r][c];
			inputData(sc, arr);
			
			int answer = findCode(arr);
			System.out.printf("#%d %d\n", test_case, answer);
		}
	}
	
	/**
	 * 암호코드를 구성하는 숫자 설정 
	 */
	static void initNumber() {
		number[0] = Integer.parseInt("0001101", 2);
		number[1] = Integer.parseInt("0011001", 2);
		number[2] = Integer.parseInt("0010011", 2);
		number[3] = Integer.parseInt("0111101", 2);
		number[4] = Integer.parseInt("0100011", 2);
		number[5] = Integer.parseInt("0110001", 2);
		number[6] = Integer.parseInt("0101111", 2);
		number[7] = Integer.parseInt("0111011", 2);
		number[8] = Integer.parseInt("0110111", 2);
		number[9] = Integer.parseInt("0001011", 2);
	}
	
	/**
	 * 배열에 저장 
	 */
	static void inputData(Scanner sc, char [][] arr) {
		for (int i=0; i<r; i++) {
			String str = sc.nextLine();
			for (int j=0; j<c; j++) {
				arr[i][j] = str.charAt(j);
			}
		}
	}
	
	/**
	 * 입력받은 배열에서 암호코드를 찾아내서 유효 여부를 파악하고, 결과의 합을 반환함  
	 * @param arr 입력받은 배열 
	 * @return 각 암호코드의 결과 합 
	 */
	static int findCode(char [][] arr) {
		int answer = 0;
		int height;
		int width;
		int zeroCnt;
		String code;
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++) {
				if (arr[i][j] == '0') continue;
				
				for (height = 5; height < (r-i); height++) { // 최소 높이가 5
					if(arr[i+height][j] == '0') {
						height--;
						break;
					}
				}
				code = "";
				zeroCnt = 0;
				for (width=0; true; width++) {
					if ((j+width)>=c) break; // out of range
					if (arr[i][j+width] != arr[i+height][j+width]) break; // 한 암호가 아님!! 
					
					// 000이면 암호코드가 끝났다고 봄
					if (arr[i][j+width] == '0') {
						zeroCnt++;
						if (zeroCnt>3) break;
					} else {
						zeroCnt = 0;
					}
					
					code += arr[i][j+width];
				}

				masking(i, j, width, arr);
				answer += scanning(code);
			}
		}
		
		return answer;
	}
	
	/**
	 * 이미 확인이 끝난 암호코드는 '0'으로 마스킹한다. (다음 탐색을 이어나가기 위함)
	 * @param si 암호코드 시작 i
	 * @param ji 암호코드 시작 j
	 * @param width 암호코드 가로길이 
	 * @param arr 데이터가 저장된 배열 
	 */
	static void masking(int si, int ji, int width, char [][] arr) {
		while(true) { // 맨 끝의 '0'제외 
			if (arr[si][ji+width-1] == '0') --width;
			else break;
		}
		
		for (int i=0; i<r; i++) {
			if (arr[si+i][ji] == '0') return;
			for (int j=0; j<width; j++) {
				arr[si+i][ji+j] = '0'; // 초기화!
			}
		}
	}
	
	/**
	 * 스캐너 기능 
	 * @param code 암호코드 
	 * @return 유효하면 각 숫자 8개의 합 
	 */
	static int scanning(String code) {
		int size = code.length();
		
		size = code.length();
		while(true) { // 맨 끝의 '0'제외 
			if (code.charAt(size-1) == '0') --size;
			else break;
		}
		code = code.substring(0, size);
		
		// 2진수로 변환 
		String binCode = ""; 
		String temp;
		for (int i=0; i<size; i+=1) {
			if (i+1>=size) temp = Integer.toBinaryString(Integer.parseInt(code.substring(i, size), 16));
			else temp = Integer.toBinaryString(Integer.parseInt(code.substring(i, i+1), 16));
			
			// 16진수->2진수 : 4자리!! 자리를 맞춰주어야 한다.
			for (int j=0; j<4-temp.length(); j++) {
				binCode += "0";
			}
			binCode += temp;
		}

		
		// binCode의 끝에 '0' 제거 (문제를 보면 모든 수가 1로 끝난다.)
		size = binCode.length();
		while(true) { // 맨 끝의 '0'제외 
			if (binCode.charAt(size-1) == '0') --size;
			else break;
		}
		binCode = binCode.substring(0, size);
		
		// 두꺼운거 압축
		int cnt;
		cnt = size/56;
		if (size%56 > 2) cnt++;
		
		String zipCode = "";
		for (int i=size-1; i>=0; i-=cnt) {
			zipCode = binCode.charAt(i) + zipCode;
		}

		// 비밀번호 획득 
		setPassword(zipCode, 0);
		int answer = getCode();
		return answer;
	}
	
	/**
	 * number[]과 비교하여 문제에서 주어진 숫자로 변환한다.
	 * @param password 코드의 8개의 숫자 중 현재 확인할 숫
	 * @return 변환된 숫자 (0~9)
	 */
	static int getRealNum(int password) {
		for (int i=0; i<10; i++) {
			if (password == number[i]) return i;
		}
		return -1;
	}
	
	/**
	 * 가능한 암호를 passwords 배열에 갱신해준다.
	 * @param turn 몇 번째인지를 받아서 shift 효과를 냄 
	 */
	static void setPassword(String code, int turn) {
		String str;
		int size = code.length();
		for (int i=1; i<8; i++) {
			str = code.substring(size-7, size);
			passwords[i] = getRealNum(Integer.parseInt(str, 2));
			size -= 7;
			if (size-7<0) break;
		}
		str = code.substring(0, size);
		passwords[0] = getRealNum(Integer.parseInt(str, 2));
	}
	
	/**
	 * 검증코드가 유효한지 확인함.
	 * @return 유효하면 각 자리의 수를 합한 결과 / 유효하지 않으면 0
	 */
	static int getCode() {
		int answer = 0;
		answer = (passwords[0]+passwords[2]+passwords[4]+passwords[6])*3 + (passwords[1]+passwords[3]+passwords[5]) + passwords[7];
		if (answer%10 != 0) return 0; // 유효하지 않음 
		
		answer = 0;
		for (int i=0; i<8; i++) answer += passwords[i];
		return answer; // 합한 결과 
	}
}
