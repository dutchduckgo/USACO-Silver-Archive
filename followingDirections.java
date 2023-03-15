import java.util.*;
import java.io.*;
class followingDirections {
    static int n;
    static int[] down;
    static int[] right1;
    static int[] swapA;
    static int[] swapB;
    static int[][] cows;
    static char[][] dir;
    public static void main (String[]args){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        down = new int[n];
        right1 = new int[n];
        cows = new int[n + 1][n + 1];
        dir = new char[n][n];

        for (int i = 0; i < n; i++) {
            dir[i] = sc.next().toCharArray();
            right1[i] = sc.nextInt();
        }

        for (int i = 0; i < n; i++)
            down[i] = sc.nextInt();

        int days = sc.nextInt();
        swapA = new int[days];
        swapB = new int[days];
        for (int i = 0; i < days; i++) {
            swapA[i] = sc.nextInt();
            swapB[i] = sc.nextInt();
        }

        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                cows[i][j] = 1;

        for (int i = 0; i <= n; i++) {
            cows[i][n] = 0;
            cows[n][i] = 0;
        }

        findR();

        int cost = 0;
        cost += findCost(cost);

        System.out.println(cost);
        char init;
        int rslt = 0;
        int first, last;

        int i = 0;
        while (i < days) {
            init = dir[swapA[i] - 1][swapB[i] - 1];
            first = swapA[i] - 1;
            last = swapB[i] - 1;

            rslt = cows[first][last];
            char tempChar;
            while (last < n && first < n) {
                tempChar = dir[first][last];
                if (tempChar == 'R') {
                    cows[first][last + 1] -= rslt;
                    last++;
                } else {
                    cows[first + 1][last] -= rslt;
                    first++;
                }
            }

            if (init == 'R')
                dir[swapA[i]-1][swapB[i]-1] = 'D';

            else
                dir[swapA[i]-1][swapB[i]-1] = 'R';

            first = swapA[i] - 1;
            last = swapB[i] - 1;
            while(first < n && last < n){
                tempChar = dir[first][last];
                if(tempChar == 'R'){
                    cows[first][last + 1] += rslt;
                    last ++;
                }
                else{
                    cows[first + 1][last] += rslt;
                    first ++;
                }

            }
            cost = 0;
            cost += findCost(0);
            System.out.println(cost);
            i ++;
        }
    }

    static void findR() {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (dir[i][j] == 'R')
                    cows[i][j + 1] += cows[i][j];
                else
                    cows[i + 1][j] += cows[i][j];
            }
    }

    static int findCost(int c) {
        for (int i = 0; i < n; i++) {
            c += cows[i][n] * right1[i];
            c += cows[n][i] * down[i];
        }
        return c;
    }

}
