//
// Created by chengye.ke on 2020/4/4.
//

#include "RPN.h"

RPN::RPN() {

}

/**
1、初始化栈和集合：运算符号栈op_stack和存储空间集合ex_stack
2、从左到右扫描中缀表达式
3、遇到操作数时，将其加入ex_stack
4、遇到运算符时，比较其与op_stack栈顶运算符的优先级
  4.1、如果op_stack为空，或栈顶运算符为左括号‘(’，则直接将此运算符入栈
  4.2、否则，若优先级比栈顶运算符的高，也将运算符压入op_stack
  4.3、否则，将op_stack栈顶的运算符弹出并加入到s2中，再次转到 流程4
5、遇到括号时：
  5.1、如果是左括号‘(’，则直接压入ex_stack
  5.2、如果是右括号‘)’，则依次弹出op_stack栈顶的运算符，并且加入ex_stack，直到遇到左括号为止，此时将这一对括号丢弃
6、重复步骤 2-5，直到表达式的最右边
7、将ex_stack中剩余的运算符依次弹出并加入ex_stack
8、ex_stack结果即为中缀表达式对应的后缀表达式
 * @param postfixExpression
 * @return
 */
std::string RPN::toRPN(std::string postfixExpression) {

    std::stack<char> op_stack;
    std::string ex_stack;

    for (size_t index = 0; index != postfixExpression.size(); index++) {
        char c = postfixExpression[index];

        switch(c) {
            case '(':
                op_stack.push(c);
                break;

            case ')':
                while (!op_stack.empty() && op_stack.top() != '(') {
                    ex_stack.push_back(op_stack.top());

                    op_stack.pop();
                }

                if (!op_stack.empty()) {
                    op_stack.pop();
                } else {
                    std::cout << "输入有误，找不到匹配的括号" << std::endl;
                    return std::string();
                }
                break;

            case '+':
            case '-':
            case '*':
            case '/':
                ex_stack.push_back(' ');
                if (op_stack.empty()) {
                    op_stack.push(c);
                    break;
                }
                while (!op_stack.empty() &&
                        get_priority(c) < get_priority(op_stack.top())
                ) {
                    ex_stack.push_back(op_stack.top());
                    op_stack.pop();
                }

                op_stack.push(c);
                break;

            case ' ':

                break;
            default:

                //判断是不是数字
                if (c >= '0' && c <= '9') {
                    ex_stack.push_back(c);
                }

                break;
        }


    }

    while (!op_stack.empty()) {
        ex_stack.push_back(op_stack.top());
        op_stack.pop();
    }
    return ex_stack;
}

int RPN::get_priority(char char_operator) {
    int priority = 0;
    switch (char_operator) {
        case '+':
        case '-':
            priority = 1;
            break;
        case '*':
        case '/':
            priority = 2;
            break;
        default:
            priority = 0;
    }
    return priority;
}
