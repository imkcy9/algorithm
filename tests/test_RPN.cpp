//
// Created by chengye.ke on 2020/4/4.
//

#include <iostream>
#include "../src/RPN.h"
int main() {
    RPN npr;
    std::cout << npr.toRPN("6 + 2 * 100 - 100") << std::endl;
    std::cout << npr.toRPN("6 + 2 * (100 - 100)") << std::endl;
    std::cout << npr.toRPN("6 + (2 * 100 - 100)") << std::endl;
    std::cout << npr.toRPN("6 + (2 * 100 - 100)*(2+5)") << std::endl;
    return 0;
}