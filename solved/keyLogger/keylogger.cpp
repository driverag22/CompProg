#include <stdio.h>
#include <iostream>
#include <list>
#include <math.h> 
#include <bits/stdc++.h>
using namespace std;

char input[1000005];

void oneRun(){
	string input;
	cin >> input;
    /* scanf("%s", input); */
    list<char> answer;
    list<char>::iterator currPos = answer.begin();
	for (int i = 0; input[i]; i++){
		switch (input[i]) {
            case '<': if(currPos != answer.begin()) currPos--; break;
            case '>': if(currPos != answer.end()) currPos++; break;
            case '-': if(currPos != answer.begin()) currPos = answer.erase(--currPos); break;
			default: currPos = answer.insert(currPos, input[i]); currPos++; break;
		}
	}
    for (char letter : answer) cout << letter;
    cout << endl;
}
int main(){

	int cases;
	std::cin >> cases;

	while(cases > 0){
		oneRun();
		cases--;
	}

    return 0;
}

