import java.io.*;
import java.util.*;

import static java.lang.System.in;
import static java.lang.System.out;

public class mooRoute {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n;
        n = Integer.parseInt(st.nextToken());

        int sum = 0, dir = 0, pos = 0;
        int[] nums = new int[n];
        //String rslt = "";
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i ++) {
            nums[i] = Integer.parseInt(st.nextToken());
            sum += nums[i];
        }


        for (int i = 0; i < sum; i ++) {
            if(dir == 0 && pos < n && nums[pos] > 0) {
                pw.print("R");
                nums[pos] --;
                pos ++;
            }
            else if(dir == 0) {
                dir = 1;
                pw.print("L");

                nums[pos - 1] --;
                pos --;
            }
            else if(nums[pos - 1] > 1 || nums[pos] == 0) {
                pw.print("L");

                nums[pos-1] --;
                pos --;

            }
            else {
                dir = 0;
                pw.print("R");
                nums[pos] --;
                pos ++;
            }
        }
        //pw.println(rslt);

        pw.close();
        br.close();

    }
}