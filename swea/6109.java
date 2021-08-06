package problemsolving;

import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{	
	public static void main(String args[]) throws Exception
	{
		System.setIn(new FileInputStream("res/s_input.txt"));
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int n;
		int cnt;
		String dInput;
		for(int test_case = 1; test_case <= T; test_case++)
		{	
			n = sc.nextInt();
			dInput = sc.next();
			
			// 방향에 맞춰서 회전할횟수 지정 
			if (dInput.equals("up")) cnt = 2;
			else if (dInput.equals("right")) cnt = 1;
			else if (dInput.equals("left")) cnt = 3;
			else cnt = 0;
			
			int [][] map = new int[n][n];
			for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
					map[i][j] = sc.nextInt();
				}
			}
			
			// rotate CNT times
			int [][] nArr = rotate(n, map, cnt);
			
			// gravity down
			int [][] gArr = gravity(n, nArr);
			
			// 원래 방향으로 되돌리기
			int [][] oArr = rotate(n, gArr, 4-cnt);

			System.out.printf("#%d\n", test_case);
			printArray(n, oArr);
		}
	}
	
	/**
	 * 시계방향으로 회전 (재귀)
	 * @param n 배열 길이 
	 * @param map 주어진 배열 
	 * @param cnt 회전 횟수 
	 * @return 회전한 배열 
	 */
	static int[][] rotate(int n, int [][] map, int cnt) {
		if (cnt == 0) return map;
		int [][] nArr = new int[n][n];
		int o;
		
		for (int j=n-1; j>=0; j--) {
			o = (-1)*(j-n+1);
			for (int i=0; i<n; i++) {
				nArr[i][j] = map[o][i];
			}
		}

		return rotate(n, nArr, cnt-1);
	}
	
	/**
	 * 아래로 중력!
	 * @param n  배열 길이 
	 * @param map 주어진 배열 
	 * @return 2048 적용 결과 (아래로 중력)
	 */
	static int[][] gravity(int n, int [][] map) {
		int [][] gArr = new int[n][n];
		
		int iPointer; // 값이 들어갈 곳을 가리킴 
		for (int j=0; j<n; j++) {
			iPointer = n-1; // 가장 아래에!
			for (int i=n-1; i>=0; i--) {
				if (map[i][j] != 0) {
					int ni = i-1;
					if (ni < 0) gArr[iPointer][j] = map[i][j];
					while(ni>=0) {
						if (map[i][j] != map[ni][j]) {
							if (map[ni][j] == 0 && ni!=0) {
								--ni;
								continue;
							}
							gArr[iPointer][j] = map[i][j];
							break;
						} else {
							// 합쳐진다.
							gArr[iPointer][j] = 2*map[i][j];
							i = ni;
							break;
						}
					}
					iPointer--; // 한칸 위로 이동
				}
			}
		}
		return gArr;
	}
	
	static void printArray(int n, int [][] map) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				System.out.printf("%d ", map[i][j]);
			}
			System.out.println();
		}
	}
}

