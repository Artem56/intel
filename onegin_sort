/*Сортировка Онегина
Артем Соломатин
*/

void gnom_sort(char** mas, int n);

int main(){
    char onegin[200][50] = {};   //двумерный массив из строк текста
    char enter;                     //будет хранить считанный enter
    char *ukz[200] = {};       //массив указателей на первый элемент
    int i, n;                  //счетчики и кол-во строк в тексте
    
    printf("Введите количество строк в тексте :\n");
    scanf("%d", &n);        		
    scanf("%c", &enter);      			 
    printf ("Введите текст\n");
    
    for (i = 0; i < n; i++){
		int j;
        for (j = 0; (onegin[i][j] = getchar()) != '\n';j++ ){ //заполняем массив строками    
            if (j == 0) 
            ukz[i] = &onegin[i][j];    		  //заполняем массив указателей адресами первых элементов строк
        }
    }
    
    gnom_sort(ukz, n); 							
    printf("\n");  
    for (i = 0; i < n; i++)
		printf("%s", ukz[i]);               
    return 0;
}

void gnom_sort (char** mas, int n){      
int i = 1;
char *tmp;	  	
while (i<n){
		if (i == 0 || *mas[i-1] <= *mas[i]){
		i++;
		}else {			
			tmp = mas[i];
			mas[i] = mas[i-1];
			mas[i-1]=tmp;
			i--;
		}
	}
}	
