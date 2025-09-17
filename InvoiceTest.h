#pragma once
#include <iostream>
#include "Invoice.h"

class InvoiceTest {
public:
    void runTests() {
        testConstructor();
        testAddServiceCost();
        testGetInvoiceId();
    }

private:
    void assertEq(int got, int want, const char* name) {
        if (got != want) {
            std::cout << "[FAIL] " << name << "  got=" << got << " want=" << want << "\n";
        } else {
            std::cout << "[PASS] " << name << "\n";
        }
    }

    void assertStrEq(const std::string& got, const std::string& want, const char* name) {
        if (got != want) {
            std::cout << "[FAIL] " << name << "  got=" << got << " want=" << want << "\n";
        } else {
            std::cout << "[PASS] " << name << "\n";
        }
    }

    void testConstructor() {
        Invoice inv("INV001");
        assertStrEq(inv.getInvoiceId(), "INV001", "constructor sets ID");
        assertEq(inv.getDollarsOwed(), 0, "constructor starts with 0 owed");
    }

    void testAddServiceCost() {
        Invoice inv("INV002");
        inv.addServiceCost(10);
        assertEq(inv.getDollarsOwed(), 10, "addServiceCost adds correctly");

        inv.addServiceCost(5);
        assertEq(inv.getDollarsOwed(), 15, "addServiceCost accumulates");

        bool threw = false;
        try { inv.addServiceCost(0); } catch(...) { threw = true; }
        if (!threw) std::cout << "[FAIL] addServiceCost rejects nonpositive\n";
        else std::cout << "[PASS] addServiceCost rejects nonpositive\n";
    }

    void testGetInvoiceId() {
        Invoice inv("XYZ123");
        assertStrEq(inv.getInvoiceId(), "XYZ123", "getInvoiceId returns correct ID");
    }
};