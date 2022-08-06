/* Online Java Compiler and Editor */
import java.util.*;
import java.io.*;


public class Main {
    public static void main(String []args) throws Exception {
        Scanner scanner = new Scanner(new FileReader("magic.in"));
        // Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(), m = scanner.nextInt(), x = scanner.nextInt(), y = scanner.nextInt();
        if (n == 1 && m == 1) {
            System.out.println(1);
            return;
        }
        if (n == 1 || m == 1 || (n == 2 && m == 2)) {
            System.out.println(-1);
            return;
        }
        TreeSet<Integer> nums = new TreeSet<Integer>();
        boolean ok = true;
        int v = Math.min(n, m), w = Math.max(n, m);
        LinkedList<Integer> aaa = new LinkedList<Integer>(), bbb = new LinkedList<Integer>();
        if (w > v) {
            int t = 0;
            for (int j = 0; j < v; j++) {
                aaa.add(n*m - j);
                t += n*m - j;
                for (int i = bbb.size(); i < w - v + j; i++) {
                    bbb.add(i + 1);
                    t -= i + 1;
                }
                if (t > bbb.size() && t < n*m - j) {
                    bbb.add(t);
                    for(int i = bbb.size(); i < n * m - j; i++){
                        nums.add(i);
                    }
                    nums.remove(t);
                    break;
                }
                if (j + 1 == v) {
                    ok = false;
                }
            }
            if (ok) {
                
                v -= aaa.size();
                w -= bbb.size();
            }
        } else {
            bbb.add(1);
            nums.remove(1);
            aaa.add(2);
            nums.remove(2);
            aaa.add(3);
            nums.remove(3);
            bbb.add(4);
            nums.remove(4);
            for(int i = 5; i <= n * m; i++){
                nums.add(i);
            }
            v -= 2;
            w -= 2;
        }
        if (ok && v != 0) {
            int c = -1;
            if (v % 2 == 1) {
                int vv = nums.first();
                aaa.add(vv);
                bbb.add(vv);
                nums.remove(vv);
                c = vv;
                v -= 1;
            } else {
                Stack<Integer> tem = new Stack<Integer>();
                while(bbb.size() > 0) {
                    int j = bbb.pop();
                    c = j;
                    tem.push(j);
                    if (nums.contains(j + 1) && nums.contains(j + 2) && nums.contains(j + 3)) {
                        aaa.add(j);
                        bbb.add(j + 1);
                        nums.remove(j + 1);
                        bbb.add(j + 2);
                        nums.remove(j + 2);
                        aaa.add(j + 3);
                        nums.remove(j + 3);
                        break;
                    }
                }
                v -= 2;
                while(tem.size() > 0){
                    bbb.add(tem.pop());
                }
            }
            Stack<Integer> stk = new Stack<Integer>();
            for (; v > 0; v -= 2) {
                while (true) {
                    do {
                        int vv = nums.first();
                        stk.add(vv);
                        nums.remove(vv);
                    } while (stk.size() < 4);
                    if (stk.get(stk.size() - 4) + 3 == stk.get(stk.size() - 1)) {
                        aaa.add(stk.pop());
                        bbb.add(stk.pop());
                        bbb.add(stk.pop());
                        aaa.add(stk.pop());
                        break;
                    }
                }
            }
            for (int i = 0; i < stk.size(); i++) {
                nums.add(stk.pop());
            }
            if (n < m) {
                LinkedList<Integer> tem = aaa;
                aaa = bbb;
                bbb = tem;
            }
            int[][] ans = new int[n+1][m+1];
            for (int i = 1; i <= m; i++) {
                if (i == y) {
                    continue;
                }
                int vv = aaa.removeLast();
                if (vv == c) {
                    vv = aaa.removeLast();
                }
                ans[x][i] = vv;
            }
            for (int i = 1; i <= n; i++) {
                if (i == x) {
                    continue;
                }
                int vv = bbb.removeLast();
                if (vv == c) {
                    vv = bbb.removeLast();
                }
                ans[i][y] = vv;
            }
            ans[x][y] = c;
            for (int i = 1; i <= n; i++) {
                if (i == x) {
                    continue;
                }
                for (int j = 1; j <= m; j++) {
                    if (j == y) {
                        continue;
                    }
                    ans[i][j] = nums.first();
                    nums.remove(ans[i][j]);
                }
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    System.out.print(ans[i][j]);
                    if(j < m) {
                        System.out.print(" ");
                    }
                }
                System.out.println();
            }
        } else {
            System.out.println(-1);
        }
    }
}