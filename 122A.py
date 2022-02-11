n = int(input())
div = [i for i in range(n + 1) if all(j == '4' or j == '7' for j in str(i))]
print("YES" if any(n % i == 0 for i in div) else "NO")
