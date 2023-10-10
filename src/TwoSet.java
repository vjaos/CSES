import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class TwoSet {
    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO(System.in, System.out);

        long n = io.nextLong();
        long total = n * (n + 1) / 2;

        if (total % 2 != 0) io.println("NO");
        else {
            io.println("YES");
            List<Long> first = new ArrayList<>();
            List<Long> second = new ArrayList<>();

            long l = 1;
            long r = n % 2 == 0 ? n : n - 1;

            while (l < r) {
                if (first.size() < second.size()) {
                    first.add(l);
                    first.add(r);
                } else {
                    second.add(l);
                    second.add(r);
                }
                l++;
                r--;
            }

            if (n % 2 != 0) {
                if (first.size() < second.size()) first.add(n);
                else second.add(n);
            }

            io.println(first.size());
            for (long val : first) {
                io.print(val);
                io.print(" ");
            }
            io.println();

            io.println(second.size());
            for (long val : second) {
                io.print(val);
                io.print(" ");
            }
        }


        io.close();
    }

    static class FastIO extends PrintWriter {
        final BufferedReader br;
        private StringTokenizer tokenizer;

        public FastIO(InputStream in, OutputStream out) {
            super(out);
            br = new BufferedReader(new InputStreamReader(in));
        }

        private String next() throws IOException {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(br.readLine());
            }
            return tokenizer.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }
    }
}
