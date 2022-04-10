/*
범위 구하기, 겹쳐지는 범위에서의 최소값과 최대값들은 표시한다. 만약 끊겨져 있는 경우 같은 방식으로 최소값과 최대값을 표시한다.
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
    return A.start < B.start; //start 좌표를 기준으로 정렬 해준다.
}


void AreaPrint(Dir arr[], int arr_size)
{
    //정렬된 상태의 Dir 배열을 받아온다.
    int start,end;
    start = arr[0].start;
    end = arr[0].end;

    for(int i = 1; i < arr_size; ++i)
    {
        if(arr[i].start > end) //다음 구역의 시작 부분이 현재 끝 부분보다 크다면 같은 범위에 존재 하지 않는다고 본다.
        {
            cout << start << " " << end << endl;
            start = arr[i].start;
            end = arr[i].end;
        }
        else if(arr[i].end > end) //만약, 다음 원소의 시작 부분이 범위에 포함하고 그 원소의 끝점이 이전 끝 점보다 클 경우 end를 갱신해준다.
        {
            end = arr[i].end;
        }
    }

    //마지막 갱신된 구역을 출력해준다.
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
    cout << "<< 범위 출력 >> \n";
    AreaPrint(dirArray,iter);

    return 0;
}