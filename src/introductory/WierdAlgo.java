package introductory;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class WierdAlgo {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        long n = Integer.parseInt(br.readLine());

        while (n != 1) {
            pw.printf("%d ", n);
            if (n % 2 == 0) n = n / 2;
            else n = 3 * n + 1;
        }

        pw.println(1);
        pw.close();
        br.close();
    }

}