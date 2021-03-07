# https://github.com/NKID00/5x5
# Copyright (c) 2021 NKID00
# SPDX-License-Identifier: MIT


def main():
    line_count = 0
    with open('result.txt', 'r', encoding='utf8') as f:
        while f.readline() != '':
            line_count += 1
    print('line_count: %d\nsolution_count: %d' % (line_count, line_count // 6 * 120))


if __name__ == '__main__':
    main()
