//
// Created by Administrator on 2020/3/12.
//

//
// Created by Crazy.Mo on 2019/2/19.
//

#ifndef MMAP_MMAP_UTIL_H
#define MMAP_MMAP_UTIL_H

#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <strings.h>
#include <android/log.h>
#include <string>

#define  LOG(...) __android_log_print(ANDROID_LOG_ERROR,"CrazyMoMMAP",__VA_ARGS__);

//写在头文件里的变量如果不加上static 的话会造成重复引用 最好的办法就是不要写在头文件
static int8_t *_ptr=0;
static size_t _size;
static int32_t _fd;

void mmap_write(const char *src_ptr,const int32_t len, const char *path_ptr, const char *name_ptr);

void mmap_write(const std::string src_ptr, const std::string path, const std::string name);

void mmap_write(const void *src_ptr, const int32_t len, const char *path_ptr, const char *name_ptr);

#endif //MMAP_MMAP_UTIL_H

