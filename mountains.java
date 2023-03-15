import java.io.*;
import java.util.*;
public class mountains {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("mountains.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("mountains.out")));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st;
        Integer[][] m = new Integer[n][2];
        int[][] mx = new int [n][2];

        for (int i = 0; i < n; i++) {

            st = new StringTokenizer(br.readLine());
            m[i][0] = Integer.parseInt(st.nextToken());
            m[i][1] = Integer.parseInt(st.nextToken());
            mx[i][0] = m[i][0] - m[i][1];
            mx[i][1] = m[i][0] + m[i][1];

        }
        Arrays.sort(mx, (m1, m2) -> m1[0] != m2[0] ? m1[0] - m2[0] : m2[1] - m1[1]);
        int rslt = 1;
        int prevX2 = mx[0][1];

        for (int i = 1; i < n; i++) {
            if (prevX2 < mx[i][1]) {
                rslt++;
                prevX2 = mx[i][1];

            }
        }
        out.println(rslt);
        out.close();
    }
}
