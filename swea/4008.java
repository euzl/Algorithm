
import java.util.ArrayList;
import java.util.Scanner;

import java.io.FileInputStream;


class Solution
{			
	static int N;
	static int [] num = new int[12];
	static int [] card = new int[4];
	static int maxV;
	static int minV;
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		for(int test_case = 1; test_case <= T; test_case++)
		{
			maxV = -100000000;
			minV = 100000000;
			
			N = sc.nextInt();
			for (int i=0; i<4; i++) card[i] = sc.nextInt();
			for (int i=0; i<N; i++) num[i]=sc.nextInt();
			DFS(1, num[0]);
			System.out.printf("#%d %d\n", test_case, (maxV-minV));
//			break;
		}
	}
	
	public static void DFS(int idx, int v) {
		if (idx == N) {
			if (v < minV) minV = v;
			if (v > maxV) maxV = v;
//			System.out.println(v);
			return;
		}
		
		for (int i=0; i<4; i++) {
			if (card[i] == 0) continue;
			if (num[idx] == 0 && i == 3) continue; // divide by zero
			card[i]--;
			DFS(idx+1, cal(v, i, idx));
			card[i]++;
		}
	}
	
	public static int cal(int v, int cIdx, int idx) {
		switch(cIdx) {
		case 0 :
			return v + num[idx];
		case 1:
			return v - num[idx];
		case 2:
			return v * num[idx];
		default:
			return v / num[idx];
		}
	}
}
