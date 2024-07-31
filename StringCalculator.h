#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>

class StringCalculator {
public:
    int add(const std::string& input);
private:
    void checkIfNegative(int number);
    int checkIfGreaterthan1000(int number);
    std::vector<int> extractNumbers(const std::string& numbers);
    int calculateSum(const std::vector<int>& numbers);
};

#endif // STRINGCALCULATOR_H
