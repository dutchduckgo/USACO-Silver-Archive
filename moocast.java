import java.io.*;
import java.util.*;
public class moocast {
    static int rslt = 0;
    public static void dfs(int current, boolean[] visited, boolean[][] transmit) {
        if(visited[current])
            return;

        visited[current] = true;
        rslt ++;
        for(int i = 0; i < transmit[current].length; i++) {
            if(transmit[current][i])
                dfs(i, visited, transmit);
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("moocast.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("moocast.out")));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        double[] x = new double[n];
        double[] y = new double[n];
        double[] range = new double[n];
        for(int i = 0; i < n; i ++) {
            st = new StringTokenizer(br.readLine());
            x[i] = Double.parseDouble(st.nextToken());
            y[i] = Double.parseDouble(st.nextToken());
            range[i] = Double.parseDouble(st.nextToken());
        }

        boolean[][] transmit = new boolean[n][n];

        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                double squareDist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                if(squareDist <= range[i] * range[i]) transmit[i][j] = true;
            }
        }
        int best  = 1;
        for(int i = 0; i < n; i++) {
            boolean[] visited = new boolean[n];
            rslt = 0;
            dfs(i, visited, transmit);
            best = Math.max(rslt, best);
        }

        out.println(best);
        out.close();
    }
}