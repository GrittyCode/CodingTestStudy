#include<iostream>
#include<vector>

using namespace std;

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void Insertion_Sort(vector<int> v)
{
    for(int i = 1; i < v.size(); ++i)
    {
        int temp = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] < temp) //j?? 
        {
            v[j+1] = v[j];
            j--;
            v[j+1] = temp;
        }
    }

    cout << "<< 선택정렬로 내림차순 >>\n";
    for(int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << ' ';    
    }
    cout << '\n';
}




int main()
{
    Init();
    int iter;
    cin >> iter;
    int temp;
    vector<int> v;
    for(int i = 0; i < iter; ++i)
    {
        cin >> temp;    
        v.push_back(temp);
    }

    Insertion_Sort(v);

    return 0;
}