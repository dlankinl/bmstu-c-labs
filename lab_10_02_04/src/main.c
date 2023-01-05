#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "constants.h"
#include "list_t.h"
#include "cmd_handler.h"


int main(void)
{
    size_t rc = EXIT_SUCCESS;
    char cmd[MAX_STR_LEN];
    if (!fgets(cmd, MAX_STR_LEN, stdin))
        return INCORRECT_INPUT;
    
    if (strcmp(cmd, "out") == 0)
        rc = cmd_out();
    else if (strcmp(cmd, "mul") == 0)
        rc = cmd_mul();
    else if (strcmp(cmd, "sqr") == 0)
        rc = cmd_sqr();
    else if (strcmp(cmd, "div") == 0)
        rc = cmd_div();
    else
        rc = UNKNOWN_CMD;

    return rc;
}