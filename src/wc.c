#include "wc.h"

struct wc_results wc_init(int argc, char *argv[])
{
    struct wc_results results = {
        .show_lines = false,
        .show_words = false,
        .show_characters = false,
        .number_of_files = 0,
    };

    bool options_provided = false;
    for (int i = 1; i < argc; ++i)
    {
        if (argv[i][0] == '-')
        {
            options_provided = true;
            for (size_t j = 1; argv[i][j] != '\0'; ++j)
            {
                switch (argv[i][j])
                {
                case 'l':
                    results.show_lines = true;

                    break;
                case 'w':
                    results.show_words = true;
                    break;
                case 'c':
                    results.show_characters = true;
                    break;
                default:
                    fprintf(stderr, "wc: invalid option -- '%c'\n", argv[i][j]);
                    fprintf(stderr,
                            "Supported flags include '-l', '-w' and '-c'.\n");
                    exit(1);
                }
            }
        }
        else
        {
            if (results.number_of_files == MAX_FILES)
            {
                fprintf(stderr, "wc: too many files\n");
                exit(1);
            }

            results.files[results.number_of_files++].filename = argv[i];
        }
    }

    if (!options_provided)
    {
        results.show_lines = true;
        results.show_words = true;
        results.show_characters = true;
    }

    return results;
}

unsigned int __wc_count_words(const char *buffer)
{
    unsigned int number_of_words = 0;
    bool in_word = false;
    for (size_t i = 0; buffer[i]; ++i)
    {
        if (isspace(buffer[i]))
        {
            in_word = false;
        }
        else if (!in_word)
        {
            in_word = true;
            ++number_of_words;
        }
    }

    return number_of_words;
}

void __wc_handle_stdin(struct wc_results *results)
{
    results->number_of_files = 1;
    results->files[0].filename = "";
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, stdin) != NULL)
    {
        ++results->files[0].number_of_lines;
        results->files[0].number_of_characters += strlen(buffer);
        results->files[0].number_of_words += __wc_count_words(buffer);
    }
}

void __wc_handle_file(struct wc_results *results, size_t file_index)
{
    FILE *file = fopen(results->files[file_index].filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "wc: %s: No such file or directory\n",
                results->files[file_index].filename);
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file) != NULL)
    {
        ++results->files[file_index].number_of_lines;
        results->files[file_index].number_of_characters += strlen(buffer);
        results->files[file_index].number_of_words += __wc_count_words(buffer);
    }
}

void wc_execute(struct wc_results *results)
{
    if (results->number_of_files == 0)
    {
        __wc_handle_stdin(results);
        return;
    }

    for (size_t i = 0; i < results->number_of_files; ++i)
    {
        __wc_handle_file(results, i);
    }
}

void wc_print_results(struct wc_results *results)
{
    unsigned int total_lines = 0;
    unsigned int total_words = 0;
    unsigned int total_characters = 0;

    for (size_t i = 0; i < results->number_of_files; ++i)
    {
        if (results->show_lines)
        {
            printf("%u ", results->files[i].number_of_lines);
            total_lines += results->files[i].number_of_lines;
        }

        if (results->show_words)
        {
            printf("%u ", results->files[i].number_of_words);
            total_words += results->files[i].number_of_words;
        }

        if (results->show_characters)
        {
            printf("%u ", results->files[i].number_of_characters);
            total_characters += results->files[i].number_of_characters;
        }

        printf("%s\n", results->files[i].filename);
    }

    if (results->number_of_files > 1)
    {
        if (results->show_lines)
        {
            printf("%u ", total_lines);
        }

        if (results->show_words)
        {
            printf("%u ", total_words);
        }

        if (results->show_characters)
        {
            printf("%u ", total_characters);
        }

        printf("total\n");
    }
}
