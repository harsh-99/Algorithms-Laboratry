#include<iostream> 
#include <stdlib.h>
#include<stdio.h>

using namespace std;
typedef struct _node {
struct _node *l; 
struct _node *r; 
struct _node *p;
} treenode;

void printree(treenode *s, int l){
	int i;
	if(l ==0) cout<<"x\n";
	else{
		if(s!=NULL){
			for(i=0;i<(4*l);i++){
			cout<<" ";
			}
			cout<<"+---X\n";
		}
		else if(s == NULL){
			for(i=0;i<(4*l);i++){
				cout<<" ";		
			}
			cout<<"+---!\n";		
			return;
		} 
	}
	printree(s->l,l+1);
	printree(s->r,l+1);
}
void destroytree(treenode *s, int n){
	if(s!=NULL){
		destroytree(s->l,n);
		destroytree(s->r,n);
		free(s);
	}

}

void genec1(treenode *s,int *b,int t){
	treenode *temp = s;
	if(s!=NULL){	
		if(s->l != NULL){
			b[t]=0;
			cout<<0<<"\n";
			genec1(temp->l,b,t+1);	
		}
		if (s->r !=NULL){
			b[t] = 1;
			cout<<1<<"\n";
			genec1(temp->r,b,t+1);
		}
		if(s->l == NULL && s->r ==NULL){
			b[t] = 2;
			cout<<2<<"\n";	
		}
	}
	
}

treenode* buildtree(int *a, int n){  
	int i;
        treenode *root = (treenode *)malloc(sizeof(treenode *));
	root->p= NULL;
	root->l=NULL;root->r=NULL;
	treenode *s = (treenode *)malloc(sizeof(treenode));
	s = root;
	for(i=0;i<n;i++){
		if(a[i] ==0){
			treenode *v = (treenode *)malloc(sizeof(treenode));
			v->l = NULL;
			v-> r = NULL;
			s->l = v;
			v->p = s;
			s = s->l;
			printf("hahah\n");	
		}
		else if(a[i] ==1){
			treenode *v = (treenode *)malloc(sizeof(treenode));
			v->l = NULL;
			v-> r = NULL;
			s->r = v;
			v->p = s;
			s= s->r;
			cout<<"bbb\n";
		}
		else if(a[i] ==2){
			s = s->p;
			printf("ccc\n");		
			}

	}	
	return root;
}
int main(){
	int i,n;
	treenode *root;
	cout<<"enter the value of n-:";
	cin>>n;
	int a[n],b[n],c[n];
	cout<<"Enter the string\n";
	for(i=0;i<n;i++){
		cin>>a[i];
		b[i] = 0;	
	}
	root = buildtree(a, n);
	//cout<<"X\n";
	printree(root,0);
	genec1(root,b,0);


}
