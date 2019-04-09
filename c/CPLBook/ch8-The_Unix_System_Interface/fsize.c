//
// Created by zhenguo on 19-4-8.
//

#include "dirent.h"
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

//apply fcn to all files in dir
#define MAX_PATH 1024

void dirwalk(char *dir, void (*fcn)(char *)){
    printf("dirwalk\n");
    char name[MAX_PATH];
    Dirent *dp;
    Dir *dfd;

    if((dfd = _opendir(dir)) == NULL){
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }

    while((dp = _readdir(dfd)) != NULL){
        printf("enter read subdir\n");
        if(strcmp(dp->name, ".") == 0
            || strcmp(dp->name, "..") == 0)
            continue;
        if(strlen(dir) + strlen(dp->name) + 2 > sizeof(name))
            fprintf(stderr, "dirwalk: name %s/%s too long\n", dir, dp->name);
        else{
            sprintf(name, "%s/%s", dir, dp->name);
            (*fcn)(name);
        }
    }

    _closedir(dfd);
}

//print the size of file "fileName"
void fsize(char *fileName){
    printf("run fsize: %s\n", fileName);
    struct stat stbuf;

    if(stat(fileName, &stbuf) == -1){
        fprintf(stderr, "fsize: can't access %s\n", fileName);
        return;
    }

    if((stbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(fileName, fsize);
    printf("%8ld %s\n", stbuf.st_size, fileName);
}

int main(int argc, char **argv){
    if(argc == 1){
        fsize(".");
    }else{
        while(--argc > 0)
            fsize(*++argv);
    }
    return 0;
}



