#pragma once
#include <string>
#include <stdexcept>

class Invoice {
private:
    std::string invoiceId;
    int dollarsOwed; // store in whole dollars for simplicity

public:
    Invoice(const std::string& id) : invoiceId(id), dollarsOwed(0) {}

    void addServiceCost(int costDollars) {
        if (costDollars <= 0) {
            throw std::invalid_argument("Cost must be positive");
        }
        dollarsOwed += costDollars;
    }

    int getDollarsOwed() const {
        return dollarsOwed;
    }

    std::string getInvoiceId() const {
        return invoiceId;
    }
};