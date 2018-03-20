#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct bst
{
	int key;
	struct bst *l;
	struct bst *r;/* data */
};

void buildbst(int a[], int l, int r, struct bst *parent){
	// cout<<parent->key<<"\n";
	int m;
	int le = l;
	int ri = r;
	// if (l=r+1){
	// 	if
	// }
	struct bst *left = (struct bst *)malloc(sizeof(struct bst));
	struct bst *right = (struct bst *)malloc(sizeof(struct bst));
	left->l = left->r = right->r = right->l = NULL;
	int k = a[l-1];
	if(a[l]>k) r=l;
	else if (a[r]<k) l=r;
	else {
			while (r!=l+1){
				m = (l+r)/2;
				if (a[m] < k) l=m;
				else r=m;
			}
		}
	if (l == le && r == ri){
		right-> key = a[r];
		left->key = a[le];
		parent->l = left;
		parent->r = right;
	}
	else if (l == le){
		right-> key = a[r];
		parent->l = NULL;
		parent->r = right;
	}
	else if (r == ri){
		left->key = a[le];
		parent->l = left;
		parent->r = NULL;
	}
	else {
		right-> key = a[r];
		left->key = a[le];
		parent->r = right;
		parent->l = left;
	}
	// cout<<"the value of a[l]"<<a[l];
	// cout<<"the value of left key"<<left->key;

	if (le != l) buildbst(a, (le+1), l, left);
	if (ri != r) buildbst(a, (r+1), ri, right);
	if (l==r) return;

}
void preorder(struct bst *root){
	if (root == NULL) return;
	cout<<root->key<<"\n";
	preorder(root->l);
	preorder(root->r);

}
int isBST(struct bst *t, int l, int r){
	if (t==NULL) return 1;
	if (t->key > l && t->key < r){
		isBST(t->l,l,t->key);
		isBST(t->r,t->key,r);
	}
	else return 0;
}
struct bst* inorderSuccessor(struct bst* root, int x)
{
	if(root == NULL) return NULL;
	struct bst* left = NULL;
	struct bst* p = root;
	while(p->key != x)
	{
		if(p->key > x) 
		{ left = p;
		  p = p->l;
		}
		else p = p->r;
		if(p == NULL) break;
	}
	if(p == NULL) return NULL;
	
	if(p->r == NULL) return left;

	p = p->r;
	while(p->l != NULL)
		p = p->l;
	return p;
}
int main(){
	int n,i,t,x;
	cout<<"Enter the size of array-:";
	cin>>n;
	int a[n];
	cout<<"Enter the array elements in preorder list\n";
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	struct bst *root = (struct bst *)malloc(sizeof(struct bst));
	root->key = a[0];
	root->l = NULL;
	root ->r = NULL;
	buildbst(a,1,(n-1), root);
	cout<<"The preorder listing is \n";
	preorder(root);
	t = isBST(root, -99999, 99999);
	if (t==1){
	 	cout<<"This is a BST\n";
    }
    cout<<"Enter the element for inordersuccessor-:";
    cin>>x;
    struct bst* p = inorderSuccessor(root,x);
    cout<<"The inordersuccessor is-:"<<p->key<<"\n";
}
