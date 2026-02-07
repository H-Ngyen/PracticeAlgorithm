import sys
import math
from collections import defaultdict, Counter, deque
from bisect import bisect_left, bisect_right
import heapq

input = sys.stdin.readline


def solve():
    n = int(input())
    arr = list(map(int, input().split()))
    print(sum(arr))


if __name__ == "__main__":
    for _ in range(int(input())):
        solve()
