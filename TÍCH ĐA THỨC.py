def solve(P, Q):
    M = len(P)
    N = len(Q)
    res = [0] * (M + N - 1)
    for i in range(M):
        for j in range(N):
            res[i + j] += P[i] * Q[j]
    
    for i in range(M + N - 1):
        print(res[i], end = ' ')

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        m, n = map(int, input().split())
        P = list(map(int, input().split()))
        Q = list(map(int, input().split()))
        solve(P, Q)
        print()
