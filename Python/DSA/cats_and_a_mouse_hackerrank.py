import math
import os
import random
import re
import sys

# Complete the catAndMouse function below.
def catAndMouse(x, y, z):
    dist_a = abs(x - z)
    dist_b = abs(y - z)
    
    if dist_a < dist_b:
        return "Cat A"
    elif dist_a > dist_b:
        return "Cat B"
    else:
        return "Mouse C"

catAndMouse(1, 2, 3)
catAndMouse(1, 3, 2)