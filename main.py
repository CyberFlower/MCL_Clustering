import matplotlib
import numpy as np
from numpy import array
import markov_clustering as mc
import networkx as nx
import pandas as pd
import openpyxl

numNodes=15

def csv2adj_graph():
    result=list()
    xlsx=pd.read_excel("input.xlsx",sheet_name="Adjacency Matrix").fillna(0).values
    for i in range(0,numNodes):
        for j in range(1,numNodes+1):
            if xlsx[i][j]!=0.0:
                result.append((i,j-1,xlsx[i][j]))
    return result


if __name__=='__main__':
    graph = nx.DiGraph()
    for i in range(numNodes):
        graph.graph[i]=i+1
    graph.add_weighted_edges_from(csv2adj_graph())

    matrix=nx.to_scipy_sparse_matrix(graph)
    
    result=mc.run_mcl(matrix, inflation=2.0, verbose=False)
    clusters=mc.get_clusters(result)
    print(clusters)
    for i in range(len(clusters)):
        for j in range(len(clusters[i])):
            print(graph.graph[clusters[i][j]],end=" ")
        print()
    # mc.draw_graph(matrix, clusters, pos=positions, node_size=50, with_labels=False, edge_color="silver")
