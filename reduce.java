import java.io.*;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;

public class reduce {

    static int rslt = Integer.MAX_VALUE;
    static Integer[][] borderCows;
    static int[][] cows;
    static HashSet<Integer> removedCow = new HashSet<>();
    static boolean[] isRemoved;
    public static void main(String[] args) throws IOException{

        BufferedReader bf = new BufferedReader(new FileReader("reduce.in"));
        int N = Integer.parseInt(bf.readLine());

        cows = new int[N][2];
        Integer[] cowLabel = new Integer[N];
        isRemoved =new boolean[N];
        for(int i = 0; i < N; i ++){
            StringTokenizer st = new StringTokenizer(bf.readLine());
            cows[i][0] = Integer.parseInt(st.nextToken());
            cows[i][1] = Integer.parseInt(st.nextToken());
            cowLabel[i] = i;
        }

        borderCows = new Integer[N][4];

        Arrays.sort(cowLabel, (c1, c2) -> cows[c1][0] != cows[c2][0] ? cows[c1][0]-cows[c2][0] : cows[c1][1] - cows[c2][1] );
        for(int i = 0; i < 4; i ++){
            borderCows[0][i] = cowLabel[i];
            borderCows[2][i] = cowLabel[N-1-i];
        }

        Arrays.sort(cowLabel, (c1, c2) -> cows[c1][1] != cows[c2][1] ? cows[c1][1]-cows[c2][1]: cows[c1][0]-cows[c2][0]);
        for(int i = 0; i < 4; i ++){
            borderCows[1][i] = cowLabel[i];
            borderCows[3][i] = cowLabel[N - 1 - i];
        }

        search(3);
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("reduce.out")));
        pw.println(rslt);
        pw.close();

    }

    private static void search(int r) {
        if(r<=0){
            rslt = Math.min(rslt, ( cows[getBorderCow(2)][0] - cows[getBorderCow(0)][0])*(cows[getBorderCow(3)][1]- cows[getBorderCow(1)][1]));
            return;
        }

        for(int i = 0; i < 4; i ++){
            int temp = getBorderCow(i);
            removedCow.add(temp);
            //isRemoved[temp] = true;
            search(r-1);
            //isRemoved[temp] = false;
            removedCow.remove(temp);
        }
    }

    private static int getBorderCow(int c){
        for(int i = 0; i < 4; i ++){
            int temp = borderCows[c][i];
            if(!removedCow.contains(temp))
                return temp;
        }

        return -1;
    }


}
