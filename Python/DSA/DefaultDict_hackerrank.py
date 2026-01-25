from collections import defaultdict
d = defaultdict(list)

n, m = list(map(int, input().split()))

for _ in range(n):
    d['a'].append(input())

for _ in range(m):
    value = input().strip()
    index = []

    for i in range(n):
        if value == d['a'][i]:
            idx = i + 1
            index.append(idx)
    
    if index:
        print(' '.join(map(str, index)))
    else:
        print("-1")