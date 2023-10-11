package introductory;

import java.io.BufferedReader;
import java.io.Closeable;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class CoinPiles {
    /*
        Пусть x - кол-во операций первого типа (удалить из правого 2 из левого 1),  y - второго
        Тогда
            a = 2x + y
            b = x + 2y

            x = (2a - b) / 3  x,y > 0
            y = (2b - a) / 3

            (a + b) = 3 (x + y)
        Имеем
            a + b делится на 3
                и max(a, b) <= 2min(a, b)
     */
    public static void main(String[] args) throws IOException {
        try(FastIO io = new FastIO(System.in, System.out)) {
            int t = io.nextInt();
            while (t-- > 0) {
                int a = io.nextInt();
                int b = io.nextInt();

                if ((a + b) % 3 == 0 && Math.max(a, b) <= 2 * Math.min(a, b)) {
                    io.println("YES");
                } else {
                    io.println("NO");
                }
            }
        }
    }

    static class FastIO extends PrintWriter implements Closeable {
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

        @Override
        public void close() {
            super.close();
        }
    }
}
