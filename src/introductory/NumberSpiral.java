package introductory;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class NumberSpiral {
    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO(System.in, System.out);

        int t = io.nextInt();

        while (t--> 0) {
            long x = io.nextLong();
            long y = io.nextLong();

            if (x < y) {
                if (y % 2 == 1) io.println(y * y - x + 1);
                else io.println((y - 1) * (y - 1) + x);
            } else {
                if (x % 2 == 0) io.println(x * x - y + 1);
                else io.println((x - 1) * (x - 1) + y);
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
