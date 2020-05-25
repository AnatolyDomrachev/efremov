#include <iostream> 
#include <stdlib.h>
#include <algorithm>

using  namespace  std;

struct node
{
  int data;
  node *left;
  node *right;
};

void print(struct node* leaf)
{
	cout << leaf << " " << leaf->data << " " << leaf->left << " " << leaf->right << endl;
	if(leaf->left)
		print(leaf->left);
	if(leaf->right)
		print(leaf->right);
}


int main()
{
	int a[] = {1,2,3,4,5,6,7};
	int b[] = {2,4,6,8,10,12,14};

	struct node* tree1 = new struct node;
	tree1->data = a[0];
	tree1->left = new struct node;
	tree1->right = new struct node;
	tree1->left->data = a[1];
	tree1->right->data = a[2];
	tree1->left->left = new struct node;
	tree1->left->right = new struct node;
	tree1->right ->left = new struct node;
	tree1->right ->right = new struct node;
	tree1->left->left->data = a[3];
	tree1->left->right->data = a[4];
	tree1->right->left->data = a[5];
	tree1->right->right->data = a[6];
	tree1->left->left->left = NULL;
	tree1->left->left->right = NULL;
	tree1->left->right->left = NULL;
	tree1->left->right->right = NULL;
	tree1->right->left->left = NULL;
	tree1->right->left->right = NULL;
	tree1->right->right->left = NULL;
	tree1->right->right->right = NULL;

	struct node* tree2 = new struct node;
	tree2->data = b[0];
	tree2->left = new struct node;
	tree2->right = new struct node;
	tree2->left->data = b[1];
	tree2->right->data = b[2];
	tree2->left->left = new struct node;
	tree2->left->right = new struct node;
	tree2->right ->left = new struct node;
	tree2->right ->right = new struct node;
	tree2->left->left->data = b[3];
	tree2->left->right->data = b[4];
	tree2->right->left->data = b[5];
	tree2->right->right->data = b[6];
	tree2->left->left->left = NULL;
	tree2->left->left->right = NULL;
	tree2->left->right->left = NULL;
	tree2->left->right->right = NULL;
	tree2->right->left->left = NULL;
	tree2->right->left->right = NULL;
	tree2->right->right->left = NULL;
	tree2->right->right->right = NULL;

	cout << "Tree 1" << endl;
	print(tree1);
	cout << endl;
	cout << "Tree 2" << endl;
	print(tree2);
	return 0;
}
