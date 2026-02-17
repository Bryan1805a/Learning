import math
import os
import random
import re
import sys

#
# Complete the 'countingValleys' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER steps
#  2. STRING path
#

def countingValleys(steps, path):
    # Write your code here
    sea_level = 0
    previous_level = 0
    valley_count = 0

    for i in range(steps):
        if path[i] == 'U':
            previous_level = sea_level
            sea_level += 1
        elif path[i] == 'D':
            previous_level = sea_level
            sea_level -= 1
        
        if sea_level == 0 and previous_level < 0:
            valley_count += 1
    
    return valley_count

print(countingValleys(8, "UDDDUDUU"))