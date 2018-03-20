#include<iostream>
#include<stdlib.h>

using namespace std;
typedef struct a{
	int l;
	int r;
	int c;
}heap;

void heapify(heap* h,int i,int n){
	int m,l,r;
	heap b;
	while(1){
		l = 2*i; r= (2*i)+1;
		if(l>n) break;
		m=r;
		if(h[l].c < h[r].c) m=l;
		if(h[i].c < h[m].c) break;
		b = h[i];
		h[i] = h[m]; 
		h[m] = b;
		i= m; 
	}
}
void makeheap(heap* h,int n){
	int i; 
	for(i=n;i>=1;i--){
		heapify(h,i,n);
	}
}
void insert(heap* h,int n,int x){
	n++;
	h[n].c = x;
	int m =n;
	heap b;
	while(1){
		if(m==1) break;
		if(h[m].c>h[m/2].c) break;
		b = h[m];
		h[m] = h[m/2];
		h[m/2] = b;
		m = m/2;
	} 	
		
}
void deletemin(heap* h, int n){
	h[1] = h[n];
	--n;
	heapify(h,1,n);	
}

void greedy1(heap *h,int k,int n){
	int *e = (int *)malloc(n*sizeof(int));
	int i;
	int sum =0;
	for(i=0;i<n;i++){
		e[i]=0;
	}
	for(i=1;i<n;i++){
		sum+=h[i].c;
	}
	int y,x,cost;
	cost =0;
	int j=0;
	for(i=1;i<n;i++){
		y=h[1].l;
		x=h[1].r;
		if(e[x] == 0 && e[y] == 0){
			e[x]=1;
			e[y]=1;
			cout<<"("<<x<<","<<y<<"):";
			cout<<h[1].c<<"\n";
			cost+=h[1].c;
			j++; 
		}
		if (j==k) break;
		deletemin(h,(n-i));
	}
	if (j == (k-1)) cost = cost+sum;
	cout<<"the value of j is"<<j<<"\n";
	cout<<cost<<"\n";              //my greedy is giving optimal solution for the given example
} 
void greedyec(heap *h,int n,int k){
	int *e = (int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		e[i]=0;
	}
	

} 
int main(){
	int i,n,k;
	cout<<"Enter the value of n-:";
	cin>>n;
	cout<<"Enter the value of k-:";
	cin>>k;
	cout<<"Enter the distance\n";
	heap *h =(heap *)malloc((n)*sizeof(heap));   
	for(i=1;i<n;i++){
		h[i].l = i-1;
		h[i].r = i;		
		cin>>h[i].c;
	} 
	makeheap(h,(n-1));
	for(i=1;i<n;i++){
		cout<<h[i].c<<"\n";
	} 
	greedy1(h,k,n);
}
