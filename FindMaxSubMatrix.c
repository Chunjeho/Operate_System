#include <stdio.h>
#include <stdlib.h>

int main(){	
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	int m = 0;
	int n = 0;
	int o = 0;
	int p = 0;
	int totalNum = 0;
	int max = 0;
	int maxIndex = 0;
	int sum = 0;
	int size = 5;
	int* startEndTable = (int*)malloc(sizeof(int)*(size*(size-1)/2+size)*2);
	int* sumTable = (int*)malloc(sizeof(int)*(size*(size-1)/2+size)*(size*(size-1)/2+size)*3);
	int table[5][5] = {{-5, -6, 3, 1, 0},
						{9, 7, 8, 3, 7},
						{-6, -2, -1, 2, -4},
						{-7, 5, 5, 2, -6},
						{3, 2, 9, -5, 1}};
	
	for(i=0;i<5;i++){
		for(j=i;j<5;j++){
//			printf("k: %d, l: %d\n",k,l);
			startEndTable[2*k+l] = i;
			l = 1;
			startEndTable[2*k+l] = j;
			l = 0;
			k += 1;
		}
	}
	
	for(k=0;k<size*(size-1)/2+size;k++){
		for(m=0;m<size*(size-1)/2+size;m++){
			sum = 0;
			l = 0;
			n = 0;
			p = 0;
			totalNum += 1;
			for(i=startEndTable[2*k+l];i<=startEndTable[2*k+l+1];i++){
				for(j=startEndTable[2*m+n];j<=startEndTable[2*m+n+1];j++){
					sum += table[i][j];
				}
			}
//			printf("(%d,%d)->", startEndTable[2*k+l], startEndTable[2*m+n]);
//			printf("(%d,%d); ", startEndTable[2*k+l+1], startEndTable[2*m+n+1]);
			sumTable[o*3+p] = sum;
			sumTable[o*3+p+1] = 2*k+l;
			sumTable[o*3+p+2] = 2*m+n;
			o += 1;
//			printf("sum: %d\n", sum);
		}
	}
	
	max = sumTable[0];
	for(o=0;o<(size*(size-1)/2+size)*(size*(size-1)/2+size);o++){
		
		if(sumTable[3*o] >= max){
			max = sumTable[3*o];
			maxIndex = o;
		}
//		printf("sum in sumTable: %d\n", sumTable[3*o]);
	}
	
//	printf("Total: %d\n", totalNum);
	printf("Max: (%d,%d)->(%d,%d); %d", startEndTable[sumTable[maxIndex*3+1]],startEndTable[sumTable[maxIndex*3+2]],startEndTable[sumTable[maxIndex*3+1]+1],startEndTable[sumTable[maxIndex*3+2]+1],max);
	

		
	return 0;
}
