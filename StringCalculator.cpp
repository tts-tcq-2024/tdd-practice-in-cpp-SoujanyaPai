#include "StringCalculator.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <regex>

void StringCalculator::checkIfNegative(int number) {
    if (number < 0) {
        throw std::runtime_error("Negative numbers are not accepted!");
    }
}

int StringCalculator::checkNumberLimit(int number) {
    return (number > 1000) ? 0 : number;
}

std::vector<int> StringCalculator::extractNumbers(const std::string& input) {
    std::vector<int> numbers;
    
    std::regex pattern(R"(-?\d{1,4})");  // The -? allows negative signs
    std::sregex_iterator checkPattern(input.begin(), input.end(), pattern);
    std::sregex_iterator end;

    for (auto i = checkPattern; i != end; ++i) {
        int number = std::stoi(i->str());
        checkIfNegative(number);
        number = checkNumberLimit(number);
        numbers.push_back(number);
    }
    return numbers;
}

int StringCalculator::calculateSum(const std::vector<int>& numbers) {
    int sum = 0;
    for (int number : numbers) {
        sum += number;
    }
    return sum;
}

int StringCalculator::add(const std::string& input) {
    if (input.empty()) {
        return 0;
    }
    std::vector<int> numbers = extractNumbers(input);
    return calculateSum(numbers);
}
