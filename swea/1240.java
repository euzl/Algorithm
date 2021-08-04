package problemsolving;

import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{	
	static String input ="";
	static int [] passwords = new int[8];
	static int [] number = new int[10];
	public static void main(String args[]) throws Exception
	{
		initNumber();
		
		System.setIn(new FileInputStream("res/input (23).txt"));
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		sc.nextLine();
		
		for(int test_case = 1; test_case <= T; test_case++)
		{
			input(sc);
			
			int answer = 0;
			for (int i=0; i<7; i++) {
				setPassword(i);
				answer = getCode();
				if (answer > 0) break;
				if (input.charAt(55-i) == '1') break; // 끝까지 다 밀었다.
			}
			
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
	
	static void input(Scanner sc) {
		input = "";
		boolean isDone = false; // 암호코드 찾았는지 여부 

		int r = sc.nextInt();
		int c = sc.nextInt();
		sc.nextLine();
		
		for (int i=0; i<r; i++) {
			String str = sc.nextLine();
			
			if (isDone) continue; // 이미 암호코드를 저장했음.
			
			// 암호코드를 찾으러 가는 여정 
			for (int j=0; j<c; j++) {
				if (str.charAt(j) == '0') continue;

				// 첫 1 등장 == 암호코드 등장 
				for (int size = 0; size<56; size++) {
					if ((j+size)>=c) break; // out of range
					input += str.charAt(j+size);
				}
				isDone = true;
				break;
			}
		}
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
	static void setPassword(int turn) {
		String str;
		int start = 7-turn;
		str = input.substring(0, start);
		passwords[0] = getRealNum(Integer.parseInt(str, 2));
		for (int i=0; i<7; i++) {
			str = input.substring(start, start+7);
			passwords[i+1] = getRealNum(Integer.parseInt(str, 2));
			start += 7;
		}
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
	
//	/**
//	 * 2진수로 이루어진 문자열을 10진수 수로 반환하는 함수 (== Integer.parseInt(str, 2))
//	 * @param bs 2진수 문자
//	 * @return 10진수 변환 결과  
//	 */
//	static int binstring2dec(String bs) {
//		int ssize = bs.length();
//		int result = 0;
//		for (int i = ssize-1; i>=0; i--) {
//			if(bs.charAt(i) == '1') {
//				result += Math.pow(2, ssize-i-1);
//			}
//		}
//		return result;
//	}
}
