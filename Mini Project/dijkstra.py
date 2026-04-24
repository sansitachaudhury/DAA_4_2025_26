import heapq
def dijkstra(graph, start):
    distances = {node: float('inf') for node in graph.nodes}
    distances[start] = 0    
    pq = [(0, start)]
    previous = {}
    while pq:
        current_dist, current_node = heapq.heappop(pq)
        for neighbor in graph.nodes[current_node]:
            weight = graph.get_weight(current_node, neighbor)
            distance = current_dist + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                previous[neighbor] = current_node
                heapq.heappush(pq, (distance, neighbor))
    return distances, previous

def get_path(previous, start, end):
    path = []
    while end != start:
        path.append(end)
        end = previous.get(end)
        if end is None:
            return []
    path.append(start)
    path.reverse()
    return path