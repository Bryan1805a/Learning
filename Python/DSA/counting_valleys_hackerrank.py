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
    level = 0
    valley_count = 0

    for step in path:
        if step == 'U':
            level += 1

            if level == 0:
                valley_count += 1
        else:
            level -= 1
    
    return valley_count

print(countingValleys(8, "UDDDUDUU"))