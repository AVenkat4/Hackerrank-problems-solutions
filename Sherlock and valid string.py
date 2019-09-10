#!/bin/python

import math
import os
import random
import re
import sys
from collections import Counter
from collections import defaultdict
# Complete the isValid function below.
def isValid(s):
    c = Counter(s)
    freq = list(c.values())
    values = sorted(freq)
    if values.count(values[0]) == len(values):
        return "YES"
    if values.count(values[0]) == len(values) - 1 and values[-1] - values[-2] == 1:
        return "YES"
    if values.count(values[-1]) == len(values) -1 and values[0] == 1:
        return "YES"
    return "NO"
    
    
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = raw_input()

    result = isValid(s)

    fptr.write(result + '\n')

    fptr.close()
