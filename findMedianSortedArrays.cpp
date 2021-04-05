#include<iostream>
#include<vector>
#include<set>
using namespace std;

//�ϲ���������
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int len1 = nums1.size();
	int len2 = nums2.size();
	if (len1 == 0)  //���nums1Ϊ�գ�����nums2����λ��
	{
		if (len2 % 2 == 0)
		{
			if (len2 == 1)
				return (nums2[len2 / 2 - 1] + nums2[len2 / 2]) / 2.0;
		}
		else
			return nums2[len2 / 2];
	}
	if (len2 == 0)   //���nums2Ϊ�գ�����nums1����λ��
	{
		if (len1 % 2 == 0)
		{
			if (len1 == 1)
			    return (nums1[len1 / 2 - 1] + nums1[len1 / 2]) / 2.0;
		}
		else
			return nums1[len1 / 2];
	}
	int len = len1 + len2;
	vector<int>nums(len); //����ָ��Ԫ�ظ�����Ҫ��������������
	int i =0, j = 0;
	int count = 0;
	while (count != len)
	{
		if (i == len1)
		{
			while (j != len2)
			{
				nums[count++] = nums2[j++];
			}
			break;
		}
		if (j == len2)
		{
			while (i != len1)
			{
				nums[count++] = nums1[i++];
			}
			break;
		}
		if (nums1[i] < nums2[j])
		{
			nums[count++] = nums1[i++];
		}
		else
		{
			nums[count++] = nums2[j++];
		}
	}
	if (len % 2 == 0)
		return (nums[len / 2 - 1] + nums[len / 2]) / 2.0;
	else
		return nums[len / 2];
}
int main()
{
	vector<int> v1 = { 1,2};
	vector<int> v2 = { 3,4 };
	double mid = findMedianSortedArrays(v1, v2);
	cout << "��λ����" << mid << endl;

	system("pause");
	return 0;
}