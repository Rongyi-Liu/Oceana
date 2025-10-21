#include <iostream>
#include "BrowserHistory.h"

int main() {
    BrowserHistory browser;

    std::cout << "Current page: " << browser.getCurrentPage() << std::endl;

    browser.visitPage("google.com");
    browser.visitPage("youtube.com");
    browser.visitPage("github.com");

    std::cout << "Current: " << browser.getCurrentPage() << std::endl;
    std::cout << "Back history size: " << browser.getBackHistorySize() << std::endl;

    while (browser.canGoBack()) {
        browser.goBack();
        std::cout << "Went back to: " << browser.getCurrentPage() << std::endl;
    }

    std::cout << "Final page: " << browser.getCurrentPage() << std::endl;

    return 0;
}
