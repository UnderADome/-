#include <stdio.h>
#include <stdlib.h> 

//#ifdef _TREE_H 
struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;

SearchTree MakeEmpty(SearchTree* T);
Position Find(int x, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(int x, SearchTree* T);
SearchTree Delete(int x, SearchTree T);
int Retrieve(Position P);


#define OK 1;
//#endif /*_TREE_H*/
struct TreeNode{
	int Element;
	SearchTree Left;
	SearchTree Right
};


SearchTree MakeEmpty(SearchTree* T){
	printf("ready to clean\n");
	if (*T == NULL){
		printf("Ϊ�գ�����Ҫfree\n");
	}	
	if (*T != NULL){
		MakeEmpty( &((*T)->Left) );
		printf ("����������\n");
		MakeEmpty( &((*T)->Right) );
		printf("����������\n");
		free(T);
		printf("���ͷ�\n");
	}
	printf("all clear!\n");
	return NULL;
}

/*����*/
Position Find(int x, SearchTree T){
	if (T == NULL)
		return NULL;
		
	if (x < T->Element)
		return Find(x, T->Left);
	else if(x > T->Element)
		return Find(x, T->Right);
	else 
		return T;
}

/*������Сֵ*/ 
Position FindMin(SearchTree T){
	if (T == NULL)
		return NULL;
	else if (T->Left == NULL)
		return T;
	else 
		return FindMin(T->Left);
}

/*�������ֵ, �ǵݹ�*/ 
Position FindMax(SearchTree T){
	if (T != NULL)
		while(T->Right != NULL)
			T = T->Right;
	return T;
}

/*����*/
SearchTree Insert(int x, SearchTree* T){
	printf ("ִ��insert\n");
	if (*T == NULL){
		*T = malloc(sizeof(struct TreeNode));
		printf ("����ռ�\n");
		if (*T == NULL)
			printf ("Out of space\n");
		else{
			((*T)->Element) = x;
			((*T)->Left) = ((*T)->Right) = NULL;
		} 
	}
	else if (x < (*T)->Element)
		(*T)->Left = Insert(x, &((*T)->Left));
	else if (x > (*T)->Element)
		(*T)->Right = Insert(x, &((*T)->Right));
		
	return T;
}

int main(void){

	SearchTree T;
	printf("����������\n");
	MakeEmpty(T);
	printf("clear finished!\n");
	
	int n = 100;//�������ֵ�����
	int x;//��¼���������
	int i;//��¼ѭ���Ĵ��� 
	scanf ("%d", &n);
	for (i=1;i<=n;i++){
		scanf("%d", &x);
		Insert(x, T);
		printf ("�����%d������x[%d] = %d\n", i, i, x);
	} 
	
	return 0;
}