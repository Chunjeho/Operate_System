#include <stdio.h>
#include <stdlib.h>

void SpiralMatrix(int *_input, int m, int n, int **_bowl){
	
	int _offset = 0;
	int i = 0;
	int j = 0;
	int _exc = _input[0];
	int _cont = 0;
	
	while(1){
		
		/*Step N Sta.*/
		
		for(i=0+_offset;i<n-_offset;i++){
		_bowl[0+_offset][i] = _input[_cont];
		printf("_bowl[%d][%d] : %d\n", _offset,i, _bowl[0+_offset][i]);
		_cont = (i == n-1-_offset) ? _cont : _cont+1;
		printf("_cont: %d\n", _cont);
		if(_bowl[0+_offset][i] == _input[m*n-1]){
			return;
		}
		}
	
		i = n-1-_offset;
	
		for(j=0+_offset;j<m-_offset;j++){
			_bowl[j][i] = _input[_cont];
			printf("_bowl[%d][%d] : %d\n", j, i, _bowl[j][i]);
			_cont = (j == m-1-_offset) ? _cont : _cont+1;
			printf("_cont: %d\n", _cont);
			if(_bowl[j][i] == _input[m*n-1]){
				return;
			}
		}
	
		j = m-1-_offset;
	
		for(i=n-1-_offset;i>=0+_offset;i--){
			_bowl[j][i] = _input[_cont];
			printf("_bowl[%d][%d] : %d\n", j, i, _bowl[j][i]);
			_cont = (i == 0+_offset) ? _cont : _cont+1;
			printf("_cont: %d\n", _cont);
			if(_bowl[j][i] == _input[m*n-1]){
				return;
			}
		}
	
		i = 0+_offset;
		
		for(j=m-1-_offset;j>=0+_offset;j--){
			_bowl[j][i] = _input[_cont];
			printf("_bowl[%d][%d] : %d\n", j, i, _bowl[j][i]);
			_cont = (j == 0+_offset) ? _cont : _cont+1;
			printf("_cont: %d\n", _cont);
			if(_bowl[_offset+1][_offset] == _input[m*n-1]){
				return;
			} // There is no more extra element(s) inside this cycle <=> last element in _input array is in _bowl[_offset+1][_offset]
		}
		_bowl[1+_offset][1+_offset] = _bowl[0+_offset][0+_offset];
		_bowl[0+_offset][0+_offset] = _exc;
		
		if(_bowl[1+_offset][1+_offset] == _input[m*n-1]){
			return; // This will operate in M x M matrix
		}
		
		_exc = _bowl[1+_offset][1+_offset];
		_offset += 1;
			/*Step N Fin.*/
	}
}

int main(){
	
	int _input[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};
	int m = 6;
	int n = 6;
	int i = 0;
	int j = 0;
	
	int** _bowl = malloc(sizeof(int*) * m);
	
	for(i=0;i<m;i++){
		_bowl[i] = malloc(sizeof(int)*n);
	}
	
	SpiralMatrix(_input, m, n, _bowl);
	
	printf("\n");
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf(" %d ", _bowl[i][j]);
			if(j == n-1){
				printf("\n");
			}
		}
	}
	
	for(i=0;i<m;i++){
		free(_bowl[i]);
	}
	
	free(_bowl);
	
	return 0;
}
