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

 EMSCRIPTEN_KEEPALIVE //Float format

//  #include <math.h>

// float val = 37.777779;

// float rounded_down = floorf(val * 100) / 100;   /* Result: 37.77 */
// float nearest = roundf(val * 100) / 100;  /* Result: 37.78 */
// float rounded_up = ceilf(val * 100) / 100;      /* Result: 37.78 */

// char* floatFormat(float value, int decimals){
//     char* number = (char*)malloc(sizeof(char)*(20));
//     if(decimals == 0){
//         return (int) value;
//     }
//     int digitCount = pow(10, decimals);
//     float floatNumber = floorf(value * digitCount)/ digitCount;
//     gcvt(floatNumber, decimals, number);
//     return number;


// }

char* floatFormat(char* value, int decimals){
    char* number = (char*)malloc(sizeof(char)*(20));
    
    int digitCount = pow(10, decimals);
    float floatNumber = floorf(value * digitCount)/ digitCount;
    gcvt(floatNumber, decimals, number);
    
  
    if (decimals == 0){
        int temp = (int) floatNumber;
        sprintf(number, "%d", temp);
        return number;
        
    }
    
    for(int i = 0; i < decimals ; i++){
        strcat(number, "0");
    }
    return number;
}