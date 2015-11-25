/*
 * Соломатин Артем
 * CPU
*/

#include "Cmd.asm"

#define NORMAL_SIZE 50 //стандартный размер, потом проверим, не превысило ли значение top значение size
#define DOP_SIZE 20                       

#define DO_PUSH {fscanf(mf, "%d", &arg);\
		push(stack, arg); a--;}
		
#define DO_POP pop(stack)
		
#define DO_ADD push(stack, pop(stack) + pop(stack))
		
#define DO_SUB push(stack, (-(pop(stack) - pop(stack))))
		
#define DO_MUL push(stack, pop(stack)*pop(stack))
		
#define DO_DIV push(stack, pop(stack)/pop(stack))
/**********************************************************************/		
typedef struct Stack_Info{
    int *data;           //указателя на данные
    int size;            //размер массива (максимальный)
    int top;             //числа элементов в массиве
}Stack_Info;
/**********************************************************************/
Stack_Info* CreateStack();
void ClearStack(Stack_Info **stack);
void Change_Size(Stack_Info *stack);
void push(Stack_Info *stack, int value);
int pop(Stack_Info *stack);

int main(){
    char c;
    int a = 0, cmd_num, arg;
	Stack_Info *stack = CreateStack();
	
	FILE *mf;
	mf = fopen ("my.asm","r");
	
	while(1){
		c = fgetc(mf);
		if(c == EOF)
			break;
		if(c == ' ')
			a++;
	}
	fclose(mf);
	mf = fopen ("my.asm","r");
	
	while(a){
		fscanf(mf, "%d", &cmd_num);
		if(cmd_num == cmd_PUSH) 
			DO_PUSH;
		if(cmd_num == cmd_POP)
			DO_POP;
		if(cmd_num == cmd_ADD)
			DO_ADD;
		if(cmd_num == cmd_SUB)
			DO_SUB;
		if(cmd_num == cmd_MUL)
			DO_MUL;
		if(cmd_num == cmd_DIV)
			DO_DIV;
		a--;
	}
	printf("%d ", pop(stack));
	ClearStack(&stack);
    return 0;
}

Stack_Info* CreateStack(){
    Stack_Info *myStack = NULL;
    myStack = malloc(sizeof(Stack_Info));
    assert(myStack != NULL);
    myStack->size = NORMAL_SIZE;
    myStack->data = malloc(myStack->size*sizeof(int));
    if (myStack->data == NULL){
        free(myStack);
        assert(0);
    }
    myStack->top = 0;
    return myStack;
}
 
void ClearStack(Stack_Info **stack){
   free((*stack)->data);
    free(*stack);
}

void Change_Size(Stack_Info *stack){//если значение превышено, то увеличиваем размер массива. 
    stack->size += DOP_SIZE;
    stack->data = realloc(stack->data,stack->size*sizeof(int));
    assert(stack->data != NULL);    //удалось выделить достаточно памяти?(на будущее) 
}


void push(Stack_Info *stack, int value){
    if (stack->top >= stack->size){    //вышли за предел массива?увеличим размер
        Change_Size(stack);            
    }
    stack->data[stack->top] = value;
    stack->top++;
}

int pop(Stack_Info *stack){
    assert(stack->top != 0);
    stack->top--;
    return stack->data[stack->top];
}
