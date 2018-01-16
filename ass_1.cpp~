#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdlib.h> 

using namespace std;

extern void registerme ( );
extern void startgame ( int );
extern int guess ( int );
extern void verifysoln ( int );

int playgame1(){
	int i,b;
	b=5;
	for(i=0;i<100000000;i++){
		b = guess(i);
		if(b == 1){
			return i;
			exit;
		}		
	}

}

int playgame2(){
	int i,b;
	for(i=0;i=100000000;i++){
		b = rand()%100000000;
		if (guess(b) == 1){
			return b;
			exit;
		}
	}

}
int playgame3(){
int i,b,l,r,mid;
r = 100000000;
l = 1;
for (i=0;i<28;i++){
	guess(l);
	b = guess (r);
	cout<<b<< endl;
	if(b==2){
		l = (r+l)/2;
	}
	else if(b==3){
		r = (r+l)/2;
        }
	else if(b == 1){
		return r;
		exit;
	}	
	
}	

}
int playgame4(){
	int l,r,i,a;
	for(i=0;i<14;i++){
		guess(l-1);
		a = guess(r+1);
		if (
	}

}	


int main(){
int a;
clock_t c1, c2;
registerme();
cout << "hello";
startgame(1);
c1 = clock(); 
a = playgame1();
c2 = clock(); 
printf("\n+++ Game 1\n    a1 = %d\n", a);
printf("    Time taken = %lf sec\n", (double)(c2-c1)/(double)CLOCKS_PER_SEC);
verifysoln(a);

startgame(2);
c1 = clock(); 
a = playgame2();
c2 = clock(); 
printf("\n+++ Game 2\n    a2 = %d\n", a);
printf("    Time taken = %lf sec\n", (double)(c2-c1)/(double)CLOCKS_PER_SEC);
verifysoln(a);

startgame(3);
c1 = clock(); 
a = playgame3();
c2 = clock(); 
printf("\n+++ Game 3\n    a3 = %d\n", a);
printf("    Time taken = %lf sec\n", (double)(c2-c1)/(double)CLOCKS_PER_SEC);
verifysoln(a);
}	
