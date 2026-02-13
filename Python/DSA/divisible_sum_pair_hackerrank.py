import math
import os
import random
import re
import sys

#
# Complete the 'divisibleSumPairs' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER k
#  3. INTEGER_ARRAY ar
#

def divisibleSumPairs(n, k, ar):
    # Write your code here
    remainder_count = [0] * k
    result = 0

    for x in ar:
        rem = x % k

        target_rem = 0 if rem == 0 else k - rem
        result += remainder_count[target_rem]

        remainder_count[rem] += 1
    
    return result
    