
#include <iostream>
#include <string.h>

using namespace std;

void displayArray(string strFinal[][3]){
     //output array
     for (int r=0;r<3;r++){
         for (int c=0;c<3;c++){
             //display with a space
              cout<<strFinal[r][c]+ ' ';
         }
         cout<<endl;
    }
    
}

void swapMovements(string strFinal[][3], int x, int y, string strMove){
      
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
    
    
    
}

void calculateCost(){
    string strCost="1";
    //output cost
    cout<<strCost<<endl;
}

void determineMovements(int r, int c){
    //UP
    if (r>0){
        cout<<"UP"<<endl;
    }
    
    //DOWN
    if (r<2){
         cout<<"DOWN"<<endl;
    }
    
    //LEFT
    if (c>0){
        cout<<"LEFT"<<endl;
    }
    
    //RIGHT
    if (c<2){
        cout<<"RIGHT"<<endl;
    }
    
}
int main()
{
    string strDigits, strMove;
    cin>>strDigits;
   // cin>>strMove;
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
    
    
    //swap the Movements
  //  swapMovements(strFinal, x, y, strMove);
    
    determineMovements(x,y);
    
//    calculateCost();
    
   // displayArray(strFinal);
   

    return 0;
}
