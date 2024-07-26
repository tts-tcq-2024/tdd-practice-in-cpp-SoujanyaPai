#include "StringCalculator.h"
#include <stdexcept>
#include <sstream>
#include <vector>
#include <algorithm>
#include <regex>

namespace {

bool isNumber(const std::string& s) {
    return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}
} // namespace

std::string StringCalculator::extractDelimiters(std::string& numbers) {
    std::string delimiters = ",\n";
    if (numbers.rfind("//", 0) == 0) {
        size_t delimEnd = numbers.find("\n");
        delimiters = numbers.substr(2, delimEnd - 2);
        numbers = numbers.substr(delimEnd + 1);
    }
    return delimiters;
}

std::vector<std::string> StringCalculator::tokenize(const std::string& numbers, const std::string& delimiters) {
    std::regex regex("[" + delimiters + "]+");
    std::sregex_token_iterator it(numbers.begin(), numbers.end(), regex, -1);
    std::sregex_token_iterator reg_end;
    return std::vector<std::string>(it, reg_end);
}

int StringCalculator::parseAndSum(const std::vector<std::string>& tokens) {
    int sum = 0;
    std::vector<int> negatives;

    for (const std::string& token : tokens) {
        if (!isNumber(token)) continue;
        int number = std::stoi(token);
        if (number < 0) {
            negatives.push_back(number);
        } else if (number <= 1000) {
            sum += number;
        }
    }

    if (!negatives.empty()) {
        std::ostringstream oss;
        oss << "Negatives not allowed: ";
        for (int neg : negatives) {
            oss << neg << " ";
        }
        throw std::runtime_error(oss.str());
    }

    return sum;
}

int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    std::string numStr = numbers;
    std::string delimiters = extractDelimiters(numStr);
    std::vector<std::string> tokens = tokenize(numStr, delimiters);
    return parseAndSum(tokens);
}
