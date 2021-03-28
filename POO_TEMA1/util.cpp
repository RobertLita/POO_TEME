//
// Created by Robert on 28.03.2021.
//

#include "util.h"

char* util::format(char *a) {
    int start=0,end=strlen(a)-1;
    char *s;
    s=new char;
    int k=-1;
    while(a[start]==' ')
        start++;
    while(a[end]==' ')
        end--;
    s[++k]=toupper(a[start]);
    for(int i=start+1;i<=end;i++) {
        if (!(a[i] == ' ' && a[i - 1] == ' '))s[++k] = tolower(a[i]);
    }
    s[++k]='\0';
    return s;
}
