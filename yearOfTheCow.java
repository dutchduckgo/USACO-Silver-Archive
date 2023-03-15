import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class yearOfTheCow {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        HashSet<Integer> hsCycle = new HashSet<>();

        for (int i = 0; i < N; i ++) {
            int temp = Integer.parseInt(br.readLine());
            hsCycle.add((temp + 11) / 12);
        }

        ArrayList<Integer> alCycle= new ArrayList<>(hsCycle);

        Collections.sort(alCycle);
        int rslt = alCycle.get((alCycle.size() - 1) * 12);
        int last = 0;

        ArrayList<Integer> gaps = new ArrayList<>();
        for (int t : alCycle) {
            int g = (t - 1) * 12 - last;
            gaps.add(g);
            last = t * 12;
        }
        Collections.sort(gaps, (g1, g2) -> g2 - g1);
        for (int i = 0; i < K - 1; i ++) {
            rslt -= gaps.get(i);
        }

        System.out.println(rslt);
    }
}