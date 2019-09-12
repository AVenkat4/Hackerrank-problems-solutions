#!/bin/python

import math
import os
import random
import re
import sys

# Complete the maximumPerimeterTriangle function below.
def maximumPerimeterTriangle(sticks):

    sticks = sorted(sticks)

    i = n-1
    while i >= 2:
        if sticks[i-2] + sticks[i-1] <= sticks[i]:
            i -= 1
        else: 
            break
    if i >= 2:
        return (sticks[i-2], sticks[i-1], sticks[i])
    
    return [-1]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(raw_input())

    sticks = map(int, raw_input().rstrip().split())

    result = maximumPerimeterTriangle(sticks)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
