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

void create_src_trees(struct node* tree1, struct node* tree2, int a[], int b[] )
{
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
}

void add_new_data(int data, struct node** tree )
{
	if(!*tree)
	{
		(*tree) = new struct node;
		(*tree)->left = NULL;
		(*tree)->right = NULL;
		(*tree)->data = data;
	}
	else
		if(data < (*tree)->data)
			add_new_data(data, &((*tree)->left) );
		else
			add_new_data(data, &((*tree)->right) );
}

void add_new_tree(struct node* src_tree, struct node** dst_tree )
{
	add_new_data(src_tree->data, dst_tree );

	if(src_tree->left)
		add_new_data(src_tree->left->data, dst_tree);
	if(src_tree->right)
		add_new_data(src_tree->right->data, dst_tree);
}

int main()
{
	int a[] = {1,2,3,4,5,6,7};
	int b[] = {2,4,6,8,10,12,14};

	struct node* tree1 = new struct node;
	struct node* tree2 = new struct node;
	struct node* tree3 = NULL;

	create_src_trees(tree1, tree2, a, b);

	add_new_tree(tree1, &tree3);
	add_new_tree(tree2, &tree3);

	cout << "Tree 1" << endl;
	print(tree1);
	cout << endl;
	cout << "Tree 2" << endl;
	print(tree2);
	cout << "Tree 3" << endl;
	print(tree3);
	return 0;
}
