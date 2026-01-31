import math
import os
import random
import re
import sys

#
# Complete the 'countApplesAndOranges' function below.
#
# The function accepts following parameters:
#  1. INTEGER s
#  2. INTEGER t
#  3. INTEGER a
#  4. INTEGER b
#  5. INTEGER_ARRAY apples
#  6. INTEGER_ARRAY oranges
#

def countApplesAndOranges(s, t, a, b, apples, oranges):
    # Write your code here
    print(sum(s <= d + a <= t for d in apples))
    print(sum(s <= d + b <= t for d in oranges))



countApplesAndOranges(7, 11, 5, 15, [-2, 2, 1], [5, -6])