#define MAXSIZE 100
typedef int datatype;
typedef struct{
	datatype a[MAXSIZE];
	int size;
}sequence_list;

void init(sequence_list *slt){
	slt->size = 0;
}

void append(sequence_list *slt, datatype x){
	if (slt->size == MAXSIZE){
		printf("˳���������");
	}
	slt->a[slt->size] = x;
	slt->size = slt->size + 1;
}

void display(sequence_list slt){
	int i;
	if (!slt.size){
		printf ("\n˳����ǿյ�");
	}else{
		for (int i=0;i<slt.size;i++){
			printf("%5d", slt.a[i]);
		}
	}
}