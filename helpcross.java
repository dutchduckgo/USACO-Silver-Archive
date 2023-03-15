import java.io.*;
import java.util.*;

public class helpcross {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("helpcross.in"));
        PrintWriter out = new PrintWriter("helpcross.out");
        StringTokenizer st = new StringTokenizer(br.readLine());

        int C = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        PriorityQueue<Integer> chickens = new PriorityQueue<Integer>();
        int[][]cows = new int[N][2];

        for (int i = 0; i < C; i ++)
            chickens.add(Integer.parseInt(br.readLine()));

        for (int i = 0; i < N; i ++) {
            st = new StringTokenizer(br.readLine());
            cows[i][0] = Integer.parseInt(st.nextToken());
            cows[i][1] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(cows, (c1, c2) -> c1[1] -  c2[1]);
        int Ni = 0;
        int rslt = 0;
        while (!chickens.isEmpty() && Ni < N) {

            int chick = chickens.peek();

            if(chick >= cows[Ni][0] && chick <= cows[Ni][1]) {
                rslt ++;
                chickens.poll();
                Ni ++;
            }

            else if(chick < cows[Ni][0]) chickens.poll();

            else if(chick > cows[Ni][1]) Ni ++;

        }
        out.println(rslt);
        br.close();
        out.close();
    }
}