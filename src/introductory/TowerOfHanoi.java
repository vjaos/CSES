package introductory;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class TowerOfHanoi {
    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO(System.in, System.out);

        int n = io.nextInt();
        io.println((1 << n) - 1);
        solve(n, 1, 3, 2, io);
        io.close();
    }

    static void solve(int n, int from, int to, int buff, FastIO io) {
        if (n > 0) {
            solve(n - 1, from, buff, to, io);
            io.print(from);
            io.print(" ");
            io.println(to);
            solve(n - 1, buff, to, from, io);
        }
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
