#include<iostream>
using namespace std;
#include<vector>
#include<queue>

typedef struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode,*BiTree;

void Init(BiTree* tree)
{
	(*tree) = NULL;
}
void Creat(BiTree* tree)
{
	int val;
	cin >> val;
	if (val == 0)
		*tree = NULL;
	else
	{
		*tree = (BiTree)malloc(sizeof(TreeNode));
		if (*tree == NULL)
			return;
		else
		{
			(*tree)->val = val;
			(*tree)->left = NULL;
			(*tree)->right = NULL;
			cout << "��ڵ�:";
			Creat(&(*tree)->left);
			cout << "�ҽڵ�:";
			Creat(&(*tree)->right);
		}
	}
}


vector<vector<int> > Print(TreeNode* pRoot) {

	vector<vector<int>> ret;
	if (pRoot == NULL)
		return ret;
	queue<TreeNode*> q;
	q.push(pRoot);
	while (q.size() != 0)
	{
		int  n = 0; //ÿ��Ԫ����(��0����)
		int qSize = q.size();
		vector<int> oneLeve;
		while (n++ < qSize) {
			TreeNode* temp = q.front();
			q.pop();
			oneLeve.push_back(temp->val);
			if (temp->left != NULL)
				q.push(temp->left);
			if (temp->right != NULL)
				q.push(temp->right);
		}

		ret.push_back(oneLeve);
	}
	return ret;
}
int main()
{
	TreeNode* tree;
	Init(&tree);
	cout << "��������ڵ㣺";
	Creat(&tree);

	vector<vector<int>> ret = Print(tree);
	for (int i = 0; i < ret.size(); i++)
	{
		for (int j = 0; j < ret[i].size(); j++)
		{
			cout << ret[i][j];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}