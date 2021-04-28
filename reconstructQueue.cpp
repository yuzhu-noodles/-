#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//��������ؽ�����
//�����д���˳���һȺ��վ��һ�����У����� people ��ʾ������һЩ�˵����ԣ���һ����˳�򣩡�ÿ�� people[i] = [hi, ki] ��ʾ�� i ���˵����Ϊ hi ��ǰ�� ���� �� ki ����ߴ��ڻ���� hi ���ˡ�
//�������¹��첢������������ people ����ʾ�Ķ��С����صĶ���Ӧ�ø�ʽ��Ϊ���� queue ������ queue[j] = [hj, kj] �Ƕ����е� j ���˵����ԣ�queue[0] �����ڶ���ǰ����ˣ���


//�������Ȱ����������Ȼ����ͨ��K���в���
class Solution {
public:
	static bool cmp(const vector<int> a, const vector<int> b)
	{
		if (a[0] == b[0]) return a[1] < b[1];
		return a[0] > b[0];
	}
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
	{
		sort(people.begin(), people.end(), cmp);
		vector<vector<int>> ret;
		for (int i = 0; i < people.size(); i++)
		{
			int index = people[i][1];
			ret.insert(ret.begin() + index, people[i]);
		}
		return ret;
	}
};
int main()
{
	int arr[6][2] = { {7,0},{4,4},{7,1},{5,0},{6,1},{5,2} };
	vector<vector<int>> people(6,vector<int>(2));
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			people[i][j] = arr[i][j];
		}
	}
	Solution s;
	vector<vector<int>> ret = s.reconstructQueue(people);
	for (int i = 0; i < ret.size(); i++)
	{
		cout << "[";
		for (int j = 0; j < ret[i].size(); j++)
		{
			cout << ret[i][j]<<" ";
		}
		cout << "]";
	}
	return 0;
}