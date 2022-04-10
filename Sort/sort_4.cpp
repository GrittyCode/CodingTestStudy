/*
���� ���ϱ�, �������� ���������� �ּҰ��� �ִ밪���� ǥ���Ѵ�. ���� ������ �ִ� ��� ���� ������� �ּҰ��� �ִ밪�� ǥ���Ѵ�.
*/
#include<iostream>
#include<algorithm>

using namespace std;

class Dir
{
public:
    int start;
    int end;

    Dir(int p_start, int p_end) : start(p_start), end(p_start)
    {

    }

    Dir()
    {

    }
};

bool compare(Dir A, Dir B)
{
    return A.start < B.start; //start ��ǥ�� �������� ���� ���ش�.
}


void AreaPrint(Dir arr[], int arr_size)
{
    //���ĵ� ������ Dir �迭�� �޾ƿ´�.
    int start,end;
    start = arr[0].start;
    end = arr[0].end;

    for(int i = 1; i < arr_size; ++i)
    {
        if(arr[i].start > end) //���� ������ ���� �κ��� ���� �� �κк��� ũ�ٸ� ���� ������ ���� ���� �ʴ´ٰ� ����.
        {
            cout << start << " " << end << endl;
            start = arr[i].start;
            end = arr[i].end;
        }
        else if(arr[i].end > end) //����, ���� ������ ���� �κ��� ������ �����ϰ� �� ������ ������ ���� �� ������ Ŭ ��� end�� �������ش�.
        {
            end = arr[i].end;
        }
    }

    //������ ���ŵ� ������ ������ش�.
    cout << start << " " << end;
}

int main()
{
    int iter;
    cin >> iter;
    Dir dirArray[iter];

    for(int i = 0; i < iter; ++i)
    {
        int start,end;
        cin >> start >> end;
        dirArray[i].start = start;
        dirArray[i].end = end;
    }

    sort(dirArray,dirArray + iter, compare);
    cout << "<< ���� ��� >> \n";
    AreaPrint(dirArray,iter);

    return 0;
}