import math
import os
import random
import re
import sys

#
# Complete the 'utopianTree' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER n as parameter.
#

def utopianTree(n):
    # Write your code here
    height_of_tree = 1
    
    for i in range(1, n+1):
        if (i % 2 != 0):
            height_of_tree = height_of_tree * 2
            
        else:
            height_of_tree += 1
    
    return height_of_tree

utopianTree(3)