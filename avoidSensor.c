#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int Sensor[][10] = {
		{0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
		{1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};
	
	/*int Sensor[][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 1, 1, 0, 1, 1, 1, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
		{1, 1, 1, 1, 0, 1, 0, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};*/
	
	int _Sensor[10][10];
	
	int *S = NULL;
	int *F = NULL;
	int *N = NULL;
	
	int _start = 0;
	int _finish = 0;
	
	int i = 0;
	int j = 0;
	int k = 0;
	int temp = 0;
	int min = 0;
	
	
	int _boolFin = 0;
	
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(Sensor[i][j] == 0 && (i == 0 && j == 0)){
				Sensor[i][j+1] = -1;
				Sensor[i+1][j] = -1;
				Sensor[i+1][j+1] = -1;
			}
			
			else if(Sensor[i][j] == 0 && (i == 9 && j == 0)){
				Sensor[i][j-1] = -1;
				Sensor[i-1][j] = -1;
				Sensor[i-1][j-1] = -1;
			}
			
			else if(Sensor[i][j] == 0 && (i == 0 && j == 9)){
				Sensor[i][j+1] = -1;
				Sensor[i-1][j] = -1;
				Sensor[i-1][j+1] = -1;
				
			}
			
			else if(Sensor[i][j] == 0 && (i == 9 && j == 9)){
				Sensor[i][j-1] = -1;
				Sensor[i-1][j] = -1;
				Sensor[i-1][j-1] = -1;
			}
			
			else if(Sensor[i][j] == 0 && ((i == 0 && j != 0) || (i == 0 && j != 9))){
				Sensor[i][j-1] = -1;
				Sensor[i][j+1] = -1;
				Sensor[i+1][j] = -1;
				Sensor[i+1][j-1] = -1;
				Sensor[i+1][j+1] = -1;
			}
			
			else if(Sensor[i][j] == 0 && ((i == 9 && j != 0) || (i == 9 && j != 9))){
				Sensor[i][j-1] = -1;
				Sensor[i][j+1] = -1;
				Sensor[i-1][j] = -1;
				Sensor[i-1][j-1] = -1;
				Sensor[i-1][j+1] = -1;
			}
			
			else if(Sensor[i][j] == 0 && ((i != 0 && j == 0) || (i != 9 && j == 0))){
				Sensor[i-1][j] = -1;
				Sensor[i+1][j] = -1;
				Sensor[i][j+1] = -1;
				Sensor[i-1][j+1] = -1;
				Sensor[i+1][j+1] = -1;
			}
			
			else if(Sensor[i][j] == 0 && ((i != 0 && j == 9) || (i != 9 && j == 9))){
				Sensor[i-1][j] = -1;
				Sensor[i+1][j] = -1;
				Sensor[i][j-1] = -1;
				Sensor[i-1][j-1] = -1;
				Sensor[i+1][j-1] = -1;
			}
			
			else if(Sensor[i][j] == 0 && i != 0 && i != 9 && j != 0 && j != 9){
				Sensor[i][j+1] = -1;
				Sensor[i][j-1] = -1;
				Sensor[i+1][j] = -1;
				Sensor[i-1][j] = -1;
				Sensor[i+1][j+1] = -1;
				Sensor[i-1][j-1] = -1;
				Sensor[i+1][j-1] = -1;
				Sensor[i-1][j+1] = -1;
			}
		}
	}

	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(Sensor[i][j] == -1){
				Sensor[i][j] = 0;
			}
		}
	}
	
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			_Sensor[i][j] = Sensor[i][j];
		}
	}
	
	for(i=0;i<=9;i++){
		if(Sensor[i][0] == 1){
			_start += 1;
		}
		
		if(Sensor[i][9] == 1){
			_finish+= 1;
		}
	}
	
	S = malloc(sizeof(int) * _start);
	F = malloc(sizeof(int) * _finish);
	
	j = 0;
	k = 0;
	
	for(i=0;i<=9;i++){
		if(Sensor[i][0] == 1){
			S[j] = i;
			j += 1;
		}
		
		if(Sensor[i][9] == 1){
			F[k] = i;
			k += 1;
		}
	}
	
	for(k=0;k<_start;k++){
		_boolFin = 0;
		
		for(i=0;i<10;i++){
			for(j=0;j<10;j++){
				Sensor[i][j] = _Sensor[i][j];
			}
		}
		
		/* Cycle */
		for(j=0;j<10;j++){
			if(Sensor[S[k]][j] == 1){
				Sensor[S[k]][j] = j+1;
				temp = j;
			}
			else if(Sensor[S[k]][j] == 0){
				break;
			}
		}
	
		for(j=0;j<=temp;j++){
			for(i=S[k];i>=1;i--){
				if(Sensor[i-1][j] == 1){
					Sensor[i-1][j] = Sensor[i][j]+1;
					//printf("%d %d is 1\n", i-1, j);
				}
				else if(Sensor[i-1][j] == 0){
					break;
				}
			}
	
			for(i=S[k];i<=8;i++){
				if(Sensor[i+1][j] == 1){
					Sensor[i+1][j] = Sensor[i][j]+1;
				}
				else if(Sensor[i+1][j] == 0){
					break;
				}
			}
		}
		
		/* While start */
		
		while(_boolFin <= _finish){
			
			for(i=0;i<=9;i++){
				for(j=0;j<=8;j++){
					if(Sensor[i][j+1] == 1 && (Sensor[i][j] != 1 && Sensor[i][j] != 0 && j != 0)){
						Sensor[i][j+1] = Sensor[i][j] + 1;
					}
				}
			}
		
			for(i=0;i<=8;i++){
				for(j=0;j<=9;j++){
					if(Sensor[i+1][j] == 1 && (Sensor[i][j] != 1 && Sensor[i][j] != 0 && j != 0)){
						Sensor[i+1][j] = Sensor[i][j] + 1;
					}
				}
			}
			
			for(i=9;i>=1;i--){
				for(j=9;j>=0;j--){
					if(Sensor[i-1][j] == 1 && (Sensor[i][j] != 1 && Sensor[i][j] != 0 && j != 0)){
						Sensor[i-1][j] = Sensor[i][j] + 1;
					}
				}
			}
			
			for(i=9;i>=0;i--){
				for(j=9;j>=1;j--){
					if(Sensor[i][j-1] == 1 && (Sensor[i][j] != 1 && Sensor[i][j] != 0 && j != 1)){
						Sensor[i][j-1] = Sensor[i][j] + 1;
					}
				}
			}
			
			for(i=0;i<_finish;i++){
				if(Sensor[F[i]][9] != 1){
					_boolFin += 1;
				}
			}
		}
		/* While End */
		/* End */
		
		/*printf("\n _Sensor\n");
		for(i=0;i<10;i++){
			for(j=0;j<10;j++){
				printf(" %d ", _Sensor[i][j]);
			}
			printf("\n");
		}*/
		
		printf("\n #%d \n", S[k]);
		for(i=0;i<10;i++){
			for(j=0;j<10;j++){
				printf(" %d ", Sensor[i][j]);
			}
			printf("\n");
		}
		
		for(i=0;i<10;i++){
			if(Sensor[i][9] != 0 && Sensor[i][9] != 1 && k == 0 && j >= 0){
				min = Sensor[i][9];
				j = -1;
			}
			if(Sensor[i][9] != 0 && Sensor[i][9] != 1 && i != 0){
				if(Sensor[i][9] <= min){
					min = Sensor[i][9];
				}
				else{
					continue;
				}
			}
		}
	}
	
	free(S);
	
	printf("\n Shortest distance: %d\n ", min-1);
	
	return 0;
}
