#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

// Simplified getSoundexCode function with reduced complexity
char getSoundexCode(char c) {
    c = toupper(c);
    if (c == 'B' || c == 'F' || c == 'P' || c == 'V') return '1';
    if (c == 'C' || c == 'G' || c == 'J' || c == 'K' || c == 'Q' || c == 'S' || c == 'X' || c == 'Z') return '2';
    if (c == 'D' || c == 'T') return '3';
    if (c == 'L') return '4';
    if (c == 'M' || c == 'N') return '5';
    if (c == 'R') return '6';
    return '0'; // For A, E, I, O, U, H, W, Y, and other non-alphabetic characters
}

void generateSoundex(const char *name, char *soundex) {
    if (name == NULL || soundex == NULL) {
        soundex[0] = '\0'; // Ensure output buffer is valid
        return;
    }

    int len = strlen(name);
    if (len == 0) {
        soundex[0] = '\0'; // Handle empty input
        return;
    }

    // Initialize the soundex string
    soundex[0] = toupper(name[0]);
    int sIndex = 1;
    char lastCode = getSoundexCode(name[0]);

    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != lastCode) {
            soundex[sIndex++] = code;
            lastCode = code; // Update the last code used
        }
    }

    // Pad the soundex string with '0's if necessary
    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    // Null-terminate the soundex string
    soundex[4] = '\0';
}

#endif // SOUNDEX_H
