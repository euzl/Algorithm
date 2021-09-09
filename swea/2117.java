
import java.util.*;
import java.io.*;


class Solution
{
	static int N, M, totalHome;
	static int [][] map = new int [20][20]; 
	static int [][] count = new int [20][20]; // (r,c)에서 출발했을 때 가구 수 
	
	static int [] dr = {1, 1, -1, -1};
	static int [] dc = {-1, 1, 1, -1};
	public static void main(String args[]) throws IOException
	{
//		System.setIn(new FileInputStream("res/sample_input (7).txt")); // 제출시 주석처리 
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		
		int result = 0;
		for (int tc=1; tc<=T; tc++) {
			String line = br.readLine();
			int split = line.indexOf(" ");
			N = Integer.parseInt(line.substring(0, split));
			M = Integer.parseInt(line.substring(split+1, line.length()));
			
			for (int i=0; i<N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j=0; j<N; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
					count[i][j] = map[i][j];
					if (map[i][j] == 1) totalHome++;
				}
			}
			
			bw.write("#"+tc+" "+findMax()+"\n");
		}
		bw.flush();
		br.close();
		bw.close();
	}
	
	public static int findMax() {
		int maxCount = 1;// 최대 가구 수 
		
		int cost, profit;
		for (int k=2; k<=N*2; k++) {
			cost = k*k + (k-1)*(k-1);
			for (int i=0; i<N; i++) {
				for (int j=0; j<N; j++) {
					around(i, j, k);
					profit = M*count[i][j] - cost;
					if (profit >= 0 && count[i][j]>maxCount) {
						maxCount = count[i][j];
						if (maxCount == totalHome) return maxCount;
					}
				}
			}
		}
		
		return maxCount;
	}
	
	/**
	 * k+1했을 때 갱신 
	 * @param r
	 * @param c
	 * @param k
	 */
	public static void around(int r, int c, int k) {
		int nr = r-k+1, nc = c;
		
		for (int d=0; d<4; d++) {
			for (int l=1; l<k; l++) {
				nr += dr[d]; nc += dc[d];
				if (nr<0||nr>=N||nc<0||nc>=N) continue;
				
				if (map[nr][nc] == 1) count[r][c]++;
			}
		}
	}
}
