//
// Created by zhenguo on 19-4-9.
//

#include "dirent.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/dir.h>
#include <unistd.h>
#include <memory.h>

//open a directory for readdir calls
Dir *_opendir(char *dirname){
    int fd;
    struct stat stbuf;
    Dir *dp;

    if((fd = open(dirname, O_RDONLY, 0)) == -1
    || fstat(fd, &stbuf) == -1
    || (stbuf.st_mode & S_IFMT) != S_IFDIR
    || (dp = (Dir *) malloc(sizeof(Dir))) == NULL )
        return NULL;

    dp->fd = fd;
    printf("open: %s %d\n", dirname, fd);
    return dp;
}

//read directory entries in sequence
Dirent *_readdir(Dir *dp){

    struct direct dirbuf;
    static Dirent d;

    size_t temp;
    printf("fd: %d\n", dp->fd);
    while((temp = read(dp->fd, (char *) &dirbuf, sizeof(dirbuf))) == sizeof(dirbuf)){
        printf("test\n");
        if(dirbuf.d_ino == 0)
            continue;
        d.ino = dirbuf.d_ino;
        strncpy(d.name, dirbuf.d_name, NAME_MAX_NEW);
        d.name[NAME_MAX_NEW] = '\0';
        printf("%s\n", d.name);
        return &d;
    }
    printf("%d\n", temp);

    return NULL;
}


//close directory opened by opendir
void _closedir(Dir *dp){
    if(dp){
        close(dp->fd);
        free(dp);
    }
}