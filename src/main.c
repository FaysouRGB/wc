#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "wc.h"

int main(int argc, char *argv[])
{
    struct wc_results results = wc_init(argc, argv);
    wc_execute(&results);
    wc_print_results(&results);
}
