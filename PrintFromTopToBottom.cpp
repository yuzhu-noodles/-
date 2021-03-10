#include<iostream>
using namespace std;
#include<vector>
#include<queue>

typedef struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode, * BiTree;

void InitTree(BiTree* tree)
{
	(*tree) = NULL;
}

void CreatTree(BiTree* tree)
{
	int num;
	cin >> num;
	if (num == 0)
		tree = NULL;
	else
	{
		*tree = (TreeNode*)malloc(sizeof(TreeNode));
		if (*tree == NULL)
			return;
		else
		{
			(*tree)->data = num;
			(*tree)->left = NULL;
			(*tree)->right = NULL;
			cout << "��ڵ�:";
			CreatTree(&(*tree)->left);
			cout << "�ҽڵ�:";
			CreatTree(&(*tree)->right);
		}
	}
}

//�������������vector��
vector<int> PrintFromTopToBottom(TreeNode* root)
{
	queue<TreeNode*> q;
	vector<int> ret;
	if (root != NULL)
	{
		q.push(root);
	}
	while (!q.empty())
	{
		ret.push_back(q.front()->data);
		if (q.front()->left != NULL)
		{
			q.push(q.front()->left);
		}
		if (q.front()->right != NULL)
		{
			q.push(q.front()->right);
		}
		q.pop();
	}
	return ret;
}
void PrePrint(BiTree root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->data << " ";
	PrePrint(root->left);
	PrePrint(root->right);
}

int main()
{
	BiTree root;
	InitTree(&root);
	cout << "���ڵ㣺";
	CreatTree(&root);
	cout << "ǰ�������\n";
	PrePrint(root);
	vector<int> ret;
	ret = PrintFromTopToBottom(root);
	cout << "���������\n";
	for (int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << " ";
	}
	system("pause");
	return 0;
}