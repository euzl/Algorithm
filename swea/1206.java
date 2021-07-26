import java.util.Scanner;
import java.io.FileInputStream;

class Solution {
	public static void main(String args[]) throws Exception {
		
		final int NOT_POSSIBLE = 300;

		Scanner sc = new Scanner(System.in);
		int T;
//		T = sc.nextInt();
		T = 10;

		int [] near = {-2, -1, 1, 2};
		for (int test_case = 1; test_case <= T; test_case++) {
			int result = 0;
			
			int len = sc.nextInt();
			int [] arr = new int[len];
			for (int i=0; i<len; i++) {
				arr[i] = sc.nextInt();
			}
			
			int subMin;
			int possi;
			for (int i=2; i<len-2; i++) {
				subMin = NOT_POSSIBLE;
				for (int n=0; n<4; n++) {
					possi = arr[i] - arr[i+near[n]];
					if (possi <= 0) break; //조망권 없다 ~
					
					if (subMin > possi) subMin = possi;
					
					if (n==3) {
						result += subMin;
					}
				}
			}
			System.out.printf("#%d %d\n", test_case, result);
		}
	}
}
