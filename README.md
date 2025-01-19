![Banner](images/banner.png)

## Overview

This tool is a recreation of the UNIX wc command. It reads text from files or standard input and displays counts for characters, lines, and words. It supports multiple files and will display each one on its line as well as a total for each category.

## Key Features

- Count characters (`-c`)
- Count lines (`-l`)
- Count words (`-w`)
- Support for multiple files
- Displays totals for each category

## Limitations and Known Issues

- The tool does not handle all wc flags.

## Usage and Testing

To test the tool, you should first run the make command. The wc executable will be located in the build folder. You can the run it using this pattern:

```bash
./wc [OPTIONS] [FILES...]
```

You can also check the example section bellow.

## Contributions and Feedback

If you have any suggestions or ideas for improving the tool, or if you've discovered a bug, I would greatly appreciate your feedback. Please feel free to submit a pull request or open an issue in the project repository.

## Credits

This project was developed by Fayçal Beghalia. Any use of this code is authorized, provided that proper credit is given.

## Example

```bash
faycal@FaycalLaptop:~/faycal/projects/wc$ build/wc Makefile src/main.c
18 48 327 Makefile
13 25 244 src/main.c
31 73 571 total
```

```bash
faycal@FaycalLaptop:~/faycal/projects/wc$ cat test.txt | build/wc -l
7145
```
