//퀵정렬 -> 피벗값을 설정한 후, i와j를 선언 i는 low값 j는 high값으로 선정한 후, 피벗값보다 작은 값들을 j로 왼쪽으로 가면서 찾고
//피벗값보다 큰 값들은 i로 오른쪽으로 가면서 찾은 후, 서로 위치를 바꿔준다. 이렇게 진행하면, 작은 값들은 배열의 왼쪽 큰 값들은 배열의
//오른쪽에 저장되어지는데 이 때, i와 j가 서로 크로스 한 경우, j와 pivot값을 바꿔주면 배열이 정렬 된다.

//퀵 정렬은 큰 배열에서 작은 배열로 재귀 진행하면서 배열의 모든 수를 오름차순 혹은 내림차순으로 정렬해나간다.
//종료 조건의 경우는 low와 high가 같거나 low가 high보다 클 경우에 재귀를 종료해준다.

#include <iostream>

using namespace std;

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int Partition(int arr[], int low, int high)
{
    // pivot값은 첫번재 배열의 인덱스로 지정
    int i = low;      //++로 먼저 더해줄꺼기 때문에 low + 1로 지정 X
    int j = high + 1; //--로 먼저 빼줄거기 때문에 high + 1로 high부터 검사 시작
    while (true)      //종료조건이 나올 때 까지 무한 루프
    {
        while (arr[++i] < arr[low]) //왼쪽 배열 검사
        {
            if (i == high) break; //왼쪽 배열에서 큰 수가 나올때 까지 i를 더해준다.
        }
        
        while (arr[--j] > arr[low] ) //오른쪽 배열 검사
        {
            if(j == low) break;
        }
        
        if(i >= j) break; //i와 j가 크로스 할 경우 종료

        //크로스가 아닐 경우 진행
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;  
    }


    //low와 j를 환
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j; //pivot값
}

void QuickSort(int arr[], int low, int high)
{
    if (low >= high) return; //종료조건

    int pivot = Partition(arr, low, high);
    //분할 재귀 방법 pivot값의 경우는 이미 자기 자신의 최적의 위치를 찾았다고 가정하므로 pivot값은 제외하고 진행(가장 중요!)
    QuickSort(arr,low, pivot - 1);
    QuickSort(arr,pivot + 1, high); 
}

int main()
{
    int iter;
    cin >> iter;
    int array[iter];

    for (int i = 0; i < iter; ++i)
    {
        int temp;
        cin >> temp;
        array[i] = temp;
    }

    QuickSort(array, 0, iter - 1);
    cout << "<< 퀵 정렬로 오름차순>>\n";

    for(int i = 0; i < iter; ++i)
    {
        cout << array[i] << " ";
    }
    return 0;
}