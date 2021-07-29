import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
	public static void main(String args[]) throws Exception
	{
//		System.setIn(new FileInputStream("res/input (7).txt"));
		Scanner sc = new Scanner(System.in);
		int T = 10;
		for(int test_case = 1; test_case <= T; test_case++)
		{
			int t = sc.nextInt();
			int a = sc.nextInt();
			int b = sc.nextInt();
			
			
			System.out.printf("#%d %d\n", test_case, abs(a,b,0));
		}
	}
	
	public static int abs(int a, int b, int cnt) {
		if (cnt >= b) return 1;
		else return a*abs(a,b,cnt+1);
	}
}
