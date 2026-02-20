import math
import os
import random
import re
import sys

#
# Complete the 'hurdleRace' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER k
#  2. INTEGER_ARRAY height
#

def hurdleRace(k, height):
    # Write your code here
    total_doses = 0

    tallest_hurdle = max(height)
    if k < tallest_hurdle:
        total_doses += tallest_hurdle - k
    
    return total_doses

print(hurdleRace(4, [1, 6, 3, 5, 2]))