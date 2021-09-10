
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string strDigits, strMove;
    cin>>strDigits;
    cin>>strMove;
    string strFinal[3][3];
    
    int x,y;
    //put into array
    int count=0;
     for (int r=0;r<3;r++){
         for (int c=0;c<3;c++){
              //store position of #
             if (strDigits[count]=='#'){
                 x=r;
                 y=c;
             }
             
             
             //store in array
             strFinal[r][c]=strDigits[count];
             count++;
             
            
         }
    }
    
    string tempVal;
    if (strMove=="UP"){
        //WORKS PERFECTLY
        tempVal=strFinal[x-1][y];
        strFinal[x][y]=tempVal;
        strFinal[x-1][y]='#';
    }else if (strMove=="LEFT"){
       tempVal=strFinal[x][y-1];
        strFinal[x][y]=tempVal;
        strFinal[x][y-1]='#'; 
        
    }else if (strMove=="DOWN"){
        tempVal=strFinal[x+1][y];
        strFinal[x][y]=tempVal;
        strFinal[x+1][y]='#'; 
        
    }else if (strMove=="RIGHT"){
        tempVal=strFinal[x][y+1];
        strFinal[x][y]=tempVal;
        strFinal[x][y+1]='#'; 
        
    }
    
    
    string strCost="1";
    //output cost
    cout<<strCost<<endl;
    
    
    //output array
     for (int r=0;r<3;r++){
         for (int c=0;c<3;c++){
             //display with a space
              cout<<strFinal[r][c]+ ' ';
         }
         cout<<endl;
    }

    return 0;
}
