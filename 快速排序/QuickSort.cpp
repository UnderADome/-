#include <stdio.h>
#include <stdlib.h>

void Quick_Sort(int *, int, int);
int findPoss(int *, int , int);

int main(void)
{
    int num;
    printf("�����������Ԫ�صĸ�����");
    scanf("%d", &num);

    int i;
    int *arr = (int *)malloc(num*sizeof(int));
    printf("������������%d��Ԫ�أ�����Ϊ������", num);
    for (i=0; i<num; i++)
        scanf("%d", arr+i);
    
    printf("����������˳��");
    Quick_Sort(arr, 0, num-1);
    for (i=0; i<num; i++)
        printf("%d", arr[i]);
    printf("\n");

    free(arr);
    arr = NULL;
    system("pause");

    return 0;
}