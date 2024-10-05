/*
 * Read hex strings and output as text.
 *
 * No checking of the characters is done, but the strings must have an even
 * length.
 *
 * $Id: hex2ascii.c,v 1.1 2009/09/19 23:56:49 grog Exp $
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "suppress_space.h"

char hexdigit(char c) {
    char outc;

    outc = c - '0';
    if (outc > 9) {
        outc -= 7;
    }
    if (outc > 15 || outc < 0) {
        fprintf(stderr, "Invalid character %c, aborting\n", c);
        exit(1);
    }
    return outc;
}

const unsigned char* hex2ascii(const char *hexval) {
    int arg;
    char *c = spaces(hexval);
    int sl;
    char oc;
    int i = 0;

    for (arg = 0; arg < strlen(c) / 2; arg++) { // Iterate until half the length
        sl = strlen(c);
        if (sl & 1) {
            fprintf(stderr, "%s is %d chars long, must be even\n", c, sl);
            return NULL;
        }

        oc = (hexdigit(*c++) << 4) + hexdigit(*c++);
        fputc(oc, stdout);
        ascii[i++] = oc;
    }

    ascii[i] = '\0'; // Add null terminator
    return (const unsigned char *)ascii;
}



