import random

def dijkstra(graph, start):
    num_nodes = len(graph)
    distances = [float('inf')] * num_nodes
    distances[start] = 0

    visited = [False] * num_nodes
    prev = [-1] * num_nodes  # Tablica poprzedników

    for _ in range(num_nodes):
        # Znajdź wierzchołek o najmniejszej odległości, który nie został jeszcze odwiedzony
        min_dist = float('inf')
        u = -1
        for i in range(num_nodes):
            if not visited[i] and distances[i] < min_dist:
                min_dist = distances[i]
                u = i

        if u == -1:  # Wszystkie dostępne wierzchołki zostały odwiedzone
            break

        visited[u] = True

        # Zaktualizuj odległości dla sąsiadów
        for v in range(num_nodes):
            if graph[u][v] > 0 and not visited[v]:
                alt = distances[u] + graph[u][v]
                if alt < distances[v]:
                    distances[v] = alt
                    prev[v] = u  # Zapisz poprzednika

    return distances, prev

def reconstruct_path(prev, start, end):
    path = []
    current = end
    while current != -1:
        path.append(current)
        current = prev[current]
    path.reverse()
    return path if path[0] == start else []  # Zwróć ścieżkę tylko jeśli istnieje


def generate_random_graph(N, k):
    # Inicjalizacja macierzy sąsiedztwa wypełnionej zerami
    graph = [[0 for _ in range(N)] for _ in range(N)]
    
    # Generowanie krawędzi
    for i in range(N):
        for j in range(i+1, N):  # Unikamy duplikatów i pętli własnych
            if random.random() < 0.55:  # Prawdopodobieństwo 0.55, bo mam wrazenie ze dla 0.5 jest zbyt rzadki graf
                weight = random.randint(1, k)  # Waga z rozkładu U(1,k)
                graph[i][j] = weight
                graph[j][i] = weight  # Graf nieskierowany
    
    return graph

def print_graph(graph):
    for row in graph:
        print(row)



if __name__ == "__main__":
    N = int (input ("Podaj liczbe wierzcholkow\n"))
    k = int (input ("Podaj zakres wag krawedzi\n"))
    graph = generate_random_graph(N, k)
    print ( "Losowo wygenerowany graf:")
    print_graph(graph)

    start_node = int (input ("Podaj wierzcholek startowy\n"))
    distances, prev = dijkstra(graph, start_node)

    print("\nNajkrótsze odległości od węzła", start_node)
    print (distances)

    print("Ścieżki:")
    for end_node in range(len(graph)):
        path = reconstruct_path(prev, start_node, end_node)
        if path:
            print(f"{end_node}: {' -> '.join(map(str, path))}")
        else:
            print(f"Brak ścieżki do {end_node}")