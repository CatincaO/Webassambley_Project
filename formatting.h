#include <stdlib.h>
#include <emscripten.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

int countDigits(int value)
{
    int res = 0;
    while (value > 0)
    {
        value /= 10;
        res++;
    }
    return res;
}

char *invalidLength(int count, char c)
{
    char *res = (char *)malloc(sizeof(char) * (count + 1));
    for (int i = 0; i < count; ++i)
    {
        res[i] = c;
    }

    return res;
}

EMSCRIPTEN_KEEPALIVE // Int format
    char *
    formatInt(float value, int digits)
{

    if ((int)value == 0)
        return "0";

    // value<digits

    int digitCount = countDigits(value);

    if (digitCount <= digits)
    {
        char *result = (char *)malloc(sizeof(char) * (digits + 1)); // digits+1 = (+-)digits

        sprintf(result, "%d", (int)value);

        return result;
    }

    // value>digits

    return invalidLength(digits, '#');
}

int getPositionOfDecimalPoint(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '.')
            return i;
    }
    return 0;
}

char *removeCharactersFromString(char *str, int length, int numToDelete)
{
    char *res = malloc(50);
    int temp = length - numToDelete;
    strncpy(res, str, temp);
    return res;
}

char *addCharsToString(char *str, char *toBeAdded, int num)
{
    char *res = malloc(30);

    strcat(res, str);

    for (int i = 0; i < num; i++)
        strcat(res, toBeAdded);

    return res;
}

EMSCRIPTEN_KEEPALIVE // Float format
    char *
    floatFormat(char *value, int desiredDecimals)
{
    int length = strlen(value);
    int positionOfDot = getPositionOfDecimalPoint(value);

    // case 0 decimals
    if (desiredDecimals == 0)
    {
        return removeCharactersFromString(value, length, length - positionOfDot);
    }

    // case desiredNumber < actualNumber
    int numOfDecimals = strlen(value) - positionOfDot - 1;
    if (desiredDecimals < numOfDecimals)
    {
        return removeCharactersFromString(value, length, numOfDecimals - desiredDecimals);
    }

    // case desiredNumber > actualNumber
    int toBeAdded = desiredDecimals - numOfDecimals;

    return addCharsToString(value, "0", toBeAdded);
}