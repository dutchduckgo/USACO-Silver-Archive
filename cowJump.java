import java.io.*;
import java.util.*;

public class cowJump {
    static int [][] lines;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader (new FileReader("cowjump.in"));
        PrintWriter out = new PrintWriter ("cowjump.out");
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(br.readLine());
        lines = new int[N][2];





    }


    public class Point {
        public int x, y;
        public Point(int x, int y){
            this.x = x; this.y = y;
        }
    }
    public static int sign(Point A, Point B, Point C) {
        int area = (B.x-A.x) * (C.y-A.y) - (C.x-A.x) * (B.y-A.y);
        if (area > 0) return 1;
        if (area < 0) return -1;
        return 0;
    }
    public static boolean between(Point P, Point X, Point Y) {
        return ((X.x <= P.x && P.x <= Y.x) || (Y.x <= P.x && P.x <= X.x))
                && ((X.y <= P.y && P.y <= Y.y) || (Y.y <= P.y && P.y <= X.y));
    }
    public static boolean intersectQ(Point P, Point Q, Point X, Point Y) {
        int[] signs = {sign(P, X, Y), sign(Q, X, Y), sign(X, P, Q), sign(Y, P, Q)};
        if (signs[0] == 0 && signs[1] == 0 && signs[2] == 0 && signs[3] == 0)
            return between(P, X, Y) || between(Q, X, Y) || between(X, P, Q);
        return signs[0] != signs[1] && signs[2] != signs[3];
    }
}