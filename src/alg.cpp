// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    if (num <= 1) {
        return num;
    }

    uint64_t max_val = num;

    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }

        if (num > max_val) {
            max_val = num;
        }
    }

    return max_val;
}

unsigned int collatzLen(uint64_t num) {
    if (num <= 1) {
        return 0;
    }

    unsigned int count = 1;

    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        count++;
    }

    return count;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
    uint64_t best_num = 0;
    unsigned int best_len = 0;

    for (uint64_t i = lbound; i <= rbound; i++) {
        uint64_t n = i;
        unsigned int current_len = 1;

        while (n > 1) {
            if (n % 2 == 0) {
                n = n / 2;
            } else {
                n = 3 * n + 1;
            }
            current_len++;
        }

        if (current_len > best_len) {
            best_len = current_len;
            best_num = i;
        }
        if (i == rbound) break;
    }

    *maxlen = best_len;
    return (unsigned int)best_num;
}
