//
// Created by chengye.ke on 2020/4/4.
//

#ifndef ALGORITHM_RPN_H
#define ALGORITHM_RPN_H
#include "../include.h"
/**
 * 逆波兰式（Reverse Polish notation，RPN，或逆波兰记法），也叫后缀表达式（将运算符写在操作数之后）
 */
class RPN {

public:
    RPN();

    /**
     * 后缀表达式转换
     * @param postfixExpression 中缀表达式
     * @return 后缀表达式
     */
    std::string toRPN(std::string postfixExpression);

private:

    /**
     * 获取+ - * /操作符优先级
     * @param char_operator 操作符
     * @return 优先级
     */
    int get_priority(char char_operator);

};


#endif //ALGORITHM_RPN_H
