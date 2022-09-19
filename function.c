#include <stdlib.h>
#include <emscripten.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "formatting.h"
#include "function.h"
#include "classes.h"


EMSCRIPTEN_KEEPALIVE
int Add(int value1, int value2)
{
    return (value1 + value2);
}

EMSCRIPTEN_KEEPALIVE
int Substract(int value1, int value2)
{
    return value1-value2;
}

EMSCRIPTEN_KEEPALIVE
int Multiply(int value1, int value2){
    return value1*value2;
}

EMSCRIPTEN_KEEPALIVE
float Divide(int value1, int value2)
{
    return value1/value2;
}

EMSCRIPTEN_KEEPALIVE
bool RelationalOperationsTest(int value1, int value2)
{
    if (value1 == value2 || value1 != value2 || value1 >= value2 && value1 > value2 )
        return true;
    return false;
}

EMSCRIPTEN_KEEPALIVE
bool LogicalOperatorsTest(bool value1, bool value2)
{
    if (!(value1 && value2) || value1 || value2)
        return true;
    return false;
}