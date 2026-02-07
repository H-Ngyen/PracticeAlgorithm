def count_sequences_mod(N, K, M, P):
    if K == 0:
        return 1 % P
    if K == 1:
        return N % P

    limit = N - (K - 1)
    if limit <= 0:
        return 0

    Smax = (M - 1) * (K - 1)
    dp = [0] * (Smax + 1)
    dp[0] = 1

    for _ in range(K - 1):
        new_dp = [0] * (Smax + 1)
        prefix = 0
        for s in range(0, Smax + 1):
            prefix += dp[s]
            if s - M >= 0:
                prefix -= dp[s - M]
            new_dp[s] = prefix % P

        dp = new_dp

    res = 0
    for s in range(0, min(Smax, limit - 1) + 1):
        res = (res + (limit - s) * dp[s]) % P

    return res


N, K, M, P = map(int, input().split())
print(count_sequences_mod(N, K, M, P))