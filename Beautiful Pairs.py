#!/bin/python

import math
import os
import random
import re
import sys
from collections import Counter
# Complete the beautifulPairs function below.
def beautifulPairs(A, B):

    n = len(A)
    countA, countB = Counter(A), Counter(B)
    a_b = countA - countB
    b_a = countB - countA
    bset = countA - a_b
    setsize = sum([bset[i] for i in bset])
    if len(b_a) >0 and len(a_b) > 0:
        return setsize + 1
    elif len(a_b) == 0 and len(b_a) > 0:
        return setsize
    elif len(b_a) == 0 and len(a_b) >= 0:
        return setsize - 1

    return setsize

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(raw_input())

    A = map(int, raw_input().rstrip().split())

    B = map(int, raw_input().rstrip().split())

    result = beautifulPairs(A, B)

    fptr.write(str(result) + '\n')

    fptr.close()
