/*Енамы, добавлять команды и менять значения здесь*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <assert.h>

#define N 10               //размер строки
#define amount 6           //кол-во известных функций

struct Cmds{
    int num;            
    const char *name;
    int argc;           //есть аргумент?
};

enum comands{
	cmd_PUSH = 1,
	cmd_POP = 2,
	cmd_ADD = 3,                    
	cmd_SUB = 4,
	cmd_MUL = 5,
	cmd_DIV = 6             //добавлять команды сюда !!!!!!!!
};

const struct Cmds Mass[] = 
{
	{cmd_PUSH, "push",1},
	{cmd_POP, "pop",0},
	{cmd_ADD, "add",0},
	{cmd_SUB, "sub",0},
	{cmd_MUL, "mul",0},
	{cmd_DIV, "div",0}            //и сюда           !!!!!!!!!
};
