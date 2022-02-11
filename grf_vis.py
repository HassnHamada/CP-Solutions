import networkx as nx
import matplotlib.pyplot as plt
from networkx.drawing.layout import random_layout


class GraphVisualization:

    def __init__(self, n):
        self.visual = []
        self.n = n
        self.node_color = ['#ff0000'] * n

    def addEdge(self, a, b, c):
        self.visual.append((a, b, {'W': c}))

    def visualize(self):
        G = nx.DiGraph()
        G.add_nodes_from(range(self.n))
        G.add_edges_from(self.visual)
        nx.draw_networkx(G, arrows=True, node_color=self.node_color,
                         pos=random_layout(G, seed=10))
        plt.show()
