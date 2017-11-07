#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
int a[3][3];
int b[3][3];
int c[3][3];
int sum;

struct v
{
	int i;
	int j;
};

void *result(void *arg){
	struct v *info = arg;
	int p;
	sum = 0;
	for(p=0; p<3; p++){
		sum+=a[info->i][p]*b[p][info->j];
	}
	return(&sum);
}

int main(){

	int i, j, k;
	pthread_t tid;
	void *status = NULL;
	struct v *info = malloc(sizeof(struct v));

	printf("Enter matrix 1:\n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("Enter element at [%d][%d] >> ", i+1, j+1 );
			scanf("%d", &a[i][j]);
		}
	}

	printf("Enter matrix 2:\n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("Enter element at [%d][%d] >> ", i+1, j+1 );
			scanf("%d", &b[i][j]);
		}
	}

	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			info->i = i;
			info->j = j;

			pthread_create(&tid, NULL, result, info);
			pthread_join(tid, &status);
			k = *((int *)status);
			c[info->i][info->j]=k;

		}
	}

	printf("result is\n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%d\t", c[i][j] );
		}
		printf("\n");
	}
}