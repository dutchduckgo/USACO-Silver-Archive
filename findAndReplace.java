import java.lang.*;
import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class findAndReplace {
    static BufferedReader r = new BufferedReader(new InputStreamReader(in));
    static StringTokenizer st;
    static PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(out)));
    static Map<Character, Character> map = new HashMap<>();
    static int T;
    public static void main(String[] args) throws Exception {
// r = new BufferedReader(new FileReader(".in"));
// pw = new PrintWriter(new BufferedWriter(new FileWriter(".out")));
        T = Integer.parseInt(r.readLine());
        for (int t = 0; t < T; t++) {
            map.clear();
            boolean stop = false;
            char[] init = r.readLine().toCharArray();
            char[] end = r.readLine().toCharArray();
            for (int k = 0; k < init.length; k++) {
                if (!map.containsKey(init[k])) map.put(init[k], end[k]);
                else if (map.get(init[k]) != end[k]) {
                    stop = true;
//pw.println(init[k] + " " + end[k]);
                    break;
                }
            }
            int changed = map.entrySet().stream().mapToInt(e -> !e.getKey().equals(e.getValue()) ?
                    1 : 0).sum();
//pw.println("changed " + changed);
            for (var e : map.entrySet()) {
                if (e.getKey().equals(e.getValue())) continue;
                if (e.getValue() == '!') continue;
                boolean cycle = cycle(e.getKey());
                if (cycle) {
                    changed++;
                }
                for (var e2 : map.entrySet()) if (e2.getValue().equals('.')) map.put(e2.getKey(), '!');
            }
            if (stop) pw.println(-1);
            else pw.println(changed);
        }
        r.close();
        pw.close();
    }
    static boolean cycle(char node) {
        if (map.containsKey(node)) {
            if (map.get(node).equals(node) || map.get(node).equals('!')) return false;
            char temp = map.get(node);
            if (map.get(node).equals('.')) return true;
            int count = map.entrySet().stream().mapToInt(e -> e.getValue().equals(temp) &&
                    !e.getKey().equals(temp) ? 1 : 0).sum();
            if (count > 1) return false;
            map.put(node, '.');
            return cycle(temp);
        }
        return false;
    }
}