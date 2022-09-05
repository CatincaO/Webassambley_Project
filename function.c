#include <stdlib.h>
#include <emscripten.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#include "formatting.h"
#include "function.h"
#include "classes.h"


EMSCRIPTEN_KEEPALIVE
int Add(int value1, int value2)
{
    return (value1 + value2);
}

