#include <stdlib.h>
 #include <emscripten.h>
 #include <string.h>
 #include <stdio.h> 

EMSCRIPTEN_KEEPALIVE
 int Add(int value1, int value2) {
   return (value1 + value2);
 }


 int countDigits(int value)
 {
    int res=0;
    while (value>0)
    {
        value/=10;
        res++;
    }
    return res;
 }
 
 

 char* invalidLength(int count, char c)
 {
     char* res = (char*)malloc(sizeof(char)*(count+1));
    for (int i=0;i<count;++i)
    {
        res[i]=c;
    }

    return res;
 }



EMSCRIPTEN_KEEPALIVE
 char* formatInput(float value, int digits)
 {

    int temp = (int)value;

    int digitCount=countDigits(value);
  
    //value == 0

    if (digitCount == 0)
        return "0";

    //value<digits

    char* result = (char*)malloc(sizeof(char)*(digits+1));//digits+1 = (+-)digits
    

    //value == digits


    sprintf(result, "%d", temp);

    if (digitCount <= digits)
        return result; 


    //value>digits
    
    return invalidLength(digits, '#');
    
    
    free(result);
 }