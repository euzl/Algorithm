import java.util.Scanner;
import java.io.FileInputStream;

class Solution {
	public static void main(String args[]) throws Exception {
//System.setIn(new FileInputStream("res/input.txt"));

		/*
		 * 표준입력 System.in 으로부터 스캐너를 만들어 데이터를 읽어옵니다.
		 */
		Scanner sc = new Scanner(System.in);
		int T = 10;
//		T = sc.nextInt();

		for (int test_case = 1; test_case <= T; test_case++) {
			int n = sc.nextInt();
			int [] status = new int[n]; // current status 
			
			int result=0, input;
			for (int r=0; r<n; r++) {
				for (int c=0; c<n; c++) {
					input = sc.nextInt();
					
					if(input==2 && status[c]==1) { // deadlock
						result++;
						status[c]=0; // init
					} else if (input==1) {
						status[c]=1; // now N
					}
				}
			}
			System.out.printf("#%d %d\n", test_case, result);
		}
	}
}
