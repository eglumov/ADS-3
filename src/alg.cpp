// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    if (num == 0) return 0;
    
    uint64_t peak = num;
    for (; num > 1; ) {
        num = (num & 1) ? (num * 3 + 1) : (num >> 1);
        if (num > peak) {
            peak = num;
        }
    }
    return peak;
}

unsigned int collatzLen(uint64_t num) {
    if (num == 0) return 0;
    
    unsigned int length = 1;
    for (; num > 1; ++length) {
        num = (num & 1) ? (num * 3 + 1) : (num >> 1);
    }
    return length;
}

unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound, uint64_t rbound) {
    unsigned int max_seq_length = 0;
    uint64_t optimal_start_num = 0;

    for (uint64_t current = lbound; current <= rbound; ++current) {
        unsigned int current_length = collatzLen(current);
        if (current_length > max_seq_length) {
            max_seq_length = current_length;
            optimal_start_num = current;
        }
    }

    *maxlen = max_seq_length;
    return static_cast<unsigned int>(optimal_start_num);
}
