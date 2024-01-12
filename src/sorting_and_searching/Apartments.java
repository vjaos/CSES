import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Apartments {
    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO(System.in, System.out);

        int n = io.nextInt(), m = io.nextInt(), k = io.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = io.nextInt();

        int[] b = new int[m];
        for (int i = 0; i < m; i++) b[i] = io.nextInt();

        Arrays.sort(a);
        Arrays.sort(b);

        int i = 0, j = 0, cnt = 0;
        while (i < n && j < m) {
            if (a[i] - k <= b[j] && b[j] <= a[i] + k) {
                i++;
                j++;
                cnt++;
            } else {
                if (a[i] - k > b[j]) j++;
                else i++;
            }
        }

        io.println(cnt);
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
