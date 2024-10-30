#ifndef SOUNDEX_H
#define SOUNDEX_H
 
#include "Soundex.h"
#include <ctype.h>
#include <string.h>
 
// char getSoundexCode(char c) {
//     c = toupper(c);
//     switch (c) {
//         case 'B': case 'F': case 'P': case 'V': return '1';
//         case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
//         case 'D': case 'T': return '3';
//         case 'L': return '4';
//         case 'M': case 'N': return '5';
//         case 'R': return '6';
//         default: return '0'; // For A, E, I, O, U, H, W, Y
//     }
// }
 
// void generateSoundex(const char *name, char *soundex) {
//     int len = strlen(name);
//     soundex[0] = toupper(name[0]);
//     int sIndex = 1;
 
//     for (int i = 1; i < len && sIndex < 4; i++) {
//         char code = getSoundexCode(name[i]);
//         if (code != '0' && code != soundex[sIndex - 1]) {
//             soundex[sIndex++] = code;
//         }
//     }
 
//     while (sIndex < 4) {
//         soundex[sIndex++] = '0';
//     }
 
//     soundex[4] = '\0';
// }

void soundex(const char *name, char *soundex_code) {
  
    strncpy(soundex_code, "0000", 4);
    soundex_code[4] = '\0'; 

    
    soundex_code[0] = toupper(name[0]);


    char mappings[26] = {'0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'};

    char previous_digit = mappings[soundex_code[0] - 'A'];
    int code_index = 1;

  
    for (int i = 1; name[i] != '\0' && code_index < 4; i++) {
        char upper_char = toupper(name[i]);
        char current_digit = mappings[upper_char - 'A'];

        
        if (current_digit != '0' && current_digit != previous_digit) {
            soundex_code[code_index++] = current_digit;
        }
        previous_digit = current_digit;
    }
}


 
#endif // SOUNDEX_H
