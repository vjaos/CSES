package introductory;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class TrailingZeros {
    /*
        Количество нулей на конце n! = сколько раз мы можем поделить n! на 10

        Рассмотрим разложение числа n! и 10 на простые множители
        n! = 1 * 2 * 3 * 4[2 * 2] * 5 ....
        10 = 2 * 5

        Сколько раз можем поделить = кол-во пар (2,5) в числе n!
        Делитель 2 встречается чаще чем 5, поэтому будет искать кол-во чисел которые делит степерь 5ки

        Разложение на простые множители
        5! =  5
        10! = 1 * 2 * 5
        11! = 2^8 * 3^4 * 5^2 * 7
     */
    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO(System.in, System.out);
        long n = io.nextLong();
        long ans = 0;
        long curr = 5;

        while (curr <= n) {
            ans += n / curr;
            curr *= 5;
        }

        io.println(ans);
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
