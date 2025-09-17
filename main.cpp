#include "UnitTest.h"
#include "EquivalenceTests.h"
#include "InvoiceTest.h"

int main() {
    UnitTest ut;
    ut.runTests();

    EquivalenceTests et;
    et.runTests();

    InvoiceTest it;
    it.runTests();

    return 0;
}