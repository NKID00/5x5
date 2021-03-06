// https://github.com/NKID00/5x5
// Copyright (c) 2021 NKID00
// SPDX-License-Identifier: MIT

#include <iostream>
#include <cstdint>
#include <mutex>
#include <atomic>
#include <thread>
#include <chrono>
#include <ctime>
#include <vector>
#include <sstream>
#include <fstream>

// for loop
#define loop(n) \
    for (; n <= 25; n++)

// skip the prime numbers
#define skip(n)   \
    switch (n)    \
    {             \
    case 13:      \
    case 17:      \
    case 19:      \
    case 23:      \
        continue; \
    }

// `skip` and assign `used`
#define skip_assign(n) \
    skip(n);           \
    u[n] = true // eat the semicolon

// `skip` and check if the number is used
#define skip_check(n) \
    skip(n);          \
    if (u[n])         \
    {                 \
        continue;     \
    }

// `skip_check` and assign `used`
#define skip_check_assign(n) \
    skip_check(n);           \
    u[n] = true // eat the semicolon

// check if the matrix fits the rule or add `count`
#define check_rule(rule, skip_count) \
    if (!(rule))                     \
    {                                \
        continue;                    \
    }

void work(std::int8_t n1, std::mutex &m, std::atomic_uint64_t &result_count, std::atomic_uint8_t &finished_count, std::ofstream &f)
{
    // loop indexes, number means index in the matrix
    std::uint8_t n2 = 2, n3 = 3, n4 = 8, n5 = 1, n10 = 1, n15 = 1, n20 = 1,
                 n7 = 1, n8 = 1, n9 = 1, n11 = 1, n16 = 1, n21 = 1,
                 n13 = 1, n14 = 1, n17 = 1, n22 = 1,
                 n19 = 1, n23 = 1;

    bool u[26]; // used
    for (int i = 0; i <= 25; i++)
    {
        u[i] = false;
    }
    u[n1] = true;

    // 2-2
    loop(n2)
    {
        skip_check_assign(n2);
        // 3-3
        loop(n3)
        {
            skip_check_assign(n3);
            // 4-4
            loop(n4)
            {
                skip_check_assign(n4);
                // 5-5
                loop(n5)
                {
                    skip_check_assign(n5);
                    // 6-10
                    loop(n10)
                    {
                        skip_check_assign(n10);
                        // 7-15
                        loop(n15)
                        {
                            skip_check_assign(n15);
                            // 8-20
                            loop(n20)
                            {
                                skip_check(n20);
                                // check1
                                check_rule(n1 * n2 * n3 * n4 == n5 * n10 * n15 * n20, 6227020800);
                                u[n20] = true;
                                // 9-7
                                loop(n7)
                                {
                                    skip_check_assign(n7);
                                    // 10-8
                                    loop(n8)
                                    {
                                        skip_check_assign(n8);
                                        // 11-9
                                        loop(n9)
                                        {
                                            skip_check_assign(n9);
                                            // 12-11
                                            loop(n11)
                                            {
                                                skip_check_assign(n11);
                                                // 13-16
                                                loop(n16)
                                                {
                                                    skip_check_assign(n16);
                                                    // 14-21
                                                    loop(n21)
                                                    {
                                                        skip_check(n21);
                                                        // check2
                                                        check_rule(n5 * n7 * n8 * n9 == n1 * n11 * n16 * n21, 5040);
                                                        u[n21] = true;
                                                        // 15-13
                                                        loop(n13)
                                                        {
                                                            skip_check_assign(n13);
                                                            // 16-14
                                                            loop(n14)
                                                            {
                                                                skip_check_assign(n14);
                                                                // 17-17
                                                                loop(n17)
                                                                {
                                                                    skip_check_assign(n17);
                                                                    // 18-22
                                                                    loop(n22)
                                                                    {
                                                                        skip_check(n22);
                                                                        // check3
                                                                        check_rule(n10 * n11 * n13 * n14 == n2 * n7 * n17 * n22, 6);
                                                                        u[n22] = true;
                                                                        // 19-19
                                                                        loop(n19)
                                                                        {
                                                                            skip_check_assign(n19);
                                                                            // 20-23
                                                                            loop(n23)
                                                                            {
                                                                                skip_check(n23);
                                                                                // check4
                                                                                check_rule(n15 * n16 * n17 * n19 == n3 * n8 * n13 * n23, 1);
                                                                                // check5
                                                                                check_rule(n20 * n21 * n22 * n23 == n4 * n9 * n14 * n19, 1);

                                                                                // here comes the right matrix
                                                                                std::stringstream ss;
                                                                                ss << "\t" << n1 << "\t" << n2 << "\t" << n3 << "\t" << n4 << std::endl
                                                                                   << n5 << "\t\t" << n7 << "\t" << n8 << "\t" << n9 << std::endl
                                                                                   << n10 << "\t" << n11 << "\t\t" << n13 << "\t" << n14 << std::endl
                                                                                   << n15 << "\t" << n16 << "\t" << n17 << "\t\t" << n19 << std::endl
                                                                                   << n20 << "\t" << n21 << "\t" << n22 << "\t" << n23 << std::endl
                                                                                   << std::endl;
                                                                                auto s = ss.str();
                                                                                {
                                                                                    std::lock_guard<std::mutex> lock(m);
                                                                                    f << s;
                                                                                }
                                                                                result_count += 120; // 5!
                                                                            }
                                                                            n23 = 1;
                                                                            u[n19] = false;
                                                                        }
                                                                        n19 = 1;
                                                                        u[n22] = false;
                                                                    }
                                                                    n22 = 1;
                                                                    u[n17] = false;
                                                                }
                                                                n17 = 1;
                                                                u[n14] = false;
                                                            }
                                                            n14 = 1;
                                                            u[n13] = false;
                                                        }
                                                        n13 = 1;
                                                        u[n21] = false;
                                                    }
                                                    n21 = 1;
                                                    u[n16] = false;
                                                }
                                                n16 = 1;
                                                u[n11] = false;
                                            }
                                            n11 = 1;
                                            u[n9] = false;
                                        }
                                        n9 = 1;
                                        u[n8] = false;
                                    }
                                    n8 = 1;
                                    u[n7] = false;
                                }
                                n7 = 1;
                                u[n20] = false;
                            }
                            n20 = 1;
                            u[n15] = false;
                        }
                        n15 = 1;
                        u[n10] = false;
                    }
                    n10 = 1;
                    u[n5] = false;
                }
                n5 = 1;
                u[n4] = false;
            }
            n4 = 1;
            u[n3] = false;
        }
        n3 = 1;
        u[n2] = false;
    }
    finished_count++;
}

