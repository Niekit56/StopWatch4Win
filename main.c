#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

#define TRUE 1

// Function for outputting digits
void drawDigit(int digit, char buffer[][100]) {
    switch(digit) {
        case 0:
            sprintf(buffer[0], "  #####  ");
            sprintf(buffer[1], " #     # ");
            sprintf(buffer[2], "#       #");
            sprintf(buffer[3], "#       #");
            sprintf(buffer[4], "#       #");
            sprintf(buffer[5], " #     # ");
            sprintf(buffer[6], "  #####  ");
            break;
        case 1:
            sprintf(buffer[0], "    #    ");
            sprintf(buffer[1], "   ##    ");
            sprintf(buffer[2], "  # #    ");
            sprintf(buffer[3], "    #    ");
            sprintf(buffer[4], "    #    ");
            sprintf(buffer[5], "    #    ");
            sprintf(buffer[6], "  #####  ");
            break;
        case 2:
            sprintf(buffer[0], "  #####  ");
            sprintf(buffer[1], " #     # ");
            sprintf(buffer[2], "       # ");
            sprintf(buffer[3], "  #####  ");
            sprintf(buffer[4], " #       ");
            sprintf(buffer[5], "#        ");
            sprintf(buffer[6], "#########");
            break;
        case 3:
            sprintf(buffer[0], "  #####  ");
            sprintf(buffer[1], " #     # ");
            sprintf(buffer[2], "       # ");
            sprintf(buffer[3], "  #####  ");
            sprintf(buffer[4], "       # ");
            sprintf(buffer[5], " #     # ");
            sprintf(buffer[6], "  #####  ");
            break;
        case 4:
            sprintf(buffer[0], "#       #");
            sprintf(buffer[1], "#       #");
            sprintf(buffer[2], "#       #");
            sprintf(buffer[3], "#########");
            sprintf(buffer[4], "       # ");
            sprintf(buffer[5], "       # ");
            sprintf(buffer[6], "       # ");
            break;
        case 5:
            sprintf(buffer[0], "#########");
            sprintf(buffer[1], "#        ");
            sprintf(buffer[2], "#        ");
            sprintf(buffer[3], "######## ");
            sprintf(buffer[4], "       # ");
            sprintf(buffer[5], "#      # ");
            sprintf(buffer[6], " ######  ");
            break;
        case 6:
            sprintf(buffer[0], " ######  ");
            sprintf(buffer[1], "#        ");
            sprintf(buffer[2], "#        ");
            sprintf(buffer[3], "#######  ");
            sprintf(buffer[4], "#      # ");
            sprintf(buffer[5], "#      # ");
            sprintf(buffer[6], " ######  ");
            break;
        case 7:
            sprintf(buffer[0], "#########");
            sprintf(buffer[1], "#     #  ");
            sprintf(buffer[2], "     #   ");
            sprintf(buffer[3], "    #    ");
            sprintf(buffer[4], "   #     ");
            sprintf(buffer[5], "  #      ");
            sprintf(buffer[6], "  #      ");
            break;
        case 8:
            sprintf(buffer[0], " ######  ");
            sprintf(buffer[1], "#      # ");
            sprintf(buffer[2], "#      # ");
            sprintf(buffer[3], " ######  ");
            sprintf(buffer[4], "#      # ");
            sprintf(buffer[5], "#      # ");
            sprintf(buffer[6], " ######  ");
            break;
        case 9:
            sprintf(buffer[0], " ######  ");
            sprintf(buffer[1], "#      # ");
            sprintf(buffer[2], "#      # ");
            sprintf(buffer[3], " ####### ");
            sprintf(buffer[4], "       # ");
            sprintf(buffer[5], "       # ");
            sprintf(buffer[6], " ######  ");
            break;
    }
}

// Function for reading a txt file
void printFileContent(const char *filename) {
    FILE *file;
    char ch;

    // Open the file for reading
    file = fopen(filename, "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Failed to open file %s.\n", filename);
        return;
    }

    // Read characters from the file and output them to the console
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }

    fclose(file);
}

int main() {
    int minutes = 0;
    int seconds = 0;

    char digitBuffers[5][7][100]; // Buffers to store each digit
    while(TRUE) {

        // Use ANSI escape codes to clear the screen and move the cursor to the top-left
        printf("\033[2J\033[H"); // Clear screen and move cursor to top-left

        // Print data from the file
        printFileContent("pattern.txt");

        // Draw first digit of minutes
        drawDigit(minutes / 10, digitBuffers[0]);
        // Draw second digit of minutes
        drawDigit(minutes % 10, digitBuffers[1]);
        // Draw colon
        sprintf(digitBuffers[2][0], " : ");
        // Draw first digit of seconds
        drawDigit(seconds / 10, digitBuffers[3]);
        // Draw second digit of seconds
        drawDigit(seconds % 10, digitBuffers[4]);

        // Print the buffer
        for (int i = 0; i < 7; i++) {
            printf("\t\t%s  \t%s  \t%s  \t%s  \t%s\n", digitBuffers[0][i], digitBuffers[1][i], digitBuffers[2][0], digitBuffers[3][i], digitBuffers[4][i]);
        }

        fflush(stdout);
        Sleep(1000); // Sleep for 1000 milliseconds = 1 second

        // Simple logic for changing symbols
        seconds++;
        if (seconds == 60) {
            seconds = 0;
            minutes++;
            if (minutes == 100) {
                minutes = 0;
            }
        }
    }

    return 0;
}
