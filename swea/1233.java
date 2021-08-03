import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{	
	static boolean answer = true;
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T = 10;
		for(int test_case = 1; test_case <= T; test_case++)
		{
			answer = true;
			String n = sc.nextLine();
			int N = Integer.parseInt(n);
			
			input(N, sc);
			
			System.out.printf("#%d %d\n", test_case, answer==true?1:0);
		}
	}
	
	static void input(int N, Scanner sc) {
		int a;
		String b;
		int i;
		String str;
		
		for (i=1; i<=N; i++) {
			str = sc.nextLine(); // 한 줄씩 입력받기 
			String [] arr = str.split(" "); // 띄어쓰기로 구분
			
			if (arr.length == 2) {
				// 단말노드이므로 숫자여야만 함 
				if (!isDigit(arr[1].charAt(0))) answer = false;
			} else {
				// 자식이 있는 경우
				
				// 연산자 여야 함.. 
				if (isDigit(arr[1].charAt(0))) answer = false;
				
				// 숫자여야 함..
				if (!isDigit(arr[2].charAt(0))) answer = false;
				
				if (arr.length == 4 && !isDigit(arr[3].charAt(0))) answer = false;
			}
		}
	}
	
	static boolean isDigit(char t) {
		if (t=='/' || t=='+'||t=='-'||t=='*') return false;
		return true;
	}
}
