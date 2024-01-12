package introductory;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class BitStrings {
  static int modulo = 1_000_000_007;

  public static void main(String[] args) throws IOException {
    FastIO io = new FastIO(System.in, System.out);
    long n = io.nextInt();

    long res = 1;
    long a = 2;
    while (n > 0) {
      if ((n & 1) == 1) {
        res = res * a;
        res %= modulo;
      }

      a *= a;
      a %= modulo;
      n >>= 1;
    }

    io.println(res);
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
