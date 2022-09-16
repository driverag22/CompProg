#include <stdio.h>
#include <iostream>
#include <math.h> 


int main(){

	int cases, n, m, counter;
	std::cin >> cases;

	for (int i = 0; i < cases; i++){
		std::cin >> n;
		int mosqx [n];
		int mosqy [n];


		int a,b;

		for (int j = 0; j < n; j++){
			std::cin >> a;
			std::cin >> b;
			mosqx[j] = a;
			mosqy[j] = b;
		}

		std::cin >> m;

		int swatx [m];
		int swaty [m];
		
		for (int j = 0; j < m; j++){
			std::cin >> a;
			std::cin >> b;
			swatx[j] = a;
			swaty[j] = b;
		}


		counter = 0;

		for (int j = 0; j < n; j++){

			for (int k = 0; k < m; k++){
				
				if( ( abs( mosqx[j]- swatx[k]) < 51) && (abs( mosqy[j]- swaty[k]) < 51) ) {
					counter++;
					break;
				}

			}
		}

		std::cout << counter << std::endl;
	}

    return 0;
}
