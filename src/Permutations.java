import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Permutations {
    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO(System.in, System.out);
        int n = io.nextInt();

        if (2 == n || 3 == n) io.println("NO SOLUTION");
        else {
            for (int i = 2; i <= n; i += 2) {
                io.print(i);
                io.print(" ");
            }

            for (int i = 1; i <= n; i += 2) {
                io.print(i);
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
