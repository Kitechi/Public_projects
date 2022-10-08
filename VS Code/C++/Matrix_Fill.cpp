#include <iostream>
using namespace std;
int matrix [4][4] ;///
int main()
{
    cout << " Enter elements of mtrix"<<endl;
    for (int i=0;i<4;i++)
    {
        for (int j=0;j< 4;j++)
        {
            cin>>matrix[i][j] ;
        }
        cout<<endl ;
    }
    return 0;
}