int main()
{
    /*
    matrix:
        xx  1  2  3  4
         5 xx  7  8  9
        10 11 xx 13 14
        15 16 17 xx 19
        20 21 22 23 xx

    order:
        xx  1  2  3  4
         5 xx  9 10 11
         6 12 xx 15 16
         7 13 17 xx 19
         8 14 18 20 xx

    loops:
        1-1 / 2-2 / 3-3 / 4-4 / 5-5 / 6-10 / 7-15 / 8-20 / check1 /
        9-7 / 10-8 / 11-9 / 12-11 / 13-16 / 14-21 / check2 /
        15-13 / 16-14 / 17-17 / 18-22 / check3 /
        19-19 / 20-23 / check4
    */

    // matrix checked or skiped count
    std::atomic_uint64_t result_count;
    std::atomic_uint8_t finished_count, finished_count_expected;
    result_count = finished_count = finished_count_expected = 0;

    std::ofstream f("result.txt");

    std::mutex m;
    std::thread([&m, &result_count, &finished_count, &finished_count_expected]() {
        std::clock_t time_latest = std::clock();
        std::uint64_t result_count_latest = 0;
        while (true)
        {
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::uint64_t result_count_copy = result_count;
            std::clock_t time_now = std::clock();
            std::cerr << "\r"
                      << result_count_copy << " (" << (result_count_copy - result_count_latest) * 1000 / (time_now - time_latest) << "/s) "
                      << (int)finished_count << "/" << (int)finished_count_expected
                      << "          " << std::flush;
            time_latest = time_now;
            result_count_latest = result_count_copy;
        }
    }).detach();

    std::uint8_t n1 = 1;
    std::vector<std::thread> threads;
    // 1-1
    loop(n1)
    {
        // no need to check if the number is used
        skip(n1);
        // create threads
        threads.emplace_back(work, n1, std::ref(m), std::ref(result_count), std::ref(finished_count), std::ref(f));
        finished_count_expected++;
    }
    for (std::thread &t : threads)
    {
        t.detach();
    }
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        if (finished_count == finished_count_expected)
        {
            break;
        }
    }
    std::cerr << std::endl;
}
