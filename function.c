#include <stdlib.h>
 #include <emscripten.h>
 #include <string.h>
 #include <stdio.h> 
#include <math.h>
EMSCRIPTEN_KEEPALIVE
 int Add(int value1, int value2) {
   return (value1 + value2);
 }


 int countDigits(int value) //Functions for help
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



EMSCRIPTEN_KEEPALIVE // Int format
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

int getPositionOfDecimalPoint(char* str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '.')
            return i;
    }
}


 EMSCRIPTEN_KEEPALIVE //Float format
char* floatFormat(char* value, int desiredDecimals){
    int length= strlen(value);
    int positionOfDot = getPositionOfDecimalPoint(value);

    //case 0 decimals
    if (desiredDecimals==0)
    {
        char* res = malloc(20);
        strncpy(res, value, positionOfDot);
        return res;
    }


    //case desiredNumber < actualNumber
    int numOfDecimals = strlen(value) - positionOfDot-1;
    if (desiredDecimals < numOfDecimals)
    {
        char* res = malloc(40);
        strncpy(res, value, positionOfDot+desiredDecimals);
        return res;
    }


    //case desiredNumber > actualNumber
    int toBeAdded=desiredDecimals-numOfDecimals;

    char* res = malloc(30);
        
    strcat(res, value);

    for (int i=0;i<toBeAdded; i++)
        strcat(res, "0");
    
    return res;
    
}