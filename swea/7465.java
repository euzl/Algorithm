import java.util.*;
import java.io.*;
 
class Solution
{
    static int N, M;
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        int T;
        T=Integer.parseInt(br.readLine());
 
        for(int test_case = 1; test_case <= T; test_case++)
        {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
             
            // 부모노드 저장 (p[x]==i 이면 각 트리의 root!)
            int [] p = new int[N+1]; 
            for (int i=0; i<=N; i++) p[i] = i;
             
            // 트리 만들기.
            int a, b;
            for (int i=0; i<M; i++) {
                st = new StringTokenizer(br.readLine());
                a = Integer.parseInt(st.nextToken());
                b = Integer.parseInt(st.nextToken());
 
                p[getRoot(p,b)] = getRoot(p,a);
            }
             
            // 루트 개수 
            int count=0;
            for (int i=1; i<=N; i++) {
                if (p[i] == i) count++;
            }
             
            bw.write("#"+test_case+" "+count + "\n");
            bw.flush();
        }
        bw.close();
    }
     
    public static int getRoot(int [] p, int idx) {
        while(true) {
            if (p[idx] == idx) return idx;
            idx = p[idx];
        }
    }
}
