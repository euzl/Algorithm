import java.util.Scanner;
import java.io.FileInputStream;

class Solution {
	public static void main(String args[]) throws Exception {
//System.setIn(new FileInputStream("res/input (3).txt"));

		Scanner sc = new Scanner(System.in);
		int T = 10;
//		T = sc.nextInt();
		
		int [][] map = new int[100][100];

		for (int test_case = 1; test_case <= T; test_case++) {
			int t = sc.nextInt();
			
			// init setting
			int r=0, c=0;
			for (int i=0; i<100; i++) {
				for (int j=0; j<100; j++) {
					map[i][j] = sc.nextInt();
					if (map[i][j] == 2) {
						r = i; c = j;
					}
				}
			}
			
			// move
			// 1. 위로쭉쭉
			// 2. 좌,우에 뭐가 있으면 그 방향으로 쭉쭉 (-> 1 반복)
			// 3. 최종 c 가 출발점의 x좌표
			int [] dc = {-1, 1};
			while(r>0) {
				// 2
				for (int d=0; d<2; d++) {
					if (c+dc[d]>=0 && c+dc[d]<100 && map[r][c+dc[d]] == 1) {
						c += dc[d];
						while(c+dc[d]>=0 && c+dc[d]<100 && map[r][c+dc[d]] == 1) c+=dc[d]; // move horizontal
						break; // 좌로갔다가 우로 다시가면 안 되니
					}
				}
				// 1
				r--;
			}
			System.out.printf("#%d %d\n", test_case, c);
		}
	}
}
