#ifndef _FILE_READING_H_
#define _FILE_READING_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int fr_read_lines_from_file(FILE *file, char **lines);
int fr_num_lines(char *lines, int size);
int fr_line_from_array(int line_num, char *lines, int size, char **line);

#endif
