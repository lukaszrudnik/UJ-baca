# Lukasz Rudnik

def BFS (graph, node):
    visited = [False] * len(graph)
    Q = [ node ]

    while Q:
        node = Q.pop(0)
        if visited [ node ] == False:
            visited [ node ] = True
            print ( node, end=' ')
            for neighbor in graph [ node ]:
                if visited [ neighbor ] == False:
                    Q.append(neighbor)


def DFS (graph, node):
    visited = [False] * len(graph)
    S = [ node ]

    while S:
        node = S.pop(-1)
        if visited [ node ] == False:
            visited [ node ] = True
            print ( node, end=' ')
            for neighbor in graph [ node ]:
                if visited [ neighbor ] == False:
                    S.append(neighbor)


graph = [
    [],
    [3, 7],
    [3],
    [2, 1, 5, 8],
    [7, 9],
    [3, 6],
    [5, 10],
    [1, 4],
    [3, 9],
    [8, 4],
    [6, 11],
    [10]
]

# main
node = 3
print("BFS: ")
BFS ( graph, node )

print()

print("DFS: ")
DFS ( graph, node )