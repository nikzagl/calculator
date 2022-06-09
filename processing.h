//
// Created by home on 04.06.22.
//
#include<string>
#include<math.h>
#include <sstream>
#include<iostream>
#include "calc_node.h"
std::string prepare_expression(std::string expr);
node* make_polish_notation(std::string expr);
float calculate(node* queue);
