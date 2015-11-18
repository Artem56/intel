/* Гномья сортировка
Соломатин Артем, 515гр.

29.09
*/


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

int main(){
	
	int i, j;      //счетчики
	int tmp;       //изменяемая переменная, для хранения данных
	int n;         //величина массива
	printf("введите длину массива n = ");
	scanf("%d", &n);
	assert(n<1000);
	int mas[n];    //массив из n элементов
	int* p = mas;
	p = malloc(n*sizeof(int*));//выделяем требуемое место массиву  
	
	      
	for (i=0;i<n;i++){
		printf("mas[%d] = ", i);
		scanf("%d", &mas[i]);
		
		assert(mas[i]<10000);
	}
	i = 0;
 
//сортируем числа массива по возрастанию
	while (i<n){
		if (i == 0 || mas[i-1] <= mas[i]){
		i++;
		}else {
			tmp = mas[i];
			mas[i] = mas[i-1];
			mas[i-1]=tmp;}
			j = i-1;
			
			while (j>0){
				if (mas[j] == mas[j-1]){
				j--;
			}
			if(mas[j]>mas[j-1]){
				break;
				}
				if(mas[j]<mas[j-1]){
					int a;
				a = mas[j];
				mas[j] = mas[j-1];
				mas[j-1] = a;
				j=j-1;
			}
			}
		}	
i = 0;


//выводим отсортированный массив
for(i=0;i<n;i++){
printf("%d ", mas[i]);
}
free(p);
return 0;
}
