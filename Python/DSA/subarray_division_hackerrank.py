import math
import os
import random
import re
import sys

#
# Complete the 'birthday' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY s
#  2. INTEGER d
#  3. INTEGER m
#

def birthday(s, d, m):
    # Write your code here
    if len(s) < m:
        return 0
    
    current_sum = sum(s[:m])
    result = 0

    if current_sum == d:
        result += 1

    for i in range(m, len(s)):
        current_sum += s[i] - s[i - m]

        if current_sum == d:
            result += 1

    
    return result

print(birthday([2, 2, 1, 3, 2], 4, 2))