#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<unsigned int>> generateSubsets(unsigned int sizeOfSet);
void outputSubsets(const std::vector<std::vector<unsigned int>>& subSets);

int main() {
    setlocale(LC_ALL, "Russian");

    unsigned int digit;
    bool good = true;
    std::string inputStr;

    while (good) {
        std::cout << "Введите размер множества от 0 до 9 включительно для генерации подмножеств или любую другую комбинацию непробельных символов для завершения:\n";

        std::cin >> inputStr;

        inputStr.erase(std::remove_if(inputStr.begin(), inputStr.end(), std::isspace), inputStr.end());

        if (inputStr.length() == 1 && std::isdigit(inputStr[0])) {
            digit = std::stoi(inputStr);

            auto subSets = generateSubsets(digit);

            outputSubsets(subSets);

            std::cout << "\n";
        }
        else {
            good = false;
        }
    }
}

std::vector<std::vector<unsigned int>> generateSubsets(unsigned int sizeOfSet) {
    std::vector<std::vector<unsigned int>> subSets;

    subSets.push_back({});

    int addedNum = 1;

    while (sizeOfSet--) {
        int cnt = subSets.size() - 1;

        while (cnt >= 0) {
            subSets.push_back(subSets[cnt]);
            subSets.back().push_back(addedNum);
            cnt--;
        }

        addedNum++;
    }

    return subSets;
}

void outputSubsets(const std::vector<std::vector<unsigned int>> & subSets) {
    for (auto & subSet : subSets)
    {
        std::cout << "{";
        for (int d = 0; d < subSet.size(); d++) {
            if (d) {
                std::cout << ", ";
            }
            std::cout << subSet[d];
        }
        std::cout << "}\n";
    }
}
