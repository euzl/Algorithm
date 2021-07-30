package problemsolving;

import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
	public static void main(String args[]) throws Exception
	{
//		System.setIn(new FileInputStream("res/input (14).txt"));
		Scanner sc = new Scanner(System.in);
		int T = 10;
		for(int test_case = 1; test_case <= T; test_case++)
		{
			int V = sc.nextInt();
			int E = sc.nextInt();
			
			int [] prevCnt = new int[V+1]; // 이전 정점의 개수 
			int [] nextCnt = new int[V+1]; // 이후 정점의 개수 
			int [][] next = new int[V+1][E]; // 간선 쌍 저장 (비효율적인 2차원 배열..)
			
			int a, b;
			for (int i=0; i<E; i++) {
				a = sc.nextInt(); b = sc.nextInt();
				next[a][nextCnt[a]] = b; // 간선 쌍 저장 
				nextCnt[a]++;
				prevCnt[b]++;
			}
		
			System.out.printf("#%d", test_case);
			
			for (int i=0; i<V; i++) {
				for (int j=1; j<=V; j++) {
					if (prevCnt[j] == 0) { // 이전 정점이 없다면 출력 
						System.out.printf(" %d", j);
						prevCnt[j] = -1; // 방문 표시 
						for (int k=0; k<nextCnt[j]; k++) {
							prevCnt[next[j][k]]--; // 연결돼있는 정점들의 이전 정점 개수를 하나 줄여줌 
						}
					}
				}
			}
			
			System.out.println();
		}
	}
}
