import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
	static final int SIZE = 8;
	static char [][] arr = new char[SIZE][SIZE];
	static int target;
	
	public static void main(String args[]) throws Exception
	{
		System.setIn(new FileInputStream("res/input (6).txt"));
		Scanner sc = new Scanner(System.in);
		int T = 10;
		for(int test_case = 1; test_case <= T; test_case++)
		{
			// input
			target = sc.nextInt();
			String s = "";
			
			for (int i=0; i<SIZE; i++) {
				s = sc.next();
				for (int j=0; j<SIZE; j++) {
					arr[i][j] = s.charAt(j);
				}
			}

			int count = 0;
			for (int i=0; i<SIZE; i++) {
				for (int j=0; j<SIZE; j++) {
					if (getMaxLengthHorizontal(i, j, j)) count++;
					if (getMaxLengthHorizontal(i, j, j+1)) count++;
					if (getMaxLengthVertical(i, i, j)) count++;
					if (getMaxLengthVertical(i, i+1, j)) count++;
				}
			}
			
			System.out.printf("#%d %d\n", test_case, count);
		}
	}
	public static boolean getMaxLengthHorizontal(int r, int c1, int c2) {
		// c1==c2 ? 홀수 : 짝수개
		while(c2<SIZE && c1>=0) {
			if (arr[r][c1] != arr[r][c2]) break;
			if (c2-c1+1 == target) return true;
			c2 += 1; c1 -= 1; 
		}
		
		return false;
	}
	
	public static boolean getMaxLengthVertical(int r1, int r2, int c) {
		while(r2<SIZE && r1>=0) {
			if (arr[r1][c] != arr[r2][c]) break;
			if (r2-r1+1 == target) return true;
			r2 += 1; r1 -= 1; 
		}
		
		return false;
	}
}
