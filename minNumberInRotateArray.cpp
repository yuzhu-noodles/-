#include<iostream>
using namespace std;
#include<vector>

//���ַ�
int minNumberInRotateArray(vector<int> rotateArray)
{
	int left = 0;
	int right = rotateArray.size() - 1;
	while (left < right)
	{
		if (rotateArray[left] < rotateArray[right])
		{
			return rotateArray[left];
		}
		int mid = left + (right - left) / 2;
		if (rotateArray[left] < rotateArray[mid])  //����ǵ�������
		{
			left = mid + 1;
		}
		else if (rotateArray[mid] < rotateArray[right])    //�ұ��ǵ�������
		{
			right = mid;
		}
		else                                            //�����������ȷ����ֻ������ж�
		{
			left++;
		}
	}
	return rotateArray[left];
}

int main()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(1);
	v.push_back(2);
	cout << minNumberInRotateArray(v) << endl;
	system("pause");
	return 0;
}