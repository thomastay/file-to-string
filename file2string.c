#include <stdio.h>
#include <string.h>

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
    /* End off with a newline */
    putc('\n', ofp);
}


int main(int argc, char **argv) {
    FILE * fp;
    const char* prog = argv[0];
    const char* helpStr = "Usage: \n    file2string [FILE] ...\n\nDescription:\n    Outputs a string that represents the file(s), followed by a newline. \n    If no FILE is named, read from STDIN.\n    '-' represents STDIN.\n";
    const char* versionStr = "file2string version 1.1.0\nCopyright (C) 2018 Thomas Tay.\nLicence: GPLv3+; GPL version 3 or later\nThis is free software, you are free to change and distribute it\nThere is NO WARRANTY WHATSOEVER\n";
    if(argc == 1){ /* no args, copy std input */
        fileparsecopy(stdin, stdout);
        return 0;
    }

    if(strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0){
        printf("%s", helpStr);
        return 0;
    }
    if(strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0){
        printf("%s", versionStr);
        return 0;
    }

    while(--argc > 0){
        if((fp = fopen(*++argv, "r")) == NULL){
            if (strcmp(*argv, "-") == 0){
                fileparsecopy(stdin, stdout);
            } else {
            fprintf(stderr, "%s: Can't open %s\n", prog, *argv);
            return 1;
            }
        } else {
            fileparsecopy(fp, stdout);
            fclose(fp);
        }
    }
     return 0;
}

