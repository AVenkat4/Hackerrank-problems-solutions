#!/bin/python

import math
import os
import random
import re
import sys

# Complete the roadsAndLibraries function below.
def roadsAndLibraries(n, c_lib, c_road, cities):

    def dfs(adj, visited, i, c):
        visited[i] = 1
        for neighbors in adj[i]:
            if visited[neighbors] == 0:
                c[-1] += 1
                dfs(adj, visited, neighbors, c)
        

    if c_road >= c_lib:
        return c_lib * n
    
    adj = {}
    for i in range(1, n+1):
        adj[i] = []

    for pair in cities:
        adj[pair[0]].append(pair[1])
        adj[pair[1]].append(pair[0])

    conn_compo = 0
    visited = [0]*(n+1)
    total = 0
    c = []
    for i in range(1, n+1): 
        if visited[i] == 0:
            c.append(0)
            dfs(adj, visited, i, c)
            total += (c[-1])*c_road + c_lib
            #print(i, total, c)
    
    return total


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(raw_input())

    for q_itr in xrange(q):
        nmC_libC_road = raw_input().split()

        n = int(nmC_libC_road[0])

        m = int(nmC_libC_road[1])

        c_lib = int(nmC_libC_road[2])

        c_road = int(nmC_libC_road[3])

        cities = []

        for _ in xrange(m):
            cities.append(map(int, raw_input().rstrip().split()))

        result = roadsAndLibraries(n, c_lib, c_road, cities)

        fptr.write(str(result) + '\n')

    fptr.close()
