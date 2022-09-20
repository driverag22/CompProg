#include <stdio.h>
#include <iostream>
#include <math.h> 


int main(){

	int cases, i, N;
	std::cin >> cases;

	for (i = 0; i < cases; i++){
		std::cin >> N;
		if (N % 2 == 0){
			std::cout << (N+1)/2 + (N+1)/3 << std::endl;
		} else {
			std::cout << (N+1)/2 + (N+3)/3 << std::endl;
		}
	}

    return 0;
}
