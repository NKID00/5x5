// https://github.com/NKID00/5x5
// Copyright (c) 2021 NKID00
// SPDX-License-Identifier: MIT

#include <iostream>
#include <cstdint>

void print_table(std::int32_t* table)
{
	std::cout << std::endl;
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            std::cout << table[y * 5 + x] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool check(std::int32_t* t)
{
	static int count = 0;
	if (count % 1000000 == 0)
	{
		std::cout << count << "\r";
	}
	count++;
    for (int i = 0; i < 5; i++)
    {
        int b = i * 5;
        if (t[b]*t[b+1]*t[b+2]*t[b+3]*t[b+4] \
            != t[i]*t[i+5]*t[i+10]*t[i+15]*t[i+20])
        {
            return false;
        }
    }
    return true;
}

void work(std::int32_t* table, int n, bool* used)
{
    if (n == 25)
    {

        if (check(table))
        {
            print_table(table);
        }
        return;
    }
    for (int i = 0; i < 25; i++)
    {
        if (used[i])
        {
            continue;
        }
        table[n] = i;
        used[i] = true;
        work(table, n + 1, used);
        used[i] = false;
    }
}

int main()
{
    std::int32_t table[25];
    bool used[25];

    for (int i = 0; i < 25; i++)
    {
        used[i] = false;
    }

    work(table, 0, used);

    return 0;
}
