#include <bits/stdc++.h>
#include <ostream>
using namespace std;

int n;
char f,sign;
char front [9], top [9], back [9], lef [9], rig [9], bottom [9];

void reset(){
	for (int i = 0; i < 9; i++) top[i] = 'w';
	for (int i = 0; i < 9; i++) front[i] = 'r';
	for (int i = 0; i < 9; i++) bottom[i] = 'y';
	for (int i = 0; i < 9; i++) back[i] = 'o';
	for (int i = 0; i < 9; i++) rig[i] = 'b';
	for (int i = 0; i < 9; i++) lef[i] = 'g';
}
void rotate(char a[9], int k){
	char temp [2];
	if(k==1){
		temp[0]=a[0];a[0]=a[6];a[6]=a[8];a[8]=a[2];a[2]=temp[0];
		temp[1]=a[1];a[1]=a[3];a[3]=a[7];a[7]=a[5];a[5]=temp[1];
	} else {
		temp[0]=a[0];a[0]=a[2];a[2]=a[8];a[8]=a[6];a[6]=temp[0];
		temp[1]=a[1];a[1]=a[5];a[5]=a[7];a[7]=a[3];a[3]=temp[1];
	}
}
void moveU(){
	if (sign == '+'){
		char temp [9];
		for (int i = 0; i <3; i++){temp[i] = front[i]; front[i] = rig[i];rig[i] = back[2-i];back[2-i] = lef[2-i];lef[2-i] = temp[i];}
		rotate(top, 1);
	} else {
		char temp [9];
		for (int i = 0; i <3; i++){temp[i] = front[i]; front[i] = lef[2-i]; lef[2-i] = back[2-i]; back[2-i] = rig[i]; rig[i] = temp[i];}
		rotate(top, 0);
	}
}
void moveD(){
	if (sign == '+'){
		char temp [9];
		for (int i = 6; i <9; i++){temp[i] = front[i]; front[i] = lef[14-i]; lef[14-i] = back[14-i]; back[14-i] = rig[i]; rig[i] = temp[i];}
		rotate(bottom, 0);
	} else {
		char temp [9];
		for (int i = 6; i <9; i++){temp[i] = front[i]; front[i] = rig[i]; rig[i] = back[14-i];back[14-i] = lef[14-i];lef[14-i] = temp[i];}
		rotate(bottom, 1);
	}
}
void moveF(){
	if (sign == '+'){
		char temp [9];
		for (int i = 6; i <9; i++){temp[i] = bottom[i];bottom[i] = rig[24-3*i]; rig[24-3*i] = top[14-i]; top[14-i] = lef[3*i-18];lef[3*i-18] = temp[i];}
		rotate(front, 1);
	} else {
		char temp [9];
		for (int i = 6; i <9; i++){temp[i] = bottom[i];bottom[i] = lef[3*i-18];lef[3*i-18] = top[14-i];top[14-i] = rig[24-3*i];rig[24-3*i] = temp[i];}
		rotate(front, 0);
	}
}
void moveB(){
	if (sign == '+'){
		char temp [3];
		for (int i = 0; i <3; i++){temp[i] = bottom[i];bottom[i] = lef[2+3*i]; lef[2+3*i] = top[2-i]; top[2-i] = rig[8-3*i];rig[8-3*i] = temp[i];}
		rotate(back, 0);
	} else {
		char temp [3];
		for (int i = 0; i <3; i++){temp[i] = bottom[i];bottom[i] = rig[8-3*i]; rig[8-3*i] = top[2-i]; top[2-i] = lef[2+3*i]; lef[2+3*i] = temp[i];}
		rotate(back, 1);
	}
}
void moveL(){
	if (sign == '+'){
		char temp [9];
		for (int i = 0; i < 9; i+=3){temp[i] = bottom[i]; bottom[i] = front[6-i]; front[6-i]=top[6-i]; top[6-i] = back[i]; back[i]=temp[i];}
		rotate(lef, 0);
	} else {
		char temp [9];
		for (int i = 0; i < 9; i+=3){temp[i] = bottom[i]; bottom[i] = back[i]; back[i] = top[6-i]; top[6-i] = front[6-i]; front[6-i] = temp[i];}
		rotate(lef, 1);
	}
}
void moveR(){
	if (sign == '+'){
		char temp [9];
		for (int i = 2; i < 9; i+=3){temp[i] = bottom[i]; bottom[i] = back[i]; back[i] = top[10-i]; top[10-i] = front[10-i]; front[10-i] = temp[i];}
		rotate(rig, 1);
	} else {
		char temp [9];
		for (int i = 0; i < 9; i+=3){temp[i] = bottom[i];bottom[i] = front[10-i]; front[10-i] = top[10-i]; top[10-i] = back[i]; back[i] = temp[i];}
		rotate(rig, 0);
	}
}
void oneRun(){
	reset();
	cin >> n;

	for (int i = 0; i < n; i++){
		cin >> f;
		cin >> sign;

		switch (f){
		case 'U': moveU(); break;
		case 'D': moveD(); break;
		case 'F': moveF(); break;
		case 'B': moveB(); break;
		case 'L': moveL(); break;
		case 'R': moveR(); break;
		}

	}

	for (int i = 0; i < 9; i+=3){
		cout << top[i] << top[i+1] << top[i+2] << endl;
	}
	/* for (int i = 0; i < 9; i+=3){ */
	/* 	cout << front[i] << front[i+1] << front[i+2] << endl; */
	/* } */
	/* for (int i = 0; i < 9; i+=3){ */
	/* 	cout << bottom[i] << bottom[i+1] << bottom[i+2] << endl; */
	/* } */
	/* for (int i = 0; i < 9; i+=3){ */
	/* 	cout << back[i] << back[i+1] << back[i+2] << endl; */
	/* } */
	/* for (int i = 0; i < 9; i+=3){ */
	/* 	cout << rig[i] << rig[i+1] << rig[i+2] << endl; */
	/* } */
	/* for (int i = 0; i < 9; i+=3){ */
	/* 	cout << lef[i] << lef[i+1] << lef[i+2] << endl; */
	/* } */
	/* cout << "==============" << endl; */
	/* for (int i = 0*2; i < 9; i=i+3) cout << top[i] << endl; */
}

int main(){

	int cases;
	cin >> cases;

	while(cases > 0){
		oneRun();
		cases--;
	}

    return 0;
}
