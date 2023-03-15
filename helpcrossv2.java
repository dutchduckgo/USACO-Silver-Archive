import java.io.*;
import java.util.*;

public class helpcrossv2 {
    public static class Cow{
        int start, end;
        public Cow(int s, int e){
            start = s;
            end = e;
        }
    }

    static TreeMap<Integer, Integer> chickens = new TreeMap<>();
    public static void add(int x){
        if(chickens.containsKey(x)){
            chickens.put(x, chickens.get(x)+1);
        }
        else{
            chickens.put(x,1);
        }
    }
    public static void remove(int x){
        chickens.put(x, chickens.get(x)-1);

        if(chickens.get(x) == 0){
            chickens.remove(x);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new FileReader("helpcross.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("helpcross.out")));

        StringTokenizer st = new StringTokenizer(f.readLine());

        int c = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());

        Cow[] cows = new Cow[n];

        for(int i = 0; i < c; i++){
            add(Integer.parseInt(f.readLine()));
        }

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(f.readLine());

            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            Cow cow = new Cow(start,end);

            cows[i] = cow;
        }

        Arrays.sort(cows, (a, b) -> a.end != b.end ? a.end - b.end : a.start - b.start);

        int counter = 0;

        for(int i = 0; i < n; i++){
            Cow cow = cows[i];
            Integer chicken = chickens.ceilingKey(cow.start);

            if(chicken != null && chicken <= cow.end){
                counter++;

                remove(chicken);
            }
        }

        out.println(counter);
        out.close();
    }
}
