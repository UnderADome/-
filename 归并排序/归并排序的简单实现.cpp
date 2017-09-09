// #include <stdio.h>
//  void MSort(int A[], int TmpArray[], int Left, int Right)
//  {
//      int Center;

//      if(Left < Right)
//      {
//          Center = (Left+Right)/2;
//          MSort(A, TmpArray, Left, Center);
//          MSort(A, TmpArray, Center+1, Right);
//          Merge(A, TmpArray, Left, Center+1, Right);
//      }
//  }

//  void MergeSort(int A[], int N)
//  {
//      int *TmpArray;
//      TmpArray = malloc(N*sizeof(int));

//      if (TmpArray != NULL)
//      {
//          MSort(A, TmpArray, 0, N-1);
//          free(TmpArray);
//      }
//      else
//         printf("No space for tmp array!");
//  }

//  /*
//  Lpos = start of left half
//  Rpos = start of right half
//  */
//  void Merge(int A[], int TmpArray[], int Lpos, Int Rpos, int RightEnd)
//  {
//      int i, LeftEnd, NumElements, TmpPos;

//      LeftEnd = Rpos - 1;
//      TmpPos = Lpos;
//      NumElements = RightEnd - Lpos + 1;

//      //main loop
//      while (Lpos <= LeftEnd && Rpos <= RightEnd)
//         if (A[Lpos] <= A[Rpos])
//             TmpArray[TmpPos++] = A[Lpos++];
//         else
//             TmpArray[TmpPos++] = A[Rpos++];
    
//     while(Lpos <= LeftEnd) /*Copy rest of first half*/
//         TmpArray[TmpPos++] = A[Lpos++];
    
//     while(Rpos <= RightEnd) /*Copy rest of second half*/
//         TmpArray[TmpPos++] = A[Rpos++];

//     /*Copy TmpArray back*/
//     for (i=0; i<NumElements; i++, RightEnd--)
//         A[RightEnd] = TmpArray[RightEnd];

//  }


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/*
@method     ���и���������ϲ�Ϊ�µ���������

@process    �������arr[start...mid]�������arr[mid+1...end]�鲢Ϊ�����brr[0...end-start+1]��
�����ٽ�brr[0...end-start+1]���Ƶ�arr[start...end]��ʹarr[start...end]����
*/
void Merge(int *arr, int *brr, int start, int mid, int end)
{
    int i = start;  int j = mid+1;  int k = 0;

    //�Ƚ��������������е�Ԫ�أ�����С��Ԫ�ز��뵽brr��
    while(i<=mid && j<=end)
    {
        //�ֱ������������ĵ�һ��Ԫ�ؿ�ʼͬʱ����ƽ�
        if (arr[i] <= arr[j])
            brr[k++] = arr[i++];
        else
            brr[k++] = arr[j++];
    }

    //�˴�while����֮�󣬲�û������������ȫ����
    //��Ϊarr��brr�����ʣ���һ�Σ�û����while�н��бȽϣ���Ҫֱ�Ӳ��뵽brr��


    //��arr������ʣ���Ԫ�ظ��Ƶ�brr��
    //���������ֻ����ִ������һ��
    while (i <= mid)
        brr[k++] = arr[i++];
    while (j <= end)
        brr[k++] = arr[j++];
    
    //��brr�е�Ԫ�ظ��Ƶ�arr�У�ʹarr[start...end]����
    for (i=0; i<k; i++)
        arr[i+start] = brr[i];
}

/*
@method     �˷���ʵ�ʾ��ǵݹ����MSort���������

@process    ����brr�����arr[start...end]�ڵ�Ԫ�ؽ��й鲢����
�鲢������˳��Ϊ��С����
*/
void MSort(int *arr, int *brr, int start, int end)
{//�ݹ��������ȽϵĹ���
    if (start < end)
    {
        int mid = (start+end)/2;
        
        //��ߵݹ�����
        MSort(arr, brr, start, mid);
        //�ұߵݹ�����
        MSort(arr, brr, mid+1, end);
        //���Ѿ��ź�����������������ٽ�������
        Merge(arr, brr, start, mid, end);
    }
}

/*
���������㷨��װ����
���������ô˷������ȫ�����������
*/
void Merge_Sort(int *arr, int len)
{
    int *brr = (int *)malloc(len*sizeof(int));
    MSort(arr, brr, 0, len-1);
    free(brr);
    brr = NULL;
}

int main(void)
{
    int num;
    printf("�����������Ԫ�صĸ�����");
    scanf("%d", &num);

    int i;
    int *arr = (int *)malloc(num*sizeof(int));
    printf("������������%d��Ԫ�أ�����Ϊ��������", num);
    for (i=0;i<num;i++)
        scanf("%d", arr+i);

    printf("�鲢������˳��");
    Merge_Sort(arr, num);
    for (i=0; i<num; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    arr = NULL;

    system("pause");

    return 0;
}