#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>

class StringCalculator {
public:
    int add(const std::string& numbers);
private:
    std::string extractDelimiters(std::string& numbers);
    std::vector<std::string> tokenize(const std::string& numbers, const std::string& delimiters);
    int parseAndSum(const std::vector<std::string>& tokens);
};

#endif // STRINGCALCULATOR_H
