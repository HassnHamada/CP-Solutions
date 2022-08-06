/* Online Java Compiler and Editor */
import java.util.*;
import java.io.*;


public class Main {

    public static IntPair solve(int s)
    {

        Trei tri = new Trei();
        IntPair ret = new IntPair(0, 1 << 30);
        for (int i = 1; i < s; i++)
        {
            tri.insert(tem[i - 1]);
            ret.x = Math.max(ret.x, tri.getMx(tem[i]));
            ret.y = Math.min(ret.y, tri.getMn(tem[i]));
        }
        return ret;
    }
    private static int[] tem;
    public static void main(String []args) throws Exception {
        Scanner scanner = new Scanner(new FileReader("input.in"));
        // Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = scanner.nextInt();
        }
        tem = new int[n];
        for (int i = 0; i < n / 2; i++)
        {
            tem[i + 1] = arr[2 * i] ^ arr[2 * i + 1];
            tem[i + 1] ^= tem[i];
        }
        IntPair a = solve(n / 2 + 1);
        for (int i = 0; i < n / 2 - 1 + (n & 1); i++)
        {
            tem[i + 1] = arr[2 * i + 1] ^ arr[2 * i + 2];
            tem[i + 1] ^= tem[i];
        }
        IntPair b = solve(n / 2 + (n & 1));
        System.out.print(Math.max(a.x, b.x));
        System.out.print(" ");
        System.out.println(Math.min(a.y, b.y));
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

class Trei{
    int[][] tri;
    int sz;
    Trei(){
        sz = 1;
        tri = new int[2 << 20][2];
        for(int i = 0; i < (2 << 20); i++){
            tri[i][0] = -1;
            tri[i][1] = -1;
        }
    }
    public void insert(int n)
    {
        int v = 0;
        for (int i = 19; i >= 0; i--)
        {
            int c = (n >> i) & 1;
            if (tri[v][c] == -1)
            {
                tri[v][c] = sz++;
            }
            v = tri[v][c];
        }
    }


    public int getMx(int n)
    {
        int v = 0, ret = 0;
        for (int i = 19; i >= 0; i--)
        {
            int c = (((n >> i) & 1) == 1 ? 0 : 1);
            if (tri[v][c] == -1)
            {
                c ^= 1;
            }
            ret |= ((((n >> i) & 1) ^ c) << i);
            v = tri[v][c];
        }
        return ret;
    }


    public int getMn(int n)
    {
        int v = 0, ret = 0;
        for (int i = 19; i >= 0; i--)
        {
            int c = ((n >> i) & 1);
            if (tri[v][c] == -1)
            {
                c ^= 1;
            }
            ret |= ((((n >> i) & 1) ^ c) << i);
            v = tri[v][c];
        }
        return ret;
    }

}
