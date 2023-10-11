import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class PalindromeReorder {
    public static void main(String[] args) throws IOException {
        try(FastIO io = new FastIO(System.in, System.out)) {
            String s = io.next();
            int n = s.length();

            if (n == 1) {
                io.println(s);
            } else {
                int[] count = new int[26];
                for (char c : s.toCharArray()) count[c - 'A']++;
                char[] res = new char[n];

                int l = 0;
                int r = n - 1;
                int oddIdx = -1;

                for (int i = 0; i < 26; i++) {
                    if (count[i] % 2 == 0) {
                        while (count[i] > 0 && l < r) {
                            res[l] = (char) ('A' + i);
                            res[r] = (char) ('A' + i);
                            l++;
                            r--;
                            count[i] -= 2;
                        }
                    } else {
                        if (oddIdx != -1) {
                            io.println("NO SOLUTION");
                            return;
                        } else {
                            oddIdx = i;
                        }
                    }
                }

                while (oddIdx != -1 && count[oddIdx] > 0 && l <= r) {
                    res[l] = (char) ('A' + oddIdx);
                    res[r] = (char) ('A' + oddIdx);
                    l++;
                    r--;
                    count[oddIdx] -= 2;
                }

                for (char c : res) io.print(c);
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
