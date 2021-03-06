# https://github.com/NKID00/5x5
# Copyright (c) 2021 NKID00
# SPDX-License-Identifier: MIT

from csv import writer, QUOTE_NONE
from collections import Counter
from itertools import combinations, permutations
from functools import reduce
from operator import mul

NUMBERS = (
     1,  2,  3,  4,  5,
     6,  7,  8,  9, 10,
    11, 12,     14, 15,
    16,     18,     20,
    21, 22,     24, 25,
)


def main():
    with open('data.txt', 'w', encoding='utf8') as f:
        product_counter = Counter(map(
            lambda i: reduce(mul, i), combinations(NUMBERS, 4)
        ))
        for i in permutations(NUMBERS, 4):
            if product_counter[reduce(mul, i)] == 1:
                f.write(' '.join(map(str, i)) + '\n')


if __name__ == '__main__':
    main()
