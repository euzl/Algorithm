import java.util.Scanner;
import java.io.FileInputStream;

class Solution {
	public static void main(String args[]) throws Exception {
//System.setIn(new FileInputStream("res/input (4).txt"));

		Scanner sc = new Scanner(System.in);
		int T = 10;
//		T = sc.nextInt();
		
		int [][] map = new int[101][101];

		for (int test_case = 1; test_case <= T; test_case++) {
			int t = sc.nextInt();
			
			int sSum=0, dSum=0;
			for (int i=0; i<100; i++) {
				for (int j=0; j<100; j++) {
					map[i][j] = sc.nextInt();
					map[i][100] += map[i][j];
					map[100][j] += map[i][j];
					if (i==j) sSum += map[i][j];
					if (i+j==99) dSum += map[i][j];
				}
			}
			
			int max = Math.max(sSum, dSum);
			for (int k=0; k<100; k++) {
				if (map[k][100] > max) max = map[k][100];
				if (map[100][k] > max) max = map[100][k];
				
				// init for next case
				map[k][100] = 0;
				map[100][k] = 0; 
			}
			
			System.out.printf("#%d %d\n", test_case, max);
		}
	}
}
