import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
	static char [][] arr = new char[100][100];
	
	public static void main(String args[]) throws Exception
	{
		System.setIn(new FileInputStream("res/input (5).txt"));
		Scanner sc = new Scanner(System.in);
		int T = 10;
		for(int test_case = 1; test_case <= T; test_case++)
		{
			// input
			int t=sc.nextInt();
			String s = "";
			
			for (int i=0; i<100; i++) {
				s = sc.next();
				for (int j=0; j<100; j++) {
					arr[i][j] = s.charAt(j);
				}
			}
			
			int maxLength = -1;
			int m;
			for (int i=0; i<100; i++) {
				for (int j=0; j<100; j++) {
					m = getMaxLengthHorizontal(i, j, j);
					if (m > maxLength) maxLength = m;
					m = getMaxLengthHorizontal(i, j, j+1);
					if (m > maxLength) maxLength = m;
					m = getMaxLengthVertical(i, i, j);
					if (m > maxLength) maxLength = m;
					m = getMaxLengthVertical(i, i+1, j);
					if (m > maxLength) maxLength = m;
				}
			}
			
			
			System.out.printf("#%d %d\n", test_case, maxLength);
		}
	}
	public static int getMaxLengthHorizontal(int r, int c1, int c2) {
		// c1==c2 ? 홀수 : 짝수개
		if (c2<100 && arr[r][c1] != arr[r][c2]) return 0;
		
		while(c2<99 && c1>0) {
			c2 += 1; c1 -= 1; 
			if (arr[r][c1] != arr[r][c2]) return c2-c1-1;
		}
		
		return c2-c1+1;
	}
	
	public static int getMaxLengthVertical(int r1, int r2, int c) {
		// c1==c2 ? 홀수 : 짝수개
		if (r2<100 && arr[r1][c] != arr[r2][c]) return 0;
		
		while(r2<99 && r1>0) {
			r2 += 1; r1 -= 1; 
			if (arr[r1][c] != arr[r2][c]) return r2-r1-1;
		}
		
		return r2-r1+1;
	}
}
