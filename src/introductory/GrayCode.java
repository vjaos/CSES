package introductory;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class GrayCode {
    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO(System.in, System.out);
        int n = io.nextInt();
        int bound = 1 << n;

        for (int i = 0; i < bound; i++) {
            int val = i ^ (i >> 1);
            String s = Integer.toBinaryString(val);
            io.println("0".repeat(n - s.length()) + s);
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
