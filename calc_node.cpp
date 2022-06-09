//
// Created by home on 02.06.22.
//

#include "calc_node.h"
#include<string>
node * add_first(node * root, std::string value)
{
    node * result=new node();
    result->value=value;
    result->next=root;
    return result;
}
numnode * add_number(numnode * root, float value) {
    numnode *result = new numnode();
    result->value = value;
    result->next = root;
    return result;
}
float pop_number(numnode *& root)
{
    float result=root->value;
    root=root->next;
    return result;
}
node * add_last(node* root, std::string value)
{
    if (!root)
    {
        node * result=new node();
        result->value=value;
        return result;
    }
    else {
        root->next = add_last(root->next, value);
        return root;
    }
}
std::string pop(node*& root)
{
    std::string result=root->value;
    root=root->next;
    return result;
}
void change_place (node*& root_1,node*& root_2)
{
    std::string elem=pop(root_1);
    root_2=add_last(root_2,elem);
}
void print_all(node * root)
{
    if(root){
        std::cout<<root->value<<" ";
        print_all(root->next);
    }
}
void print_nums(numnode* root)
{
    if(root){
        std::cout<<root->value<<" ";
        print_nums(root->next);
    }
}
std::string replace_all(std::string str,std::string A,std::string B) {
    int pos=0;
    while (true)
    {
        pos=str.find(A,pos);
        if ((int)pos==-1)
            break;
        str.replace(pos,A.length(),B);
        pos+=B.length();
    }
    return str;
}
void replace_tokens(node*& queue, std::string A,std::string B)
{
    node* temp=queue;
    while(temp)
    {
        if (temp->value==A)
            temp->value=B;
        else if(temp->value==("#"+A))
            temp->value="#"+B;
        temp=temp->next;
    }
}