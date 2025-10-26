# Lukasz Rudnik

def dfs(v, graph, visited, stack=None):
    visited[v] = True
    for u in graph[v]:
        if not visited[u]:
            dfs(u, graph, visited, stack)
    if stack is not None:
        stack.append(v)

def dfs_collect(v, graph, visited, result):
    visited[v] = True
    result.append(v)
    for u in graph[v]:
        if not visited[u]:
            dfs_collect(u, graph, visited, result)

def reverse_graph(n, graph):
    rev = []
    for _ in range(n):
        rev.append([])
    for v in range(n):
        for u in graph[v]:
            rev[u].append(v)
    return rev

def kosaraju(n, edges):
    graph = []
    for _ in range(n):
        graph.append([])
    for a, b in edges:
        graph[a].append(b)

    visited = []
    for _ in range(n):
        visited.append(False)
    stack = []
    for i in range(n):
        if not visited[i]:
            dfs(i, graph, visited, stack)

    rev = reverse_graph(n, graph)
    visited = []
    for _ in range(n):
        visited.append(False)
    comp_id = []
    for _ in range(n):
        comp_id.append(-1)

    curr_comp = 0
    while stack:
        node = stack.pop()
        if not visited[node]:
            component = []
            dfs_collect(node, rev, visited, component)
            for v in component:
                comp_id[v] = curr_comp
            curr_comp += 1

    scc_count = curr_comp
    scc_graph = []
    for _ in range(scc_count):
        scc_graph.append({})
    indegree = []
    for _ in range(scc_count):
        indegree.append(0)

    for i in range(len(edges)):
        a = edges[i][0]
        b = edges[i][1]
        ca = comp_id[a]
        cb = comp_id[b]
        if ca != cb and cb not in scc_graph[ca]:
            scc_graph[ca][cb] = True
            indegree[cb] += 1

    zero_indegree = []
    for i in range(scc_count):
        if indegree[i] == 0:
            zero_indegree.append(i)

    if len(zero_indegree) != 1:
        return -1

    start_scc = zero_indegree[0]
    candidates = []
    for i in range(n):
        if comp_id[i] == start_scc:
            candidates.append(i)

    start_node = candidates[0]
    for i in candidates:
        if i < start_node:
            start_node = i

    visited = []
    for _ in range(n):
        visited.append(False)
    dfs(start_node, graph, visited)

    for i in range(n):
        if not visited[i]:
            return -1
    return start_node

def main():
    G = int(raw_input())
    for _ in range(G):
        line = raw_input()
        parts = line.strip().split()
        n = int(parts[0])
        m = int(parts[1])
        edges = []
        for i in range(m):
            a = int(parts[2 + 2*i])
            b = int(parts[2 + 2*i + 1])
            edges.append([a, b])
        print kosaraju(n, edges)

main()