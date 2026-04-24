class Graph:
    def __init__(self):
        self.nodes = {}
        self.edges = {}  # store unique edges

    def add_edge(self, u, v, weight):
        if u not in self.nodes:
            self.nodes[u] = []
        if v not in self.nodes:
            self.nodes[v] = []

        self.nodes[u].append((v))
        self.nodes[v].append((u))

        # store edge uniquely (sorted tuple)
        self.edges[tuple(sorted((u, v)))] = weight

    def get_weight(self, u, v):
        return self.edges[tuple(sorted((u, v)))]

    def set_weight(self, u, v, weight):
        self.edges[tuple(sorted((u, v)))] = weight