#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

struct list{
	int key;
	struct list *ptr;
};

void bfs1(int v, int n, struct list *h,int n2){
	int a[n],i,u;
	int level[n];
	for(i=0;i<n;i++){
		a[i] =0;
		level[i] = 0;
	}
	queue <int> q;
	a[v] = 1;
	q.push(v);
	struct list* c;
	while(!q.empty()){
		u = q.front();
		q.pop();
		h[u].ptr = c;
		while(c->ptr != NULL){
			if(a[c->key] == 0) {
				q.push(c->key);
				a[c->key] = 1;
				level[c->key] = level[u]+1;
			}
			c = c->ptr;
		}		
	}
}
int bfs(int v, int n, struct list *h,int n2){
	int* a = new int[n];
	cout<<v;
	int i,u;
	int level[n];
	for(i=0;i<n;i++){
		a[i] =0;
		level[i] = 0;
	}
	queue <int> q;
	a[v] = 1;
	q.push(v);
	struct list* c;
	int flag =0;
	while(!q.empty() && flag ==0){
		u = q.front();
		q.pop();
		for(i=0;i<n2;i++){
			if (u == n-i) flag =1;
		}
		h[u].ptr = c;
		if(c != NULL)
		while(c->ptr != NULL){
			if(c == NULL) break;
			cout<<a[c->key];
		// 	if(a[c->key] == 0) {
		// 		q.push(c->key);
		// 		a[c->key] = 1;
		// 		level[c->key] = level[u]+1;
		// 	}
		// 	c = c->ptr;
		}		
	}
	if (flag==1) return level[u];
	else return 999999999;
}


int main(){
	int n,m,n1,n2,i,a,b;
	cout<<"n=";
	cin>>n;
	cout<<"m=";
	cin>>m;
	cout<<"n1=";
	cin>>n1;
	cout<<"n2=";
	cin>>n2;
	struct list* h = (struct list *)malloc(n*sizeof(struct list));
	struct list* c;
	struct list* d;
	for(i=0;i<n;i++){
		h[i].key = i;
		h[i].ptr = NULL;
	}
	cout<<"Enter the values of the list in the pair\n";
	for(i=0;i<m;i++){
		cin>>a;
		cin>>b;
		struct list* new1 = (struct list *)malloc(sizeof(struct list));
		struct list* new2 = (struct list *)malloc(sizeof(struct list));
		new1->key = b;
		new1->ptr = h[a].ptr;
		new2->key = a;
		new2->ptr = h[b].ptr;		
		//c = new1;
		//d = new2;
		h[a].ptr = new1;
		h[b].ptr = new2;

	}
	for(i=0;i<n;i++){
		c = h[i].ptr;
		cout<<h[i].key<<"=";
		// cout<<c->key;
		while(c != NULL){
			cout<<c->key<<"->";
			c = c->ptr;
		}
		cout<<"\n";
	}
	int min = 999999999;
	int r;
	for(i=0;i<n1;i++){
		r = bfs(i,n,h,n2);
		if(r<min){
			r = min;
		}
	}
	cout<<"D(V1,V2) = "<<min;

}