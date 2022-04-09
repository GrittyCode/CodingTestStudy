//������ -> �ǹ����� ������ ��, i��j�� ���� i�� low�� j�� high������ ������ ��, �ǹ������� ���� ������ j�� �������� ���鼭 ã��
//�ǹ������� ū ������ i�� ���������� ���鼭 ã�� ��, ���� ��ġ�� �ٲ��ش�. �̷��� �����ϸ�, ���� ������ �迭�� ���� ū ������ �迭��
//�����ʿ� ����Ǿ����µ� �� ��, i�� j�� ���� ũ�ν� �� ���, j�� pivot���� �ٲ��ָ� �迭�� ���� �ȴ�.

//�� ������ ū �迭���� ���� �迭�� ��� �����ϸ鼭 �迭�� ��� ���� �������� Ȥ�� ������������ �����س�����.
//���� ������ ���� low�� high�� ���ų� low�� high���� Ŭ ��쿡 ��͸� �������ش�.

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
    // pivot���� ù���� �迭�� �ε����� ����
    int i = low;      //++�� ���� �����ٲ��� ������ low + 1�� ���� X
    int j = high + 1; //--�� ���� ���ٰű� ������ high + 1�� high���� �˻� ����
    while (true)      //���������� ���� �� ���� ���� ����
    {
        while (arr[++i] < arr[low]) //���� �迭 �˻�
        {
            if (i == high) break; //���� �迭���� ū ���� ���ö� ���� i�� �����ش�.
        }
        
        while (arr[--j] > arr[low] ) //������ �迭 �˻�
        {
            if(j == low) break;
        }
        
        if(i >= j) break; //i�� j�� ũ�ν� �� ��� ����

        //ũ�ν��� �ƴ� ��� ����
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;  
    }


    //low�� j�� ȯ
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j; //pivot��
}

void QuickSort(int arr[], int low, int high)
{
    if (low >= high) return; //��������

    int pivot = Partition(arr, low, high);
    //���� ��� ��� pivot���� ���� �̹� �ڱ� �ڽ��� ������ ��ġ�� ã�Ҵٰ� �����ϹǷ� pivot���� �����ϰ� ����(���� �߿�!)
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
    cout << "<< �� ���ķ� ��������>>\n";

    for(int i = 0; i < iter; ++i)
    {
        cout << array[i] << " ";
    }
    return 0;
}