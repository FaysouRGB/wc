# WC Command Project

This tool reads text from files or standard input and displays counts for:
- Characters (`-c`)
- Lines (`-l`)
- Words (`-w`)

It also support multiple files and will display each one on its line as well as a total for each category.

Note: if no flags are provided, they will be all set.

## Usage

```bash
./wc [OPTIONS] [FILES...]
```

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
