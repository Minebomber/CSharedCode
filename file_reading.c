#include "file_reading.h"

// Reads all lines from a file into a 1d array
// param file - the file pointer to read from
// param lines - an array to store the data (char* array;)
// return num of characters in the line for a loop (numchars + 1)
int fr_read_lines_from_file(FILE *file, char **lines) {
    // Initial array size
    int array_size = 10;
    // Error checking
    if (file == NULL) {
        printf("Error with file (1)\n");
        exit(1);
    }
    // Allocate an initial chunk of memory
    *lines = calloc(array_size, sizeof(char));
    int current_char = 0;
    // Loop
    while (1) {
        // Get character in file
        char c = fgetc(file);
        // Break if end
        if (c == EOF) break;
        // Check if need to allocate more memory
        if (current_char == array_size) {
            array_size *= 2;
            *lines = realloc(*lines, array_size * sizeof(char));
        }
        // Add char to array
        (*lines)[current_char] = c;
        // Increment counter
        current_char++;
    }
    // Return size
    return current_char + 1;
}

// Gets the number of lines in the lines array
// param lines - the array of lines
// param size - the size of the lines array
// return number of newlines
int fr_num_lines(char *lines, int size) {
    // Newline counter
    int num = 0;
    // Loop
    for (int i = 0; i < size; i++) {
        char c = lines[i];
        if (c == '\n') num++;
    }
    // Return
    return num;
}

// Gets a line from the lines array
// param lineNum - the index of the line to get
// param lines - the lines array
// param size - the size of the lines array
// param line - an array to store the line in (char* array;)
// return size of the line array
int fr_line_from_array(int line_num, char *lines, int size, char **line) {
    // Initialize the start and end to 0
    int start = 0;
    int end = 0;
     // [start, end)
    // Variable to keep track of how many newlines passed
    int newlines_passed = 0;

    // Loop over all characters in lines array
    for (int i = 0; i < size; i++) {
        char c = lines[i];
        // If newline
        if (c == '\n') {
            newlines_passed++; // Increment the newline counter
            if (newlines_passed == line_num) { start = i + 1; } // Set start
            if (newlines_passed == line_num + 1) { end = i; break; } // Set end; break
        }
    }
    // Calculate the size of the line array
    int line_size = end - start;
    // Allocate memory to line
    *line = calloc(line_size, sizeof(char));
    // Copy data from lines to line -- does not include the newline
    memcpy(*line, lines + start, line_size * sizeof(char));
    // Return the size of line
    return line_size;
}
