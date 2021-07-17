#include <iostream>
using namespace std;
struct node
{
	int data;
	node* right;
	node* left;
};
class BST
{

public:
	BST();
	void insert(int val);
	node* insert(int val, node* leaf);
	void inorder_print();
	void preorder_print();
	void postorder_print();
	void Search(int key);
	void Find_Min();
	void Find_Max();
	void Delete_Node(int x);
	void size_print();
	void Print_second_Largest_in_List(node* leaf);
	void Print_third_Laragest_in_the_List(node* leaf);
	void Print_Second_Smallest_in_the_list(node* leaf);
	void Print_Third_Smallest_in_the_list(node* leaf);
	void EALandS();
	void Display_Range(int k1, int k2);

private:
	void postorder_print(node* leaf);
	void preorder_print(node* leaf);
	void inorder_print(node* leaf);
    node * Search(node* leaf, int key);
	node* Find_Min(node* leaf);
	node* Find_Max(node* leaf);
	node* Delete_Node(node* root, int x);
	int size(node* leaf);
	void Second_Largest(node* leaf, int& x);
	void Third_Laragest(node* leaf, int& y);
	void Second_Smallest(node* leaf, int& x);
	void Third_Smallest(node* leaf, int& x);
	void Print_Range(node* leaf, int k1, int k2);
	node* root;

};
BST::BST()
{
	root = NULL;
}
node* BST::insert(int val, node* leaf)
{
	if (leaf == NULL)
	{
		leaf = new node;
		leaf->data = val;
		leaf->left = NULL;
		leaf->right = NULL;
	}
	else if (val < leaf->data)
	{
		leaf->left = insert(val, leaf->left);
	}
	else if (val > leaf->data)
	{
		leaf->right = insert(val, leaf->right);
	}
	return leaf;
}
void BST::inorder_print(node* leaf)
{
	if (leaf == NULL)
		return;
	else
	{
		inorder_print(leaf->left);
		cout << leaf->data << " " << endl;
		inorder_print(leaf->right);
	}
}
void BST::preorder_print(node* leaf)
{
	if (leaf == NULL)
	{
		return;
	}
	else
	{
		cout << leaf->data << " " << endl;
		preorder_print(leaf->left);
		preorder_print(leaf->right);
	}
}
void BST::postorder_print(node* leaf)
{
	if (leaf == NULL)
	{
		return;
	}
	else
	{
		postorder_print(leaf->left);
		postorder_print(leaf->right);
		cout << leaf->data << " " << endl;
	}
}
void BST::Print_Range(node* leaf, int k1, int k2)
{
	if (leaf == NULL)
		return;
	if (k1 < leaf->data)

		Print_Range(leaf->left, k1, k2);

	if (k1 <= leaf->data && k2 >= root->data)
	{

		cout << leaf->data << "  " << endl;

	}

	if (k2 > leaf->data)
		Print_Range(leaf->right, k1, k2);
}
/*void BST::Search(node* leaf, int key)
{
	if (leaf == NULL)
		return;



	if (key < leaf->data )
	{
		//cout << leaf->data << " Found on left node of the tree \n";
		return Search(leaf->left, key);
		if (key == leaf->left->data)
		{
			cout << leaf->data << " Found on left node of the tree \n";
			return Search(leaf->left, key);
		}
	}

	if (key > leaf->data && key == leaf->right->data)
	{
		//cout << leaf->data << " Found on right node of the tree \n";
		return Search(leaf->right, key);
		if (key == leaf->right->data)
		{
			cout << leaf->data << " Found on right node of the tree \n";
			return Search(leaf->right, key);
		}
	}

	
	if (key < leaf->data && key != leaf->left->data)
		cout << key << " Node not found!!! \n";
	if (key > leaf->data && key != leaf->right->data)
		cout << key << " Node not found!!! \n";
	/*if (key == leaf->data)
		cout << key << " Is the root of the tree \n";
}*/
node* BST::Search(node* leaf,int  key)
{
	if (leaf == NULL || leaf->data == key)
	{
		cout << "Node found on tree \n" << leaf->data << endl;
		return leaf;
	}
		
	if (leaf->data < key)
		return Search(leaf->right, key);
	
	return Search(leaf->left, key);
}
node* BST::Find_Min(node* leaf)
{
	if (leaf == NULL)
		return NULL;
	else if (leaf->left == NULL)
	{
		cout << leaf->data << endl;
		return leaf;

	}

	else
		return Find_Min(leaf->left);
}
node* BST::Find_Max(node* leaf)
{
	if (leaf == NULL)
	{
		return NULL;
	}
	else if (leaf->right == NULL)
	{
		cout << leaf->data << endl;
		return leaf;
	}
	else
		return Find_Max(leaf->right);
}
void BST::Second_Largest(node* leaf, int& c)
{
	if (leaf == NULL || c >= 2)
		return;
	Second_Largest(leaf->right, c);
	c++;
	if (c == 2)
	{
		cout << "The second largest element in the bst is  " << leaf->data << endl;
		return;
	}
	Second_Largest(leaf->left, c);
}
void BST::Third_Laragest(node* leaf, int& x)
{
	if (leaf == NULL || x >= 3)
		return;
	Third_Laragest(leaf->right, x);
	x++;
	if (x == 3)
	{
		cout << "The third largest element in the bst is  " << leaf->data << endl;
		return;
	}
	Third_Laragest(leaf->left, x);

}
void BST::Second_Smallest(node* leaf, int& x)
{
	if (leaf == NULL || x >= 2)
		return;
	Second_Smallest(leaf->left, x);
	x++;
	if (x == 2)
	{
		cout << "The second smallet element in the list is  " << leaf->data << endl;
		return;
	}
	Second_Largest(leaf->right, x);
}
void BST::Third_Smallest(node* leaf, int& x)
{
	if (leaf == NULL || x >= 3)
		return;
	Third_Smallest(leaf->left, x);
	x++;
	if (x == 3)
	{
		cout << "The third smallest element in the bst is  " << leaf->data << endl;
		return;
	}
	Third_Smallest(leaf->right, x);

}
node* BST::Delete_Node(node* leaf, int x)
{
	if (leaf == NULL)
		return NULL;
	else if (x < leaf->data)
	{
		leaf->left = Delete_Node(leaf->left, x);
	}
	else if (x > leaf->data)
	{
		leaf->right = Delete_Node(leaf->right, x);
	}

	//No child

	else
	{
		if (leaf->right == NULL && leaf->left == NULL)
		{
			delete leaf;
			leaf = NULL;
		}

		//One Child
		if (leaf->right == NULL)
		{
			node* temp = leaf;
			leaf = leaf->left;
			delete temp;
		}
		if (leaf->left == NULL)
		{
			node* temp = leaf;
			leaf = leaf->right;
			delete temp;
		}

		//Two Child

		else
		{
			node* temp = Find_Max(leaf->left);
			leaf->data = temp->data;
			leaf->left = Delete_Node(leaf->left, x);
		}
	}

	return leaf;

}
int BST::size(node* leaf)
{
	if (leaf == NULL)
	{
		return 0;
	}
	else
	{
		return(size(leaf->left) + 1 + size(leaf->right));
	}
}
void BST::insert(int x)
{
	root = insert(x, root);
}
void BST::inorder_print()
{
	inorder_print(root);
}
void BST::preorder_print()
{
	preorder_print(root);
}
void BST::postorder_print()
{
	postorder_print(root);
}
void BST::Search(int key)
{
	root=Search(root, key);
}
void BST::Find_Min()
{
	root = Find_Min(root);
}
void BST::Find_Max()
{
	root = Find_Max(root);
}
void BST::Print_second_Largest_in_List(node* leaf)
{
	int x = 0;
	Second_Largest(leaf, x);
}
void BST::Print_third_Laragest_in_the_List(node* leaf)
{
	int x = 0;
	Third_Laragest(leaf, x);
}
void BST::Print_Second_Smallest_in_the_list(node* leaf)
{
	int x = 0;
	Second_Smallest(leaf, x);
}
void BST::Print_Third_Smallest_in_the_list(node* leaf)
{
	int x = 0;
	Third_Smallest(leaf, x);
}
void BST::EALandS()
{
	Print_second_Largest_in_List(root);
	Print_third_Laragest_in_the_List(root);
	Print_Second_Smallest_in_the_list(root);
	Print_Third_Smallest_in_the_list(root);
}
void BST::size_print()
{
	cout << "Size of bst is \n";
	cout << size(root);
}
void BST::Delete_Node(int x)
{
	root = Delete_Node(root, x);
}
void BST::Display_Range(int k1, int k2)
{

	Print_Range(root, k1, k2);
}
int main()
{
	BST bst;
	bst.insert(20);
	bst.insert(15);
	bst.insert(10);
	bst.insert(25);
	bst.insert(30);
	bst.insert(12);
	bst.insert(22);
	cout << "Inorder arrangement of tree is \n";
	bst.inorder_print();
	//cout << endl;
	//cout << endl;
	//cout<<"The the largest number in the tree is \n";
	//bst.Find_Max();
	/*cout << endl;
	cout << endl;*/
	bst.Delete_Node(25);
	cout << endl;
	cout << endl;
	bst.inorder_print();
	//bst.Search(30);
	/*cout << "The smallest number in the tree is \n";
	bst.Find_Min();
	cout << endl;
	cout << endl;*/
	/*cout << endl;
	cout << endl;
	cout << "Pre-order arrangement of tree is \n";
	bst.preorder_print();
	cout << endl;
	cout << endl;
	cout << "Post-order arrangemnet of the tree is \n";
	bst.postorder_print();*/
	/*cout << endl;
	cout << endl;
	bst.EALandS();*/
	cout << endl;
	cout << endl;
	//cout << "The arrangede linked list is \n";
	//bst.Display_Range(10,20);
	cout << endl;
	cout << endl;
	//bst.size_print();



	return 0;
}