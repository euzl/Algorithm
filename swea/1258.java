//package problemsolving; // 제출시 주석 

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;

import java.io.FileInputStream;


class Solution
{
	static int size;
	public static void main(String args[]) throws Exception
	{
//		System.setIn(new FileInputStream("res/input (4).txt")); // 제출시 주석처리 


		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		int N;
		int [][] map = new int[100][100];
		int [] r = new int [100];
		int [] c = new int [100];
		int cnt;
		for(int test_case = 1; test_case <= T; test_case++)
		{
			N = sc.nextInt();
			
			for (int i=0; i<N; i++) {
				for (int j=0; j<N; j++) {
					map[i][j] = sc.nextInt();
				}
			}
			
			cnt = -1;
			
			// 화학물질이 담긴 용기 찾기~
			PriorityQueue<Bomb> pq = new PriorityQueue<>();
			for (int i=0; i<N; i++) {
				for (int j=0; j<N; j++) {
					if (map[i][j] != 0) {
						cnt++;
						r[cnt] = 1;
						c[cnt] = 1;
						
						int k;
						// row
						for (k=i+1; k<N; k++) {
							if (map[k][j] == 0) break;
							r[cnt]++;
						}
						
						int l;
						// column
						for (l=j+1; l<N; l++) {
							if (map[i][l] == 0) break;
							c[cnt]++;
						}
						
						pq.offer(new Bomb(cnt, r[cnt]*c[cnt], r[cnt]));
						
						// masking
						for (int ii=i; ii<k; ii++) {
							for (int jj=j; jj<l; jj++) {
								map[ii][jj] = 0;
							}
						}
					}
				}
			}
			
			System.out.print("#"+test_case + " " + (cnt+1));
			int idx;
			while(!pq.isEmpty()) {
				idx = pq.poll().idx;
				System.out.printf(" %d %d", r[idx], c[idx]);
			}
			System.out.println();
		}
	}
	
	static class Bomb implements Comparable<Bomb>{
		int idx;
		int size;
		int r;
		Bomb(int idx, int size, int r) {
			this.idx = idx;
			this.size = size;
			this.r = r;
		}
		@Override
		public int compareTo(Bomb o) {
			if (this.size<o.size) return -1;
			else if (this.size > o.size) return 1;
			else {
				if (this.r < o.r) return -1;
				else return 1;
			}
		}
	}


}
