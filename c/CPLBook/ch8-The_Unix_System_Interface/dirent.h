//
// Created by zhenguo on 19-4-8.
//

#ifndef CPLBOOK_DIRENT_H
#define CPLBOOK_DIRENT_H

#define NAME_MAX_NEW  14

//portable directory entry
typedef struct {
    long ino;
    char name[NAME_MAX_NEW+1];
} Dirent;

//minimal DIR
typedef struct {
    int fd;
    Dirent d;
} Dir;

//open a directory for readdir calls
Dir *_opendir(char *dirname);
//read directory entries in sequence
Dirent *_readdir(Dir *dfd);
//close directory opened by opendir
void _closedir(Dir *dfd);

#endif //CPLBOOK_DIRENT_H
