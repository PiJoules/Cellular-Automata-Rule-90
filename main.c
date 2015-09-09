#include <stdio.h>
#include <string.h>

#define STEPS 25

int char2int(char a){
	return a-'0';
}

char int2char(int a){
	return a+'0';
}

char xorChar(char a, char b){
	return int2char(char2int(a)^char2int(b));
}

void convert(int len, char input[len]){
	int i;
	char copy[len];

	// Account for left and right most digits
	// Apparently ^ is XOR in C
	copy[0] = xorChar('0', input[1]);
	copy[len-1] = xorChar(input[len-2], '0');

	for (i = 1; i < len-1; i++){
		copy[i] = xorChar(input[i-1], input[i+1]);
	}

	for (i = 0; i < len; i++){
		input[i] = copy[i];
	}
}

int main(int argc, char* argv[]){
	if (argc < 2){
		return 1;
	}

	int i;
	int len = strlen(argv[1]);
	char input[len];
	for (i = 0; i < len; i++){
		input[i] = argv[1][i];
	}

	for (i = 0; i < STEPS; i++){
		printf("%s\n", input);

		// Break the loop if a string of 0s since
		// it will just be 0s from then on.
		int sum = 0;
		int j;
		for (j = 0; j < len; j++){
			sum |= input[j]-'0';
		}
		if (!sum){
			return;
		}

		convert(len, input);
	}

	return 0;
}