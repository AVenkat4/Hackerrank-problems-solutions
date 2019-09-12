#!/bin/python

import math
import os
import random
import re
import sys

# Complete the candies function below.
def candies(n, arr):

    candy = [1]*n

    for i in range(1, n):
        if arr[i] > arr[i-1]:
            candy[i] = candy[i-1] + 1

    #print(candy)
    for i in range(n-2, -1, -1):
        if arr[i] > arr[i+1] and candy[i] <= candy[i+1]:
            candy[i] = candy[i+1] + 1
    #print(candy)
    return sum(candy)   

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(raw_input())

    arr = []

    for _ in xrange(n):
        arr_item = int(raw_input())
        arr.append(arr_item)

    result = candies(n, arr)

    fptr.write(str(result) + '\n')

    fptr.close()
