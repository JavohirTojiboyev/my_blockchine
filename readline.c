#include "main.h"

char *my_readline(int fd) {
        char line[4096];
        char c;
        int position = 0, r;
        ;
        if(read(fd, &c, 1)==0)
            return 0;
        line[position++] = c;
        while((r=read(fd, &c, 1)) > -1) {
            if(r==0 OR c=='\n')
                break;
            line[position++] = c;
        }
        line[position] = '\0';
        char* res = (char*)malloc(sizeof(char)*position);
        res = line;
        return res;
}
