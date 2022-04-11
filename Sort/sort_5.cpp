#include <iostream>
#include<algorithm>

using namespace std;

/*

mcss3(a, low, high) if(low == high) return a[low] mid = (mid+high)/2
 //���ʿ��� ��ġ�� �κ� ������ �ִ��� ���ϱ�
 left_sum = mcss3(a, low, mid) right_sum = mcss3(a, mid+1, high)
 //���ʿ� ��ġ�� �κб����� �ִ��� two_sided_sum ���ϱ�
 //a[i...mid] ��� �� �ִ��� lsum ���ϱ�
 lsum = sum = a[mid] for i=mid-1, mid-2, ..., low
 sum += a[i] if(sum > lsum) lsum = sum
 //a[mid+1...j] ��� �� �ִ��� rsum ���ϱ�
 rsum = sum = a[mid+1] for i=mid+2, mid+3, ..., high
 sum += a[i] if(sum > rsum) rsum = sum
 two_sided_sum = lsum + rsum
 return max(left_sum, right_sum, two_sided_sum


*/


int mcss3(int array[], int low, int high)
{
    if(low == high) return array[low]; //���� ����

    int mid = (low + high) / 2;
    int left_sum = mcss3(array,low, mid);
    int right_sum = mcss3(array,mid + 1, high);
    //left,right �κ��� �迭�� ���� �����ش�. ���������

    //�� �ʿ� ��ġ�� �κ� ������ �ִ��� ���ϱ�
    //���� �κ� �迭�� ���ϱ�
    int sum = array[mid];
    int lsum = sum;
    for(int i = mid - 1; i >= low; --i)
    {
        sum += array[i];
        if(sum > lsum) lsum = sum;
    }
    sum = array[mid + 1];

    //������ �κ� �迭 �� ���ϱ�
    int rsum = sum;
    for(int i = mid + 2; i <= high; ++i)
    {
        sum += array[i];
        if(sum > rsum) rsum = sum;
    }
    int two_sided_sum = lsum + rsum;

    int bigsum = max(left_sum,right_sum);

    return max(bigsum,two_sided_sum);
}
int main()
{
    int iter;
    cin >> iter;
    int array[iter];
    for(int i = 0; i < iter; ++i)
    {
        int temp;
        cin >> temp;
        array[i] = temp;
    }

    int maxSum = mcss3(array,0,iter - 1);

    cout << "�Էµ� �迭�� �ִ� ���� �κ� ���� ���� : " << maxSum << "�Դϴ�." << endl;
    return 0;
}