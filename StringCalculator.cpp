#include "StringCalculator.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <regex>

void StringCalculator::checkIfNegative(int number) {
    if (number < 0) {
        throw std::runtime_error("Negative numbers not allowed.");
    }
}

int StringCalculator::checkNumberLimit(int number) {
    return (number > 1000) ? 0 : number;
}

std::vector<int> StringCalculator::extractNumbers(const std::string& input) {
    std::vector<int> numbers;
    
    std::regex pattern(R"(-?\d{1,4})");  // The -? allows for optional negative signs
    std::sregex_iterator iter(input.begin(), input.end(), pattern);
    std::sregex_iterator end;

    for (auto i = iter; i != end; ++i) {
        int number = std::stoi(i->str());

        checkForNegative(number);
        number = checkNumberLimit(number);
        // Add the number to the vector if it's not excluded
        if (number != 0) {
            numbers.push_back(number);
        }
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
