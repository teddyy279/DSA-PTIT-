if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        prev2 = a[0]
        prev1 = max(a[0], a[1])
        for i in range(2, n):
            current = max(prev2 + a[i], prev1)
            prev2, prev1 = prev1, current
        
        print(prev1)
