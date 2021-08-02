import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
	static final int SIZE = 101; // 정점 숫자의 최대가 100이므로 간단한 저장을 위함 ~
	static int [][] graph = new int [SIZE][SIZE]; // 비상연락망 
	static int [] tele = new int [SIZE]; // 연락받는 순서 
	
	public static void main(String args[]) throws Exception
	{
		System.setIn(new FileInputStream("res/input (18).txt"));
		Scanner sc = new Scanner(System.in);
		int T = 10;
		for(int test_case = 1; test_case <= T; test_case++)
		{
			init();
			
			int size = sc.nextInt(); // size
			int start = sc.nextInt(); // start
			
			int a, b;
			for (int i=0; i<size; i+=2) {
					a = sc.nextInt(); b = sc.nextInt();
					graph[a][b] = 1; // a->b
			}
			
			BFS(start, graph, tele);
			
			System.out.printf("#%d %d\n", test_case, getLastMax(tele));
		}
	}
	
	/**
	 * 배열 초기화 
	 */
	public static void init() {
		for (int i=0; i<SIZE; i++) {
			tele[i] = 0;
			for (int j=0; j<SIZE; j++) {
				graph[i][j] = 0;
			}
		}
	}
	
	/**
	 * @param tele 연락받는 순서 
	 * @return 가장 늦게 연락받는 번호 중 가장 큰 번호
	 */
	public static int getLastMax(int [] tele) {
		int max = -1, maxIdx = 0;
		for (int i=1; i<SIZE; i++) {
			if (tele[i] >= max) {
				max = tele[i];
				maxIdx = i; // 갈수록 i가 커지니까 바로 대입 가능 
			}
		}
		return maxIdx;
	}
	
	/**
	 * @param start 당번(시작점) 
	 * @param graph 비상연락망 
	 * @param tele 연락받는 순서 저장 
	 */
	public static void BFS(int start, int [][] graph, int [] tele) {
		Queue<Integer> q = new LinkedList<>();
		q.add(start);
		
		tele[start] = 1;
		
		int cur;
		while(!q.isEmpty()) {
			cur = q.poll();
			
			for (int i=1; i<SIZE; i++) {
				if (graph[cur][i] == 1 && tele[i] == 0) {
					tele[i] = tele[cur]+1; // visit and counting
					q.add(i); 
				}
			}
		}
	}
}
