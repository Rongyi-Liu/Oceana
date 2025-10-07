#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>

class RecordsManager {
public:
    std::vector<int> read(const std::string& path) {
        std::ifstream file;
        file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try {
            file.open(path);
            std::vector<int> records;
            std::string line;
            while (std::getline(file, line)) {
                int value = std::stoi(line);
                records.push_back(value);
            }
            file.close();
            return records;
        }
        catch (const std::invalid_argument&) {
            std::cout << "invalid_argument error\n";
            safeClose(file);
            throw;
        }
        catch (const std::out_of_range&) {
            std::cout << "out_of_range error\n";
            safeClose(file);
            throw;
        }
        catch (const std::ios_base::failure&) {
            std::cout << "ios_base::failure error\n";
            safeClose(file);
            throw;
        }
    }
private:
    static void safeClose(std::ifstream& f) {
        if (f.is_open()) {
            try { f.close(); } catch (...) {}
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << (argc > 0 ? argv[0] : "sum_records") << " <file1> [file2 ...]\n";
        return 1;
    }
    for (int i = 1; i < argc; ++i) {
        const std::string filename = argv[i];
        try {
            RecordsManager rm;
            const auto records = rm.read(filename);
            long long sum = 0;
            for (int v : records) sum += v;
            std::cout << sum << "\n";
        }
        catch (const std::exception& e) {
            std::cerr << "Error in '" << filename << "': " << e.what() << "\n";
        }
    }
    return 0;
}
