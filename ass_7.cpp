#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct hash{
	int hash_i,hash_sigma,hash_flag;
};

struct hash* htinit(int s){
	struct hash* h = (struct hash *)malloc(s*sizeof(struct hash));
	for(int i=0;i<s;i++){
		h[i].hash_i = h[i].hash_sigma = h[i].hash_flag = 0;
	}
	return h;
}

int hashfunc(int i,int sigma,int j,int s){
	return(((100003*i)+(103*sigma)+j)%s);
}

int htsearch(struct hash* h, int i, int sigma, int s){
	int j,l;
	for(j=0;j<s;j++){
		l = hashfunc(i,sigma,j,s);
		if(h[l].hash_i == i && h[l].hash_sigma == sigma)
			return(l);
	}
	return 0;
}

void htinsert(struct hash* h, int i, int sigma, int flag, int s){
	int l,j;
	if (htsearch(h,i,sigma,s) > 0) return;
	for(j=0;j<s;j++){
		l = hashfunc(i,sigma,j,s);
		if(h[l].hash_i == 0 && h[l].hash_sigma == 0){
			h[l].hash_i = i;
			h[l].hash_sigma = sigma;
			h[l].hash_flag = flag;
		}
		return;
	}
}

int exhs(int a[], int i, int sum, int t, int n){
	if(i==n){
		if ((sum+a[i]) < t) return (sum+a[i]);
		else if (sum<t) return sum;
		else return 0;
	}
	if (sum > t){
		return 0;
	}
	
	int j1 = exhs(a,(i+1),sum,t,n);
	int j2 = exhs(a,(i+1),(sum+a[i]),t,n);
	if (j1>j2) return j1;
	else return j2;
}

int hashs(int i,int sigma, int a[],int t, int n, struct hash* h, int s){
	int v1,v2;
	cout<<"value of i"<<i;
	if(i==n){
		if ((sigma+a[i]) < t) return (sigma+a[i]);
		else if (sigma<t) return sigma;
		else return 0;
	}

	if (sigma>t) return 0;
	if (htsearch(h,i,sigma,s)==0){
		v1= hashs(i+1,sigma,a,t,n,h,s);
		htinsert(h,i,sigma,0,s);
		cout<<"hhhhh";
	}
	else return h[(htsearch(h,i,sigma,s))].hash_sigma;

	if (htsearch(h,i,sigma+a[i],s) == 0){
		v2 = hashs((i+1),(sigma+a[i]),a,t,n,h,s);
		htinsert(h,i,sigma+a[i],1,s);
	}
	else return h[(htsearch(h,i,sigma+a[i],s))].hash_sigma;
	cout<<"the value of v1"<<v1;
	if (v1>v2) return v1;
	return v2;	 

}
int main(){
	int c,n,i;
	cout<<"Enter the value of N -:";
	cin>>n;
	int a[n],sum = 0,p;
	cout<<"Enter the value of treasures\n";
	for(i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	int t = sum/2;
	p= exhs(a,0,0,t,(n-1));
	cout<<"sum ="<<sum;
	cout<<"\nt="<<t;
	cout<<"\nExhaustive search, The maximum P ="<<p;
	int s = n*t;
	struct hash* h;
	h = htinit(s);
	c = hashs(0,0,a,t,n-1,h,s);
	cout<<"\nthe value of p by hash is-:"<<c;
}