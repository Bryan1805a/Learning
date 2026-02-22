import math
import os
import random
import re
import sys

#
# Complete the 'designerPdfViewer' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY h
#  2. STRING word
#

def designerPdfViewer(h, word):
    # Write your code here
    tallest_word = 0
    for i in word:
        if h[ord(i) - ord('a')] > tallest_word:
            tallest_word = h[ord(i) - ord('a')]

    return tallest_word * len(word)

h = [1, 3, 1, 3, 1, 4, 1, 3, 2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5]
word = "abc"

print(designerPdfViewer(h, word))