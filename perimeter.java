import java.io.*;
import java.util.*;
public class perimeter {
    static boolean [][] checked;
    static int area;
    static int maxArea;
    static int perimeter;
    static int minPerimeter;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("perimeter.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("perimeter.out")));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        checked = new boolean[N][N];
        int [][] grid = new int[N][N];
        String temp;

        for (int i = 0; i < N; i ++) {
            st = new StringTokenizer(br.readLine());
            temp = st.nextToken();
            for (int j = 0; j < N; j ++) {
                if (temp.substring(j, j + 1).equals("#")) grid[i][j] = 1;
                if (temp.substring(j, j + 1).equals(".")) grid[i][j] = 0;
            }
        }
        maxArea = 0;
        minPerimeter = 10000;
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < N;  j ++) {
                if (grid[i][j] == 1 && !checked[i][j]) {
                    area = 0;
                    perimeter = 0;
                    floodFill(i, j, grid);
                    if (area > maxArea) {
                        maxArea = area;
                        minPerimeter = perimeter;
                    }
                    if (area == maxArea) {
                        if (perimeter < minPerimeter)  minPerimeter = perimeter;
                    }
                }
            }
        }

        out.println(maxArea + " " + minPerimeter);
        out.close();

    }

    private static void floodFill(int row, int col, int [][] grid) {
        int count = 0;
        int up = row - 1;
        int down = row + 1;
        int left = col - 1;
        int right = col + 1;
        area ++;
        checked[row][col] = true;

        if (up >= 0 && grid[up][col] == 1 && !checked[up][col]) floodFill(up, col, grid);
        if (up >= 0 && grid[up][col] == 1) count ++;

        if (left >= 0 && grid[row][left] == 1 && !checked[row][left]) floodFill(row, left, grid);
        if (left >= 0 && grid[row][left] == 1) count ++;

        if (down < grid.length && grid[down][col] == 1 && !checked[down][col]) floodFill(down, col, grid);
        if (down < grid.length && grid[down][col] == 1) count ++;

        if (right < grid.length && grid[row][right] == 1 && !checked[row][right]) floodFill(row, right, grid);
        if (right < grid.length && grid[row][right] == 1) count ++;

        perimeter += (4 - count);
    }

}
