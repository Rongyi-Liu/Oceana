#pragma once
#include <iostream>
#include "Addition.h"

class EquivalenceTests {
public:
    void runTests() {
        testPositiveIntegers();
        testNegativeIntegers();
        testMixedSigns();
        testZeroes();
        testSpecialCases();
    }

private:
    void assertEq(int got, int want, const char* name) {
        if (got != want) {
            std::cout << "[FAIL] " << name << "  got=" << got << " want=" << want << "\n";
        } else {
            std::cout << "[PASS] " << name << "\n";
        }
    }

    void testPositiveIntegers() {
        Addition add;
        assertEq(add.add(5, 10), 15, "positive integers");
    }

    void testNegativeIntegers() {
        Addition add;
        assertEq(add.add(-4, -5), -9, "negative integers");
    }

    void testMixedSigns() {
        Addition add;
        assertEq(add.add(-7, 10), 3, "mixed signs");
    }

    void testZeroes() {
        Addition add;
        assertEq(add.add(0, 0), 0, "zeros");
    }

    void testSpecialCases() {
        Addition add;
        assertEq(add.add(1, -1), 0, "1 and -1 cancel");
    }
};