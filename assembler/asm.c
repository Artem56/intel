/*
 * Соломатин Артем
 * Асемблер
*/
#include "Cmd.asm"

#define DEFINE_CMD(k)\
		if(strncmp(cmd,Mass[k].name, 3) == 0){\
			fprintf(cpuf, "%d ", Mass[k].num);\
			if(Mass[k].argc == 1){\
			fscanf(mf,"%d", &arg);\
			fprintf(cpuf,"%d ", arg);\
		}\
	}
/**********************************************************************/
void clear(char*cmd);


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
