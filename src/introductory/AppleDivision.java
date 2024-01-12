package introductory;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class AppleDivision {
    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO(System.in, System.out);

        int n = io.nextInt();
        int all = 1 << n;

        long[] p = new long[n];
        for (int i = 0; i < n; i++) p[i] = io.nextLong();

        long min = Long.MAX_VALUE;
        for (int i = 0; i < all; i++) {
            long f = 0, s = 0;

            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) > 0) f += p[j];
                else s += p[j];
            }

            min = Math.min(Math.abs(f - s), min);
        }

        io.println(min);
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
