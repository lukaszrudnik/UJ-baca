# Lukasz Rudnik

INF = 1 << 60

def process_agent(n, k, m, edges):
    current = [INF] * n
    current[0] = 0  # start

    for i in range(k+1):  # maksymalnie k+1 krawedzi
        next = current[:]  # kopia
        for j in range(m):
            u, v, cost = edges[j]
            if current[u] + cost < next[v]:
                next[v] = current[u] + cost
        current = next

    if current[n-1] == INF:
        return -1
    else:
        return current[n-1]

# Glowna funkcja
L = int(raw_input())
for _ in range(L):
    while True:
        line = raw_input()
        if line.strip() != "":
            break
    parts = map(int, line.strip().split())
    n = parts[0]
    k = parts[1]
    m = parts[2]
    edges = []
    for i in range(m):
        a = parts[3 + 3*i]
        b = parts[3 + 3*i + 1]
        c = parts[3 + 3*i + 2]
        edges.append([a, b, c])
    print process_agent(n, k, m, edges)
