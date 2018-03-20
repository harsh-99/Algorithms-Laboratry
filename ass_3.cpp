#include <iostream>
#include <stdlib.h>

using namespace std;

void merge(int m[], int l, int mid, int r)
{
    int i, j, k;
    int n1 = mid - l + 1;
    int n2 =  r - mid;
 
    
    int L[n1], R[n2];
 
   
    for (i = 0; i < n1; i++)
        L[i] = m[l + i];
    for (j = 0; j < n2; j++)
        R[j] = m[mid + 1+ j];
 
    
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            m[k] = L[i];
            i++;
        }
        else
        {
            m[k] = R[j];
            j++;
        }
        k++;
    }
 
    
    while (i < n1)
    {
        m[k] = L[i];
        i++;
        k++;
    }
 
   
    while (j < n2)
    {
        m[k] = R[j];
        j++;
        k++;
    }
}
 

void solveGRD(int m[], int l, int r)
{
    if (l < r)
    {
        
        int mid = l+(r-l)/2;
 
        
        solveGRD(m, l, mid);
        solveGRD(m, mid+1, r);
 
        merge(m, l, mid, r);
    }
}

int min(int a, int b){
	if(a<b)
		return a;
	else 
		return b;

}

void solveDP(int m[], int p[], int n, int a){
	int min_efforts, max_points;	
	int r = n+1;
	int i,s,j;
	s=0;
	int m0,m1;
	for(i=0;i<n;i++){
		s+=p[i];
	}
	cout<<"the value of s"<<s;
	int **t = (int **)malloc(r * sizeof(int *));
	for (i=0; i<r; i++){
		t[i] = (int *)malloc((s+1) * sizeof(int));
	}
	for(i=0;i<=n;i++){
		t[i][0] = 0;	
	}
	for(i=1;i<=n;i++){
		t[0][i] = 10000;	
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=s;j++){
			if(j<p[i-1]){
				t[i][j] = t[i-1][j];
				continue;
			}
			else if(j >= p[i-1]){
			m0 = t[i-1][j];
			m1 = t[i-1][j-p[i-1]] + m[i-1];
			if(m1 < a){
				t[i][j] = min(m0,m1);
			}
			else t[i][j] = m0;
		}
	}
	}
	for(j=1;j<=s;j++){
		if(t[n][j] != 10000){
			min_efforts = t[n][j];
			max_points = j;
		}
	}
	cout<<"\nMaximum points-:" << max_points;
	cout<<"\nMinimum efforts-:"<< min_efforts;

}

int main(){
	int i,n,a,sum;
	sum = 0;
	cout<<"Enter the value of n-:";
	cin>>n;
	cout<<"enter the value of total possible time-:";
	cin>>a;
	int m[n],p[n];
	cout<<"Enter the minutes of each assignment\n";
	for(i=0;i<n;i++){
		cin>>m[i];
	}
	
	
	solveGRD(m, 0, (n-1));
	cout<<"the sorted array\n";
	for(i=0;i<n;i++){
		cout<<m[i]<<"\n";
	}
	cout<<"part1 \nMinimum effort =";
	for(i=0;i<n;i++){
		sum += m[i];
		if (sum<a) {
			cout<<m[i]<<"+";
		}
	}
	cout<<"\nthe 2nd part starts\n";
	cout<<"Enter the efforts of each assignment\n";
	for(i=0;i<n;i++){
		cin>>m[i];
	}
	cout<<"Enter the points of each assignment respectivly\n";
	for(i=0;i<n;i++){
		cin>>p[i];
	}
	solveDP(m,p,n,a);


}
