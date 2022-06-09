#pragma once
#include <string>
#include<iostream>
struct node
{
    node* next;
    std::string value;
};
struct numnode
{
    numnode * next;
    float value;
};
node * add_first(node * root, std::string value);
node * add_last(node* root, std::string value);
std::string pop(node*& root);
void change_place (node*& root_1,node*& root_2);
void print_all(node * root);
void print_nums(numnode * root);
numnode * add_number(numnode* root,float value);
float pop_number(numnode*& root);
std::string replace_all(std::string str,std::string A,std::string B);
void replace_tokens(node*& queue, std::string A,std::string B);
