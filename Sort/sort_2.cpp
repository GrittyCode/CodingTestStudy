#include <iostream>
#include <queue>
#define MAX 10000

using namespace std;

int sort_list[MAX]; 

void Merge(int list[], int left, int right) 
{
    int mid = (left + right) / 2;
    int k = left;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (list[i] <= list[j])
        {
            sort_list[k++] = list[j++];
        }
        else
        {
            sort_list[k++] = list[i++];
        }
    }

    //³²Àº ¼ö Á¤¸®
    if (i > mid)
    {
        for (int l = j; l <= right; l++)
        {
            sort_list[k++] = list[l];
        }
    }
    else
    {
        for (int l = i; l <= mid; l++)
        {
            sort_list[k++] = list[l];
        }
    }

    for (int l = left; l <= right; ++l)
        list[l] = sort_list[l];
}

void MergeSort(int list[], int left, int right)
{
    if (left < right) //ì¢…ë£Œì¡°ê±´
    {
        int mid = (left + right) / 2;
        MergeSort(list, left, mid);
        MergeSort(list, mid + 1, right);
        Merge(list, left, right);
    }
}

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    Init();

    int iter;
    cin >> iter;

    int array[iter];

    int temp;

    for (int i = 0; i < iter; ++i)
    {
        cin >> temp; 
        array[i] = temp;
    }

    MergeSort(array, 0, iter - 1); // 0~ iter - 1ê¹Œì?? ? •? ¬
    cout << "<<º´ÇÕÁ¤·Ä ³»¸²Â÷¼ø>>\n";

    for (int i = 0; i < iter; ++i)
    {
        cout << array[i] << " ";
    }

    cout << endl;

    return 0;
}