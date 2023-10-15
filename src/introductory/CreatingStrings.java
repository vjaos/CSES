package introductory;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class CreatingStrings {
    static StringBuilder sb = new StringBuilder();
    static List<String> ans = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO(System.in, System.out);
        String chars = io.next();

        int[] count = new int[26];
        for (char c : chars.toCharArray()) count[c - 'a']++;

        generate(0, chars.length(), count);

        io.println(ans.size());
        for (String val : ans) io.println(val);

        io.close();
    }

    static void generate(int k, int n, int[] count) {
        if (k == n) {
            ans.add(sb.toString());
        } else {
            for (int i = 0; i < 26; i++) {
                if (count[i] > 0) {
                    count[i]--;
                    sb.append((char) (i + 'a'));

                    generate(k + 1, n, count);

                    sb.deleteCharAt(sb.length() - 1);
                    count[i]++;
                }
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
