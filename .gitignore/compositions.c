/*Порождение всех разбиений для композиций.   Generation of all partitions for compositions*/
#include <stdio.h>
#include <string.h>
int  permute (int  * a) {
	int k = 0;
	char  argv[1][50];
	for (k=0; a[k] != 0; k++)
	{
	argv[1][k]	=  a[k] + '0';
	}
	argv[1][k]='\0';

	int i = 0;
    int j = 0;
    int x = 0;   //Хранит длину строки. Var to let know length of a string
    int y = 0;   //Считаем число перестановок. It counts number.
    char c;      //Для обмена. Buffer
    char  ch[33]; //Хранит перевернутую копию аргумента. Reversed copy of an argument


/*It calculates an array's length. Вычислим длину строки*/

    for (x; argv[1][x]; x++);

/*Buble sort an array. Упорядочим алфавит*/

    for(i=0; i < x; i++) {
        for(j = x-1; j > i; j-- ) {
            if (argv[1][j-1] > argv[1][j]) {
                c=argv[1][j-1];
                argv[1][j-1]=argv[1][j];
                argv[1][j]=c;
            }
        }
    }

      /*Копируем аргумент в переменную ch
       Copy argument to ch variable*/
      strcpy (ch, argv[1]);

      i = x;
      j = 0;
	/*Перевернем переменную ch - нужна для остановки алгоритма.
	 Reverse ch. It's needed to stop the algorithm*/
		while( i > j ) {
         i--;
         c=ch[j];
         ch[j]=ch[i];
         ch[i]=c;
         j++;
        }


/*Main part: here we permute. Порождаем перестановки*/

    while (1) {

        printf("%s\n", argv[1]);
		if (strcmp (argv[1], ch) == 0)  break;
        i=x-2;
        /*Here we search next. Ищем новую перестановку*/
        while(argv[1][i] >= argv[1][i+1] ) i--;
        j=x-1;
        while(argv[1][j] <= argv[1][i] ) j--;

        /*Change. Обмен*/
        c=argv[1][j];
        argv[1][j]=argv[1][i];
        argv[1][i]=c;
        i++;
        /*Tail reverse. Оборачиваем хвост*/
        for (j = x-1; j > i; i++, j--) {
            c = argv[1][i];
            argv[1][i] = argv[1][j];
            argv[1][j] = c;
        }

    }

}

int main (int argc, char *argv[]) {

    /*Массив целых. This is an array of integers*/
    int a[10]= {1,	1,1,1,1,1,1,1,1,0};

    int i = 0;
    int j = 0;

    int sum = 0;
    int first_elem = 0;
    int min_elem = 0;

    int n = 0; /*Initial number of objects in array A.
    Число объектов (первоначально) в массиве А*/
    for (n; a[n] != 0; n++);
    /*Number of objects in array A (at the moment).
    Число объектов (в текущий момент) в массиве А*/
    int x = 0;

    while (1)
    {
        /*Печать и выход. Print end exit*/
        //for (j=0; a[j] != 0; j++) printf("%d", a[j]);
        //printf("\n");
       permute(a);
        if (a[0] == n) break;

        /*Элемент в нулевом индексе нашего динамического
        массива на текущий момент.
        First element of our dynamic array*/
        first_elem = a[0];

        i = 0;

        for (x=0; a[x] != 0; x++);
        while (i != x -1)
        {
            /*Найдем элемент меньше первого. Here we search min. element*/
            if (a[i] < first_elem)
            {
                first_elem = a[i];
                min_elem = i;
            }

            i++;
        }
        /*Here we count current numbers of elements in A*/
        /*Здесь мы подсчитываем текущие числа элементов в A*/


        /*Перенос элемента  "1". Here we transfer "1". */
        a[min_elem]+= 1;
        a[x - 1]-= 1;
        /*Here we cut A. Обрежем А*/
        a[min_elem+1] = 0;


        /*Добавим в массив единицы заново.
        Here we add 1 (fill)  to the array*/
        for (j = min_elem+1; j != n; j++) a[j] = 1;
        a[j-1] = 0;

        /*Найдем сумму  элементов и обрежем массив А.
         * We count the sum of elements and cut the array A*/
        sum = 0;
        for (j = 0; a[j] != 0; j++)
        {
            sum = sum + a[j];
            if (sum == n) a[j+1] = 0;
        }

        /*Обнулим переменную. Unset min_elem*/
        min_elem = 0;

    }
}



