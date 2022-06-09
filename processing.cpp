//
// Created by home on 04.06.22.
//

#include "processing.h"
std::string bin_ops[8]={"+","-","*","/","^","(",")","(  - "};
std::string rep_bin_ops[8]={" + "," - "," * "," / "," ^ "," ( "," ) ","( # "};
int priority(char symbol)
{
    switch (symbol)
    {
        case '+':
            return 0;
        case '-':
            return 0;
        case '*':
            return 1;
        case '/':
            return 1;
        case '^':
            return 3;
        case '#':
            return 2;
        default:
            return -1;
    }
}
std::string prepare_expression(std::string expr) {
if(expr[0]=='-') {
    expr.replace(0, 1, "#");
}
    for (int i = 0; i <= 7; i++)
    {
        expr=replace_all(expr,bin_ops[i],rep_bin_ops[i]);
    }
    return expr;
}
node*  make_polish_notation(std::string expr)
{
    node * stack=nullptr;
    node * queue=nullptr;
    expr=prepare_expression(expr);
    std::stringstream buffer;
    std::string elem,head;
    buffer<<expr;
    while(buffer>>elem)
    {
        if(elem=="(")
            stack=add_first(stack,elem);
        else if  (elem==")") {
            while (stack->value != "(")
            {
                change_place(stack,queue);
            }
            if(stack)
                pop(stack);
        }
        else if ((priority(elem[0])==-1)||(elem.length()>=2))
            queue=add_last(queue,elem);
        else {
            while ((stack)&&(priority((stack->value)[0])>=priority(elem[0])))
                change_place(stack,queue);
            stack=add_first(stack,elem);
        }
    }
    while(stack)
    {
        if(stack->value!="(")
            queue = add_last(queue, pop(stack));
        else
            pop(stack);
    }
    return queue;
}

float calculate(node * queue)
{
    float a,b;
    numnode * stack=nullptr;
    while(queue) {
        if ((queue->value.length() >= 2) || priority(queue->value[0]) == -1)
            stack = add_number(stack, std::stof(queue->value));
        else if (queue->value[0] == '#')
        {
             stack->value*=-1;
        }
        else{
            a = pop_number(stack);
            b = pop_number(stack);
            switch (queue->value[0]) {
                case '+':
                    stack = add_number(stack, a + b);
                    break;
                case '-':
                    stack = add_number(stack, b- a);
                    break;
                case '*':
                    stack = add_number(stack, a * b);
                    break;
                case '/':
                    stack=add_number(stack,b/a);
                    break;
                default:
                    stack = add_number(stack, pow(b, a));
                    break;
                }
            }
     queue=queue->next;
    }
    return stack->value;
        
}


