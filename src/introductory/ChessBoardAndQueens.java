package introductory;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class ChessBoardAndQueens {
    static int count = 0;
    static boolean[][] blocked;
    static boolean[] col;
    static boolean[] diag1;
    static boolean[] diag2;

    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO(System.in, System.out);

        int n = 8;

        blocked = new boolean[n][n];
        col = new boolean[n];
        diag1 = new boolean[2 * n];
        diag2 = new boolean[2 * n];

        for (int i = 0; i < n; i++) {
            String row = io.next();
            for (int j = 0; j < n; j++) {
                blocked[i][j] = row.charAt(j) == '*';
            }
        }

        search(0, n);

        io.println(count);
        io.close();
    }

    static void search(int y, int n) {
        if (y == n) {
            count++;
        } else {
            for (int x = 0; x < n; x++) {
                if (blocked[y][x] || col[x] || diag1[x + y] || diag2[x - y + n - 1]) continue;
                col[x] = diag1[x + y] = diag2[x - y + n - 1] = true;
                search(y + 1, n);
                col[x] = diag1[x + y] = diag2[x - y + n - 1] = false;
            }
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
