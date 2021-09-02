
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;

import java.io.FileInputStream;


class Solution
{
	static int N;
	static double E;
	
	static int [] x;
	static int [] y;
	
	static Island [] il;
	static final double INF = Double.MAX_VALUE;
	static final int NS = -1; // not start
	static final int END = -2; // finish

	public static void main(String args[]) throws Exception
	{

		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		for(int test_case = 1; test_case <= T; test_case++)
		{
			N = sc.nextInt();
			il = new Island[N];
			x = new int[N];
			y = new int[N];
			
			for (int i=0; i<N; i++) {
				x[i] = sc.nextInt();
			}
			for (int i=0; i<N; i++) {
				y[i] = sc.nextInt();
			}
			E = sc.nextDouble();
			
			for (int i=0; i<N; i++) {
				il[i] = new Island(i);
				il[i].key = INF;
			}
			
			prim();
			
			double answer = 0;
			for (int i=0; i<N; i++) {
				answer += il[i].key;
			}
			

			System.out.printf("#%d %d\n", test_case, Math.round(answer));
//			if (test_case == 4) break;
		}
	}
	
	public static void prim() {
		ArrayList<Island> list = new ArrayList<>();
		
		for (int i=0; i<N; i++) {
			list.add(il[i]);
		}
		// 시작
		il[0].key = 0.0;
		il[0].p = 0;
		
		Island cur;
		
		while(true) {
			cur = getMin(list);
			if (cur == null) break;
			cur.p = END; // 확인한다 표시 
//			System.out.println(cur.num + ") " + cur.key);
			for (int i=0; i<N; i++) {
				if (il[i].p == END) continue;
//				System.out.println(i);
				double length = (Math.pow(x[cur.num]-x[il[i].num], 2)+Math.pow(y[cur.num]-y[il[i].num], 2))*E;
				if (il[i].key > length) {
					il[i].key = length;
					il[i].p = cur.num;
//					System.out.println(i+")"+il[i].key);
				}
			}
		}
	}

	static class Island {
		int num;
		int p;
		double key;
		Island() {}
		Island(int num) {
			this.num = num;
			this.p = NS;
			this.key = INF;
		}
	}
	
	static Island getMin(ArrayList<Island> list) {
		Island min = null;
		for (int i=0; i<N; i++) {
			if (list.get(i).p == END) continue; // 이미 끝난거 
			if (min == null) { // 최초설정 
				min = list.get(i);
				continue;
			}
			if (list.get(i).key < min.key) { // 작은 값을 가진 섬으로 갱신 
				min = list.get(i);
			}
		}
		return min;
	}
}
