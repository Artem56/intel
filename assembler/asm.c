/*
 * Соломатин Артем
 * Асемблер
 * */

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define DEFINE_CMD(k)\
		if(strncmp(cmd,Mass[k].name, 3) == 0){\
			fprintf(cpuf, "%d ", Mass[k].num);\
			if(Mass[k].argc == 1){\
			fscanf(mf,"%d", &arg);\
			fprintf(cpuf,"%d ", arg);\
		}\
	}
			
#define N 10               //размер строки
#define amount 6           //кол-во известных функций
/**********************************************************************/
enum comands{
	cmd_PUSH = 1,
	cmd_POP = 2,
	cmd_ADD = 3,                    
	cmd_SUB = 4,
	cmd_MUL = 5,
	cmd_DIV = 6             //добавлять команды сюда !!!!!!!!
};

void clear(char*cmd);

struct Cmds{
    int num;            
    const char *name;
    int argc;           //есть аргумент?
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
/**********************************************************************/
int main (){
	FILE *mf, *cpuf;
	mf = fopen ("cmd.asm","r"); //cчитваем команды из cmd.asm
	int a = 0, i, j;
	char c;
	char cmd[N] = {};
	int arg = 0;
	
	while(1){
	c = fgetc(mf);						//Подсчитываем количество строк в команде
		if(c == EOF)
			break;
		if((c == '\n') || (c == ' '))
			a++;                       //кол-во строк в команде		
	}
	
	fclose(mf);
	mf = fopen ("cmd.asm","r");
	cpuf = fopen ("my.asm","w");      //результат печатаем в my.asm
	
	while(a){
		i = 0;
		c = fgetc(mf);
		while(c != ' ' && c != '\n' && c != EOF){
			cmd[i] = c;
			i++;
			c = fgetc(mf);
		}
		for(j = 0; j < amount; j++)     //какую команду видим?
			DEFINE_CMD(j);
		a--;
		clear(cmd);
	}	
	return 0;
	fclose(mf);
	fclose(cpuf);
}

void clear(char*cmd){
	int i;
	for(i = 0; i < N; i++){
		cmd[i] = '\0';
	}
}
