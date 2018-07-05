#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

map<int,string> keys;

int Recursion(int array[], int current_length, string output[],int length)
{
    int i,count=0;
    const char DataArray[10][5] = {"", "", "ABC", "DEF", "GHI", "JKL","MNO", "PQRS", "TUV", "WXYZ"};
 	
    if (current_length==length)
    {
        return count;
    }
    
    for(i=0; i<strlen(DataArray[array[current_length]]); i++)
    {
        count++;
        output[current_length] = DataArray[array[current_length]][i];
        Recursion(array, current_length+1, output,length);
       
        if(array[current_length] == 0 || array[current_length] == 1)
        {
            return 1;
        }
       return count;
    }
}

int keypad(int num, string output[]){
   if(num>=1 && num<=1000000)
   {   int array[100];
        int i=0;
     
     while(num>0){
       
     int rem=num%10;
     array[i]=rem;
     num=num/10;
       i++;
     }
    return Recursion(array, 0, output,i);
 
   }
}

int main()
{
    string alpha[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    for(int i = 2; i <= 9; i++)
    {
        keys[i] = alpha[i-2];
    }
    int num;
    cin >> num;
    int total = 1;
    int pos = num%10;
    int rem = num/10;
    for(int i = 0; i < to_string(num).size(); i++)
    {
        total *= keys[pos].size();
        pos = rem%10;
        rem /= 10;
    }
    
    string* output = new string[total];
    
    int count = keypad(num, output);
    
    for(int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}