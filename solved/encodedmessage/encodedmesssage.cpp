#include <stdio.h>
#include <iostream>
#include <math.h> 
#include <string.h>



int main(){
	int cases;

	std::cin >> cases;


	for(int p = 0; p < cases; p++){
		std::string message;
		std::cin >> message;
		int n = message.length();

		int ln = sqrt(n);

		std::string ans;

		for (int j = ln-1; j > -1; j--){
			for(int i = 0; i < ln; i++){
				ans = ans + message[j + i*ln];
			}
		}

			/* std::cout << (N+1)/2 + (N+1)/3 << std::endl; */
		std::cout << ans << std::endl;
	}
	    return 0;
}
