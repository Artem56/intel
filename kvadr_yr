/*Квадратное уравнение
Артем Соломатин
01.10
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>


int error(char str[10]);

double tr(double tmp);
 
double yr(double a, double b, double c, double *x1, double *x2);

int main(){  
	double x1, x2;  //корни
	double a, b, c; //коэффициенты
	printf("a= ");
	a = tr(a);
	printf("b= ");
	b = tr(b);
	printf("c= ");
	c = tr(c);
	assert(a<5000 && b<5000 && c<5000);//проверка размеров коэффициентов
	int n = yr(a, b, c, &x1, &x2);
	if (n == 0){
		printf("Действительных корней нет");
	}
	if(n == 1){
		printf("\n Корень=%f",x1);
	}
	if(n == 2){
		printf("\n Первый корень= %f \n Второй корень= %f", x1, x2);
	}
	if(n == 3){
		printf("Коней бесконечное множество");
	} 
	if(n == 4){
		printf("\n Корень=%f",x1);
	}	
	return 0;
}
/****************************************************************/
int error(char str[10]){   /*проверяем каждый элемент*/
	int i = 0;
	int err, pnt;
	while(str[i] != '\0'){
		if(str[i] > '9' || str[i] < '0' && str[i] != '.' && str[i] !='-' && str[i] !='+'){
                err = 1;
                assert (err==0);
            }
            if (str[i]=='.'){
                pnt++;
                assert (pnt<=1);
            }
            i++;
            assert (str[i] !='+'&& str[i] !='-');
        }
        return err;
	}
/***************************************************************/	
double tr(double tmp){   /*считываем и проверяем массив*/
	char str[10];
	scanf("%s", str);
	if(error(str) != 1){   /*Нет ли ошибки в вводе*/
        tmp = atof( str ); /*tmp хранит строку, преобразованную в число*/
    }else
        printf("Неверный ввод");

    return tmp;
}
/***************************************************************/
double yr(double a, double b, double c, double *x1, double *x2){ /*квадратное уравнение с численными коэффициентами*/
	int n;
	int d = b*b - 4*a*c;
	if (a == 0 && c != 0){
		*x1 = (-b/c);
		*x2 = *x1;
		n = 4;
	}
	if (a == 0 && b == 0 && c == 0){
		n = 3;
	}
    if (d > 0 && a !=0){
        *x1 = (-b - sqrt(d)) / (2*a);
        *x2 = (-b + sqrt(d)) / (2*a);
        n = 2;
    }if(d == 0 && a !=0){
        *x1 = (-b / (2 * a));
        *x2 = *x1;
         n = 1;
    }if(d<0 && a != 0){
         n = 0;
    }
else{
	*x1 = (-b / c);
}
    return n;
}
	
	
