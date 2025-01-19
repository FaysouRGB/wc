#ifndef WC_H
#define WC_H

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 32
#define BUFFER_SIZE 1024

struct wc_file
{
    char *filename;
    unsigned int number_of_lines;
    unsigned int number_of_words;
    unsigned int number_of_characters;
};

struct wc_results
{
    bool show_lines;
    bool show_words;
    bool show_characters;
    struct wc_file files[MAX_FILES];
    size_t number_of_files;
};

struct wc_results wc_init(int argc, char *argv[]);

void wc_execute(struct wc_results *results);

void wc_print_results(struct wc_results *results);

#endif /* ! WC_H */
