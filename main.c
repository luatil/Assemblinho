#include <stdio.h>

#define MAX 10

int geline(char line[], int maxsize);
void decode(char arr[][4], char line[]);

int main() 
{
    char inst[MAX][4];
    char line[MAX];
    while(geline(line, MAX) != 0) {
        printf("%s", line);
    }
    return 0;
}

int geline(char line[], int maxsize) {
    int c, i;
    for(i=0;i<maxsize && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if(c == '\n') {
        line[i] = c;
        i++;
    } 
    line[i] = '\0';
    return i;
}

int getwords(char code[], char address[], char line[]) {
    int c, i;
    for(i = 0; i<MAX && (c = getchar()) != ' '; ++i) 
        code[i] = c;
    // for simplicity, let's assume it's just a one space thing
    // also, adress is just a 2 value thing
    address[0] = c = getchar();
    address[1] = c = getchar();
    return i;
}

int string_compare(char str1[], char str2[]) {
    int i = 0;
    while(str1[i] != '\0') {
        if(str1[i] != str2[i]) return 0;
    }
    return i;
}

void copy(char to[], char from[]) {
    int i = 0;
    while((to[i] = from[i]) != '\0') ++i;
}

void str_to_hex(char to[], char from[]) {
    if(     string_compare("NOP",    from) > 0) copy(to, "00");
    else if(string_compare("MOV",    from) > 0) copy(to, "01");
    else if(string_compare("CP" ,    from) > 0) copy(to, "02");
    else if(string_compare("SUM" ,   from) > 0) copy(to, "03");
    else if(string_compare("SUB" ,   from) > 0) copy(to, "04");
    else if(string_compare("READ" ,  from) > 0) copy(to, "07");
    else if(string_compare("PRINT" , from) > 0) copy(to, "08");
    else if(string_compare("STOP",   from) > 0) copy(to, "09");
    else if(string_compare("JP" ,    from) > 0) copy(to, "0a");
    else if(string_compare("JPB" ,   from) > 0) copy(to, "0b");
    else if(string_compare("JPZ" ,   from) > 0) copy(to, "0d");
}

void decode(char arr[][4], char line[]) {
    char code[MAX];
    char address[MAX];

    getwords(code, address, line);

}
