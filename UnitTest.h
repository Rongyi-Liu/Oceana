#pragma once
#include <iostream>
#include "Addition.h"

class UnitTest {
public:
    void runTests() {
        testAddition();
    }

private:
    void assertEq(int got, int want, const char* name) {
        if (got != want) {
            std::cout << "[FAIL] " << name << "  got=" << got << " want=" << want << "\n";
        } else {
            std::cout << "[PASS] " << name << "\n";
        }
    }

    void testAddition() {
        Addition add;
        assertEq(add.add(1, 2), 3, "add small positives");
        assertEq(add.add(-4, -5), -9, "add negatives");
        assertEq(add.add(-7, 10), 3, "add mixed signs");
        assertEq(add.add(0, 0), 0, "add zeros");
        assertEq(add.add(0, 42), 42, "add zero + positive");
        assertEq(add.add(0, -42), -42, "add zero + negative");
    }
};