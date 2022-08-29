/* Online Java Compiler and Editor */
import java.util.Scanner;
import java.util.Arrays;
import java.util.List;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;


public class Main {

    public static int[] count_sort(int[] p, int[] c, int n) {
        int[] cnt = new int[n];
        for(int i = 0; i < n; i++) {
            cnt[c[i]]++;
        }
        int[] p_new = new int[n];
        int[] pos = new int[n];
        pos[0] = 0;
        for (int i = 1; i < n; i++) {
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for(int i = 0; i < n; i++) {

            p_new[pos[c[p[i]]]] = p[i];
            pos[c[p[i]]]++;
        }
        return p_new;
    }

    public static void main(String []args) throws Exception {
        Scanner scanner = new Scanner(new FileReader("hawara.in"));
        String  s = scanner.nextLine();
        s += "$";
        Integer n = s.length();
        int[] p = new int[n], c = new int[n];
        {
            IntPair[] a = new IntPair[n];
            for(int i = 0; i < n; i++) {
                a[i] = new IntPair(s.charAt(i), i);
            }
            Arrays.sort(a);
            for (int i = 0; i < n; i++) {
                p[i] = a[i].y;
            }
            c[p[0]] = 0;
            for (int i = 1; i < n; i++) {
                if (a[i].x == a[i - 1].x) {
                    c[p[i]] = c[p[i - 1]];
                } else {
                    c[p[i]] = c[p[i - 1]] + 1;
                }
            }
        }
        for (int k = 0; (1 << k) < n; k++) {

            for (int i = 0; i < n; i++) {
                p[i] = (p[i] - (1 << k) + n) % n;
            }
            p = count_sort(p, c, n);
            int[] c_new = new int[n];
            c_new[p[0]] = 0;

            for (int i = 1; i < n; i++) {
                IntPair now = new IntPair(c[p[i]], c[(p[i] + (1 << k)) % n]);
                IntPair prev = new IntPair(c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]);
                if (now.x == prev.x && now.y == prev.y) {
                    c_new[p[i]] = c_new[p[i - 1]];
                } else {
                    c_new[p[i]] = c_new[p[i - 1]] + 1;
                }
            }
            c = c_new;
            k++;
        }
        int[] arr = new int[n];
        for (int i = 1; i < n; i++) {
            arr[p[i]] = i;
        }
        SEG seg = new SEG();
        seg.build(0, 0, n - 2, arr);
        int q = scanner.nextInt();
        while (q-- != 0) {
            int l = scanner.nextInt(), r = scanner.nextInt(), k = scanner.nextInt();
            System.out.println(seg.get(l - 1, r - k, 0, 0, n - 2).y + 1);
        }
    }
}


class IntPair implements Comparable<IntPair> {
    int x;
    int y;
    IntPair(int x, int y) {
        this.x=x;
        this.y=y;
    }
    public int compareTo(IntPair other) {
        if(this.x == other.x) {
            return this.y - other.y;
        }
        return this.x - other.x;
    }
}

class SEG {
    IntPair[] tre;
    SEG() {
        tre = new IntPair[1 << 18];
    }
    public void build(int i, int s, int e, int[] vec) {
        if (s == e) {
            tre[i] = new IntPair(vec[s], s);
            return;
        }
        int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
        this.build(l, s, m, vec);
        this.build(r, m + 1, e, vec);
        if (tre[l].x < tre[r].x) {
            tre[i] = tre[l];
        } else {
            tre[i] = tre[r];
        }
    }

    public IntPair get(int qs, int qe, int i, int s, int e) {
        if (qs > e || qe < s) {
            return new IntPair(1 << 30, -1);
        }
        if (s >= qs && e <= qe) {
            return tre[i];
        }
        int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
        IntPair a = get(qs, qe, l, s, m), b = get(qs, qe, r, m + 1, e);
        if (a.x < b.x) {
            return a;
        }
        return b;
    }
}
