#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "coder.h"
#include "str.h"

int main(int argc, char** argv) {
    char type[10];
    char* text;
    char* result;
    bool ok = false;
    if (argc == 4) {
        /* 
        argv[1] - key
        argv[2] - text
        argv[3] - param
        */
        strcpy(type, argv[1]);
        const int size = strlen(argv[2]);
        text = (char*) malloc(sizeof(char) * (size + 1));
        strcpy(text, argv[2]);

        if (strcmp(type, "--caesar") == 0 && isNumber(argv[3])) {
            int offset = stringToInt(argv[3]);
            result = immutableCaesarDecode(text, offset);
            ok = true;
        }
        else if (strcmp(type, "--xor") == 0) {
            char password[100];
            strcpy(password, argv[3]);
            result = immutableXorDecode(text, password);
            ok = true;
        }
        free(text);
    }
    else if (argc == 1) {   
        printf("Type (caesar/xor): ");
        scanf("%s", type);
        printf("Text: ");
        char ch = fgetc(stdin);
        text = inputString();

        if (strcmp(type, "caesar") == 0) {
            int offset;
            printf("Offset: ");
            scanf("%d", &offset);
            result = immutableCaesarDecode(text, offset);
            ok = true;
        }
        else if (strcmp(type, "xor") == 0) {
            char password[100];
            printf("Password: ");
            scanf("%s", password);
            result = immutableXorDecode(text, password);
            ok = true;
        }

        free(text);
    }
    
    if (ok == true) {
        printf("%s\n", result); // printing result
        free(result);
    }
    else {
        printf("Input format must be: \n");
        printf("1. ./decoder --caesar text offset\n");
        printf("2. ./decoder --xor text password\n");
        printf("3. ./decoder\n");
    }
    
    return 0;
}
