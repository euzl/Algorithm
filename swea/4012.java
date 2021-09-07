
import java.util.ArrayList;
import java.util.Scanner;

import java.io.FileInputStream;


class Solution
{			
	static int N;
	static int [] type = new int[16]; // 1, -1
	static int [][] synergy = new int[16][16]; // 음식 간의 시너지 
	static int minV;
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		for(int test_case = 1; test_case <= T; test_case++)
		{
			minV = Integer.MAX_VALUE;
			N = sc.nextInt();
			for (int i=0; i<N; i++) {
				type[i] = -1;
				for (int j=0; j<N; j++) {
					synergy[i][j] = sc.nextInt();
				}
			}
			
			DFS(0, -1);
			
			System.out.printf("#%d %d\n", test_case, minV);
		}
	}
	
	public static void DFS(int cnt, int idx) {
		if (cnt == N/2) {
			cal();
			return;
		}

		for (int i=idx+1; i<N; i++) {
			type[i] = 1;
			DFS(cnt+1, i);
			type[i] = -1;
		}
	}
	
	public static void cal() {
		int value = 0;
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				if (i==j) continue;
				if (type[i] == type[j]) value += type[i]*synergy[i][j];
			}
		}
		
		value = Math.abs(value);
		
		if (value < minV) minV = value;
	}
}
