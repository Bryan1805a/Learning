import math
import os
import random
import re
import sys
from functools import reduce

#
# Complete the 'getTotalX' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY a
#  2. INTEGER_ARRAY b
#

def getTotalX(a, b):
    # Write your code here
    def lcm(x, y):
        return (x * y) // math.gcd(x, y)
    
    lcm_a = reduce(lcm, a)
    gcd_b = reduce(math.gcd, b)

    count = 0
    multiple = lcm_a

    while multiple <= gcd_b:
        if gcd_b % multiple == 0:
            count += 1
        multiple += lcm_a
    
    return count