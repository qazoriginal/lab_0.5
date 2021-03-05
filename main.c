#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *getString(char *a, int *fl, int *size);
char *samesim(char *a,int size);



int main() {
    int fl, size;
    do {
        char *a = (char *)malloc(1 * sizeof(char ));
        a = (char *)realloc(a , sizeof(char ) * 1);
        a = getString(a, &fl, &size);
        if (a[0] == '\0')
            return 0;
        //printf("HERE");
        //puts(a);
        //printf("%d", size);
        //samesim(a,size);
        printf("final string: ");
        puts(samesim(a,size));
        free(a);
        //while (scanf("%*[^\n]",a) != EOF)
        //    scanf("%*c");
    } while (fl != EOF); //fl != EOF
    return 0;
}


char *getString(char *a, int *fl, int *size){
    *size = 1;
    printf("Input string, please --> ");
    char buf[101];
    do {
        *fl = scanf("%100[^\n]", buf);
        if (buf[0] == '\0'){
            a[0] = '\0';
            return a;
        }
        a = (char *)realloc(a,sizeof(char) * (*size + 100));
        strcat(a , buf);
        *size += 100;
        scanf("%*c");
    } while (*fl > 0 && strlen(buf) >= 100);
    return a;
}


char *samesim(char *a,int size){
    char *b = (char *)malloc(size * sizeof(char ));
    char *p = a;
    char *u = b;
    while (*p == ' ' || *p == '\t'){
        ++p;
    }
    char h = *p;
    while (*p != '\0'){
        if (*(p + 1) == h && *p == h /*|| *(p - 1) == h*/) {
            *b = *p;
            ++b;
        }
        if (*(p + 1) != h && *(p - 1) == h && *p == h){
            *b = *p;
            ++b;
            *b = ' ';
            //b = strcat(b," ");
            ++b;
        }

        ++p;
    }
    return u;
}