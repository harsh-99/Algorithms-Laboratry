#include <iostream>
#include <stdlib.h>

using namespace std;
int greedy(int **c, int n){
	int min =99999;
	int i,j,l_j,cost,sum = 0;
	for(j=0;j<n;j++){
		if(c[0][j]< min){
			min = c[0][j];
			l_j = j;
		}
	}
	cout<<"\nThe minimum for 1st is "<<min<<" coordinate is (0,"<<l_j<<") to (1,"<<l_j<<")\n";
	sum = min;
	min = 999999;
	int t = l_j;
	for(i=1;i<n-1;i++){
		for(j=t;j<n;j++){
			cost = 5*(j-t)+c[i][j];
			if(cost<min) {
				min = cost;
				l_j = j;
			}
		}
		cout<<"The minimum for"<<(i+1)<<"is "<<min<<" coordinate is ("<<(i+1)<<","<<l_j<<") to ("<<i+1<<","<<l_j<<")\n";
		sum += min;
		min = 99999;
		t = l_j;
	}
	return sum;
}
int greedy1(int **c, int n, int i, int j){         // This has used recursion. It is of no use. 
	int t, d[n-j], min;
	min = 999999;
	if(i==0){
		for(t=j;t<n;t++){
			d[t-j] = greedy1(c,n,(i+1),t) + c[i][t];
		}
		for(t=0;t<(n-j);t++){
			if(d[t]<min) min = d[t];
		}
		cout<<min<<"\n";
		return min;
		}
	if (i>0 && i<(n-1)){
		for(t=j;t<n;t++){
			d[t-j] = 5*(t-j) + greedy1(c,n,(i+1),t) + c[i][t];
		}
		for(t=0;t<(n-j);t++){
			if(d[t]<min) min = d[t];
		}
		cout<<min<<"\n";
		return min;
	}
	if(i==(n-1)) return 0;
}
void dp(int **c, int n){
	int i,j;
	int **t = (int **)malloc(n*sizeof(int *));
	for(i=0;i<(n);i++){
		t[i] = (int *)malloc(n*sizeof(int));
	} 
	for(i=0;i<n;i++){
		t[0][i] = 0;
	}
	int sum = 0;
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			sum += c[j][0];
		}
		t[i][0] = sum;
		sum =0;
	}
	int j1,j2;
	for(i=1;i<n;i++){
		for(j=1;j<n;j++){
			j1 = t[i-1][j]+c[i-1][j];
			j2 = t[i][j-1]+5;
			if(j1>j2) j1 = j2;
			t[i][j] = j1;
		}
	}
	int min =99999;
	for(i=0;i<n;i++){
		if(min>t[n-1][i]) min = t[n-1][i];
	}
	cout<<"\nThe value fron Dp is"<<min;
}
void dpsol(int **c, int n){
	int i,j;
	int **t = (int **)malloc(n*sizeof(int *));
	int **d = (int **)malloc(n*sizeof(int *));
	for(i=0;i<(n);i++){
		t[i] = (int *)malloc(n*sizeof(int));
		d[i] = (int *)malloc(n*sizeof(int));
	} 
	for(i=0;i<n;i++){
		t[0][i] = 0;
	}
	int sum = 0;
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			sum += c[j][0];
		}
		t[i][0] = sum;
		sum =0;
	}
	int j1,j2,min;
	for(i=1;i<n;i++){
		for(j=1;j<n;j++){
			j1 = t[i-1][j]+c[i-1][j];
			j2 = t[i][j-1]+5;
			if(j1>j2) {min = j2;
				d[i][j] = 1;}
			else {min = j1;
				d[i][j] = 0;}

			t[i][j] = min;
		}
	}
	min =99999;
	int s;
	for(i=0;i<n;i++){
		if(min>t[n-1][i]) {min = t[n-1][i];
			s = i;}
	}

	//cout<<"The value fron Dp is"<<min;
	i = n-2;
	int h_cost =0;
	cout<<"\nBuilding bridge b/w ("<<n-1<<","<<s<<") and ("<<(n-2)<<","<<s<<") with the cost-"<<c[n-2][s];
	while(i!=0){
		if(d[i][s] == 1){
			s = s-1;
			h_cost +=5;
		}
		else {
			cout<<"\nBuilding bridge b/w ("<<i<<","<<s<<") and ("<<(i-1)<<","<<s<<") with the cost-"<<c[i-1][s];
			i--;
		}
	}
	cout<<"\ntotal horizontal cost is -:"<<h_cost<<"\n";
}
int main(){
	int d,n,i,a,j;
	cout<<"Enter the value of n -";
	cin>>n;
	int **c = (int **)malloc((n-1)*sizeof(int *));
	for(i=0;i<(n-1);i++){
		c[i] = (int *)malloc((n)*sizeof(int));
	}
	cout<<"Enter the matric C\n";
	for(i=0;i<n-1;i++){
		for(j=0;j<n;j++){
			cin>>a;
			c[i][j] = a;
		}
	}
	cout<<"*******Using Greedy*********";
	d = greedy(c,n);
	cout<<d<<"\n";
	cout<<"*******Using DP*********";
	dp(c,n);
	cout<<"*******Using DPsol*********";
	dpsol(c,n);
	
}