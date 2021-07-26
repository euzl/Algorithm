import java.util.Scanner;

class Solution {
	public static void main(String args[]) throws Exception {
		
//		System.setIn(new FileInputStream("res/input2.txt"));

		Scanner sc = new Scanner(System.in);
		int T;
		T = sc.nextInt();
		
		int tnum;
		
		for (int test_case = 1; test_case <= T; test_case++) {
			tnum = sc.nextInt();
			int [] score = new int[101];
			
			int input;
			for (int i=0; i<1000; i++) {
				input = sc.nextInt();
				score[input]++;
			}
			
			int maxIdx = -1;
			int maxCount = -1;
			for (int i=100; i>=0; i--) {
				if (score[i] > maxCount) {
					maxCount = score[i];
					maxIdx = i;
				}
			}
			
			System.out.printf("#%d %d\n", tnum, maxIdx);
		}
	}
}
