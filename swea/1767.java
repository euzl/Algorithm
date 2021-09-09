
import java.util.*;
import java.io.*;


class Solution
{
	static int N, M, totalHome;
	static int [][] map = new int [12][12]; 
	static ArrayList<Pair> core = new ArrayList<>(); 
	static int maxCoreCnt;
	static int minLineSum;
	
	static int [] dr = {1, 0, -1, 0};
	static int [] dc = {0, 1, 0, -1};
	public static void main(String args[]) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		
		for (int tc=1; tc<=T; tc++) {
			core.clear();
			maxCoreCnt = 0;
			minLineSum = Integer.MAX_VALUE;
			
			N = Integer.parseInt(br.readLine());
			
			for (int i=0; i<N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j=0; j<N; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
					if (map[i][j] == 1) core.add(new Pair(i, j));
				}
			}
			
			DFS(0, 0, 0);
			bw.write("#"+tc+" "+minLineSum+"\n");
		}
		bw.flush();
		br.close();
		bw.close();
	}
	
	public static void DFS(int cIdx, int coreCnt, int lineSum) {
		if (cIdx >= core.size()) {
			// 모든 코어 확인완료
			if (coreCnt > maxCoreCnt || (coreCnt == maxCoreCnt && lineSum < minLineSum)) {
				maxCoreCnt= coreCnt;
				minLineSum = lineSum;
			}
			return;
		}

		// 이 코어 제외 
		DFS(cIdx+1, coreCnt, lineSum);
		
		// 4방향
		int nr=core.get(cIdx).r;
		int nc=core.get(cIdx).c;
		int backD;
		for (int d=0; d<4; d++) {
			if (!isPromisingDir(cIdx, d)) continue;
			
			while(true) {
				nr += dr[d]; nc += dc[d];
				if (nr<0||nr>=N||nc<0||nc>=N) break;
				map[nr][nc] = 2; // 전선표시 
				lineSum++; // 전선 길이 늘리기 
			}
			
			DFS(cIdx+1, coreCnt+1, lineSum);
			
			while(true) {
				nr -= dr[d]; nc -= dc[d];
				if (map[nr][nc] == 1) break;
				map[nr][nc] = 0; // 전선표시제거  
				lineSum--; // 전선 길이 되돌리기  
			}
		}
		
	}
	
	public static boolean isPromisingDir(int cIdx, int d) {
		int nr=core.get(cIdx).r;
		int nc=core.get(cIdx).c;
		
		while(true) {
			nr += dr[d]; nc += dc[d];
			if (nr<0||nr>=N||nc<0||nc>=N) return true;
			if (map[nr][nc] > 0) return false; // 다른 코어나 전선이 있음.
		}
	}
	
	static class Pair {
		int r; int c;
		Pair(int r, int c) {this.r=r; this.c=c;}
	}
}
