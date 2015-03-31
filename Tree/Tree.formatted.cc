#include <iostream>
#include "GenericList.cc"
using namespace std;


//Templates


class Tree
{
	private:
		struct TreeNode
		{
			char data;
			TreeNode* left;
			TreeNode* right;
		};

		TreeNode *root;	// the root of the tree
		void InOrder(TreeNode* n)
		{
			if(n != NULL)
			{
				InOrder(n->left);
				cout << n->data;
				InOrder(n->right);
			}
		}

		void PreOrder(TreeNode* n)
		{
			if(n != NULL)
			{
				cout << n->data;
				PreOrder(n->left);
				PreOrder(n->right);
			}
		}

		void PostOrder(TreeNode* n)
		{
			if(n != NULL)
			{
				PostOrder(n->left);
				PostOrder(n->right);
				cout << n->data;
			}
		}

		void ReverseOrder(TreeNode* n)
		{
			if(n != NULL)
			{
				ReverseOrder(n->right);
				cout << n->data;
				ReverseOrder(n->left);
			}
		}

		void PrintTree(TreeNode* n, int level)
		{
			if(n == NULL)
				return;

			PrintTree(n->right, level + 1);
			for(int i = 0; i < level; i++)
				cout << "   "; // 3 spaces
			cout << n->data << endl;
			PrintTree(n->left, level + 1);
		}

	public:
		// constructor
		Tree()
		{
			root = NULL;
		}

		void InsertIntoTree(char data)
		{
			if(root == NULL)
			{
				root = new TreeNode;
				root -> data = data;
			}

			else
			{
				TreeNode *curr = root;
				while(true)
				{
					if(data < curr->data)
					{
						if(curr->left == NULL)
						{
							curr -> left = new TreeNode;
							curr -> left -> data = data;
							break;
						}

						else
						{
							curr = curr->left;
						}
					}
					else
					{
						if(curr->right == NULL)
						{
							curr -> right = new TreeNode;
							curr -> right -> data = data;
							break;
						}

						else
						{
							curr = curr-> right;
						}
					}
				}
			}
		}
		void InOrder()
		{
			InOrder(root);
			cout << endl;
		}
		void PostOrder()
		{
			PostOrder(root);
			cout << endl;
		}
		void PreOrder()
		{
			PreOrder(root);
			cout << endl;
		}
		void ReverseOrder()
		{
			ReverseOrder(root);
			cout << endl;
		}
		void PrintTree()
		{
			PrintTree(root, 0);
			cout << endl;
		}
};


int main()
{
	char Line[MAX_SIZE];
	while(cin.getline(Line, MAX_SIZE))
	{
		Tree tree;
		for(int i = 0; i < cin.gcount() - 1; i++)
		{
			tree.InsertIntoTree(Line[i]);
		}
		cout << "       PreOrder: ";
		tree.PreOrder();

		cout << "        InOrder: ";
		tree.InOrder();

		cout << "      PostOrder: ";
		tree.PostOrder();

		cout << "Reverse Inorder: ";
		tree.ReverseOrder();

		tree.PrintTree();
	}
}



