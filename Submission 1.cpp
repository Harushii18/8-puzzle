
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string strDigits;
    cin>>strDigits;
    
    for (int i=0;i<strDigits.length();i++){
        cout<<strDigits[i];
        if ((i+1%3!=0)){
            cout<<' ';
        }
        if (((i+1) % 3==0) && (i>0)){
            cout<<endl;
        }
    }
    
    return 0;
}
