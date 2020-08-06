#include <stdio.h>
#include <stdlib.h>
int main(){
	
	int _num = 0;
	int *ARR = NULL;
	int _size = 0;
	int _q = 0;
	int _r = 0;
	int i = 0;
	
	char _alphabet[] = {'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y'};
	scanf_s("%d", &_num);
	
	_q = _num / 26;
	
	while(1){
		if(_q == 0){
			_size += 1;
			break;
		}
		else if(_q > 0 && _q <= 26){
			_size += 2;
			break;
		}
		else{
			_size += 1;
		}
		_q /= 26;
	}
	
	ARR = malloc(sizeof(int) * _size);
	
	for(i=0;i<_size;i++){
		_q = _num/26;
		_r = _num%26;
		
		ARR[i] = _r;
		
		if(_q == 0){
			break;
		}	
		
		_num = _q;
	}
	
	for(i=_size-1;i>=0;i--){
		printf("%c", _alphabet[ARR[i]]);
	}
	
	return 0;
}
