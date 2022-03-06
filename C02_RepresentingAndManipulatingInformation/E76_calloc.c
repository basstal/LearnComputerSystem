#include<stdio.h>

/**
 * 使用malloc和memset编写库函数calloc，
 * 代码应该没有任何由算术溢出引起的漏洞，且无论数据类型size_t用多少位表示，代码都应该正常工作
 */

void *calloc(size_t nmemb, size_t size)
{
    size_t memSize = nmemb * size;
    if (!nmemb || !size || memSize / size != nmemb)
        return NULL;
    
    void *rtn = malloc(memSize);
    rtn = memset(rtn, 0, memSize);
    return rtn;
}