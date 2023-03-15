import java.io.*;
        import java.util.*;

public class lemonade {
    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader (new FileReader("lemonade.in"));
        PrintWriter out = new PrintWriter ("lemonade.out");
        int n = Integer.parseInt(br.readLine());
        Integer[] cows = new Integer[n];
        int rslt = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i ++)
            cows[i] = Integer.parseInt(st.nextToken());

        Arrays.sort(cows, (a1, a2) -> a2 - a1);

        for (int i = 0; i < n; i ++) {
            if (cows[i] >= rslt) rslt ++;
            else break;
        }

        out.println(rslt);
        out.close();
        br.close();
    }
}
