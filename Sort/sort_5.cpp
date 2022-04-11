#include <iostream>
#include<algorithm>

using namespace std;

/*

mcss3(a, low, high) if(low == high) return a[low] mid = (mid+high)/2
 //한쪽에만 걸치는 부분 구간의 최대합 구하기
 left_sum = mcss3(a, low, mid) right_sum = mcss3(a, mid+1, high)
 //양쪽에 걸치는 부분구간의 최대합 two_sided_sum 구하기
 //a[i...mid] 모양 중 최대합 lsum 구하기
 lsum = sum = a[mid] for i=mid-1, mid-2, ..., low
 sum += a[i] if(sum > lsum) lsum = sum
 //a[mid+1...j] 모양 중 최대합 rsum 구하기
 rsum = sum = a[mid+1] for i=mid+2, mid+3, ..., high
 sum += a[i] if(sum > rsum) rsum = sum
 two_sided_sum = lsum + rsum
 return max(left_sum, right_sum, two_sided_sum


*/


int mcss3(int array[], int low, int high)
{
    if(low == high) return array[low]; //종료 조건

    int mid = (low + high) / 2;
    int left_sum = mcss3(array,low, mid);
    int right_sum = mcss3(array,mid + 1, high);
    //left,right 부분의 배열의 합을 구해준다. 재귀적으로

    //양 쪽에 걸치는 부분 구간의 최대합 구하기
    //왼쪽 부분 배열합 구하기
    int sum = array[mid];
    int lsum = sum;
    for(int i = mid - 1; i >= low; --i)
    {
        sum += array[i];
        if(sum > lsum) lsum = sum;
    }
    sum = array[mid + 1];

    //오른쪽 부분 배열 합 구하기
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

    cout << "입력된 배열의 최대 연속 부분 합의 값은 : " << maxSum << "입니다." << endl;
    return 0;
}