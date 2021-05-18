#include<iostream>
using namespace std;
#include<vector>

typedef struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int n) :val(n), left(NULL), right(NULL) {}
}TreeNode;

//������������
TreeNode* CreatBiTree(vector<int> arr, int start) {
	if (arr[start] == '-1')
		return NULL;
	TreeNode* root = new TreeNode(arr[start]);
	int left_index = 2 * start + 1;
	int right_index = 2 * start + 2;
	if (left_index > arr.size() - 1)
		root->left = NULL;
	else
		root->left = CreatBiTree(arr, left_index);
	if (right_index > arr.size() - 1)
		root->right = NULL;
	else
		root->right = CreatBiTree(arr, right_index);
	return root;
}
//�ж��Ƿ�Ϊ����
bool DFS(TreeNode* A, TreeNode* B) {
	if (!A || !B) {
		if (!B) return true;  //B�Ѿ�Ϊ�գ�˵��B�Ѿ������꣬˵��BΪA���ӽṹ
		else return false;   //A�����꣬Bû�б����꣬˵��B��ΪA���ӽṹ
	}
	if (A->val != B->val) return false;  //AB�ڵ㲻��ȣ�B��ΪA���ӽṹ
	return DFS(A->left, B->left) && DFS(A->right, B->right);  //�ݹ��ж�A�����������������Ƿ����
}
bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
	if (!pRoot1 || !pRoot2) return false;  //�жϿ���
	return DFS(pRoot1, pRoot2) || isSubtree(pRoot1->left, pRoot2) || isSubtree(pRoot1->right, pRoot2);
}
//��ӡ
void PrintBitree(TreeNode* root) {
	if (!root) return;
	cout << root->val << "->";
	PrintBitree(root->left);
	PrintBitree(root->right);
}
int main() {
	int a1[] = { 8,8,-1,9,-1,2,-1,5 }; 
	int len1 = sizeof(a1) / sizeof(*a1);
	vector<int> arr1(a1, a1 + len1);
	int a2[] = { 8,8,-1,9,-1,2 };
	int len2 = sizeof(a2) / sizeof(*a2);
	vector<int> arr2(a2, a2 + len2);
	TreeNode* root1 = CreatBiTree(arr1, 0);
	TreeNode* root2 = CreatBiTree(arr2, 0);
	//PrintBitree(root1);
	//cout << endl;
	//PrintBitree(root2);
	if (isSubtree(root1, root2))
		cout << "root2��root1������" << endl;
	else
		cout << "root2����root1������" << endl;
	return 0;
}