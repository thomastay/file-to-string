#include <stdio.h>

void fileparsecopy(FILE* ifp, FILE* ofp){
    int c;
    while((c=getc(ifp)) != EOF){
        if (c == '\n'){
            putc('\\', ofp);
            putc('n', ofp);
        } else if (c == '\t'){
            putc('\\', ofp);
            putc('t', ofp);
        } else if (c == '"'){
            putc('\'', ofp);
        }
        else
            putc(c, ofp);
    }
}


int main(int argc, char **argv) {
    FILE * fp;
    const char* prog = argv[0];
    if(argc == 1) /* no args, copy std input */
        fileparsecopy(stdin, stdout);

    while(--argc > 0){
        if((fp = fopen(*++argv, "r")) == NULL){
            fprintf(stderr, "%s: Can't open %s\n", prog, *argv);
            return 1;
        } else{
            fileparsecopy(fp, stdout);
            fclose(fp);
        }
    }
     return 0;
}

