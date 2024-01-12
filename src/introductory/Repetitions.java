package introductory;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Repetitions {

    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO(System.in, System.out);
        String dna = io.next();

        int max = 0;
        for (int i = 0; i < dna.length(); i++) {
            int count = 1;

            while (i + 1 < dna.length() && dna.charAt(i) == dna.charAt(i + 1)){
                count++;
                i++;
            }

            max = Math.max(count, max);
        }

        io.println(max);
        io.close();
    }

    static class FastIO extends PrintWriter {
        final BufferedReader br;
        private StringTokenizer tokenizer;

        public FastIO(InputStream in, OutputStream out) {
            super(out);
            br = new BufferedReader(new InputStreamReader(in));
        }

        public String next() throws IOException {
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
