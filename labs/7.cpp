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

void create_src_tree(struct node* tree, int a[])
{
	tree->data = a[0];
	tree->left = new struct node;
	tree->right = new struct node;
	tree->left->data = a[1];
	tree->right->data = a[2];
	tree->left->left = new struct node;
	tree->left->right = new struct node;
	tree->right ->left = new struct node;
	tree->right ->right = new struct node;
	tree->left->left->data = a[3];
	tree->left->right->data = a[4];
	tree->right->left->data = a[5];
	tree->right->right->data = a[6];
	tree->left->left->left = NULL;
	tree->left->left->right = NULL;
	tree->left->right->left = NULL;
	tree->left->right->right = NULL;
	tree->right->left->left = NULL;
	tree->right->left->right = NULL;
	tree->right->right->left = NULL;
	tree->right->right->right = NULL;
}

void add_new_data(int data, struct node** tree )
{
	if(!*tree) // если указывает на NULL
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

	if(src_tree->left) // если существует левый узел, то добавить его
		add_new_tree(src_tree->left, dst_tree);// для правого
	if(src_tree->right)
		add_new_tree(src_tree->right, dst_tree);
}

int main()
{
	int a[] = {8,2,3,6,5,4,7};
	int b[] = {8,9,6,0,60,92,84};

	struct node* tree1 = new struct node;
	struct node* tree2 = new struct node;
	struct node* tree3 = NULL;

	create_src_tree(tree1, a);
	create_src_tree(tree2, b);

	add_new_tree(tree1, &tree3); //Передаём указатель на указатель так как содержимое этой ячейки памяти будет меняться
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
