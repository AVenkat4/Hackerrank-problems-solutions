#!/bin/python

import math
import os
import random
import re
import sys

# Complete the decentNumber function below.
def decentNumber(n):

    if n % 3 == 0:
        return int('5' * n)
    else:
        rem = n % 3
        num = n
        q5 = n / 3
        num3 = 0
        while rem % 5 != 0 and num >= 0:
            num = (q5-1)*3
            rem = (n - num) % 5
            num3 = (n - num)
            q5 = num / 3
        
        if num < 0:
            return -1
        return num*'5' + num3*'3'

if __name__ == '__main__':
    t = int(raw_input().strip())

    for t_itr in xrange(t):
        n = int(raw_input().strip())

        print(decentNumber(n))
