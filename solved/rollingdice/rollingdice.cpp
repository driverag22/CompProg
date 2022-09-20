#include <stdio.h>
#include <iostream>
#include <math.h> 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll x,y;
int top, front, east, l, orient = 0, mul = 1;


void rollX(int mul, int orient) {
	if (orient == 0){
		x += mul; mul = mul % 4;
		for(int i = 0; i < mul; i++){
			int t = front; front = east; east = 7 - t; 
		} 
	} else {
		x -= mul; mul = mul % 4;
		for(int i = 0; i < mul; i++){
			int t = front; front = 7 - east; east = t;	
		}	
	}
}
void rollY(int mul, int orient) {
	if (orient == 0){
		y += mul; mul = mul % 4;
		for(int i = 0; i < mul; i++){
			int t = front; front = top; top = 7 - t; 
		} 
	} else {
		y -= mul; mul = mul % 4;
		for(int i = 0; i < mul; i++){
			int t = front; front = 7 - top; top = t;	
		} 
	}
}

void oneRun(){
	x = 0; y = 0;
	front = 1; east = 3; top = 2; mul = 1; orient = 0;

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++){
		switch (s[i]) {
			case '+': orient = 0; break;
			case '-': orient = 1; break;
			case 'X': rollX(mul, orient); mul = 1; break;
			case 'Y': rollY(mul, orient); mul = 1; break;
			case '.': std::cout << "position (" << x<< "," << y << "), " << front << " dots" << std::endl; break;
			default: mul = s[i] - '0'; 
		}
	}
	
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
