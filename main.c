#include <stdio.h>

#define MAX 10

int  geline(char line[], int maxsize);
void decode(char arr[][4], char line[]);
void getwords(char s1[], char s2[], char so[]);
void daloop();
void clear_str(char[], int size);
int  string_compare(char str1[], char str2[]);
void str_to_hex(char to[], char from[]);
void decode(char arr[][4], char line[]);

int main() 
{   
    //char s1[] = "MOV";
    //char s2[MAX];
    //str_to_hex(s2, "MOV");
    //printf("%s\n", s2);
    daloop();
    return 0;
}

void daloop() {
    char inst[MAX][4];
    char line[MAX];
    char code[MAX];
    char address[MAX];
    char tmp[MAX];
    int i =0; 
    
    printf("v2.0 raw\n");

    while(geline(line, MAX) != 0) {
        // The program is reading the line correctly
        //printf("%s", line);
        getwords(code, address, line);
        //printf("%s %s\n", code, address);
        str_to_hex(tmp, code);
        printf("%s%s ", tmp, address);
        //printf("\n");
    }
    printf("\n");

}

void clear_str(char s[], int size) {
    for(int i = 0; i < size; i++) s[i]=0;
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

void getwords(char s1[], char s2[], char so[]) {
    int c;
    int state = 0;
    for(int i = 0; so[i] != '\n'; ++i) {
        if(so[i] == ' ' && state == 0) {
            s1[i] = '\0';
            state = 1;
        }
        if(state == 0) {
            s1[i] = so[i];
        } 
        if(state == 1 && so[i] != ' ') {
            s2[0] = so[i];
            s2[1] = so[i+1]; 
            s2[2] = '\0';
            return;
        }
    }
}

int string_compare(char str1[], char str2[]) {
    int i = 0;
    while(str1[i] != '\0' || str2[i] != '\0') {
        if(str1[i] != str2[i]) return 0;
        i++;
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
    else if(string_compare("JPB" ,   from) > 0) copy(to, "0b");
    else if(string_compare("JPZ" ,   from) > 0) copy(to, "0d");
    else if(string_compare("JP" ,    from) > 0) copy(to, "0a");
}

void decode(char arr[][4], char line[]) {
    char code[MAX];
    char address[MAX];

    getwords(code, address, line);

}
