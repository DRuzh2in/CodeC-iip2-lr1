#include <stdio.h>
#include <climits>
#include <cstdlib>

int arrLimit();
void genRandArr(int **A, int*n);
void printAll(int **A, int*n, bool inOut);
void sort(int **A, int **B, int *n);
int minElement(int ***A, int **n);

int main() {

    int n = arrLimit();                         //запрашиваю количество элементов
    int *Arr = (int*) malloc (n * sizeof(int));
    int *Brr = (int*) malloc (n * sizeof(int));
    genRandArr(&Arr, &n);                       //заполняю массив случайными числами
    printAll(&Arr, &n, 1);                      //вывожу на экран массив
    sort(&Arr, &Brr, &n);                       //сортирую массив
    printAll(&Brr, &n, 0);                      //вывожу на экран массив
    free (Arr);
    free (Brr);

}

int arrLimit()
{
    int n;
    int *N = &n;                                //функция возвращает указатель
    printf("Введите количество элементов в массиве, N = ");
    scanf("%d", N);
    return *N;
}

void genRandArr(int **A, int*n)
{
    srand(0);
    for(int i=0; i<*n; i++)
        *((*A)+i) = rand();
}

void printAll(int **A, int*n, bool inOut)
{
    if (inOut == 1)
        printf("\nInput array:\nint Arr[%d] =", *n);
    else
        printf("\nOutput array:\nint Brr[%d] =", *n);
    for (int i = 0; i<*n; i++)
        printf(" %d", *((*A)+i));
    printf("\n\n");
}


void sort(int **A, int **B, int *n)
{
    for (int i = 0; i < *n; i++)
    {
        int min = minElement(*A, &n);;
        *((*B)+i) = *((*A)+min);
        *((*A)+min) = INT_MAX;
    }
}

int minElement(int *A, int **n)
{
    int min = 0;
    for (int j = 1; j < **n; j++)
        if(*((A)+min) > *((A)+j))
            min = j;
    int *p = &min;                                //функция возвращает указатель
    return *p;
}

