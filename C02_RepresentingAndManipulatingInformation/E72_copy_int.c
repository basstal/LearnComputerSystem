#include <stdio.h>
#include <memory.h>

/**
 * 将整数val复制到缓冲区buf中，但是只有当缓冲区中有足够可用（maxbytes）的空间时，才执行复制
 */

void copy_int(int val, void * buf, int maxbytes){
    int sz = sizeof(val);
    if(maxbytes - sz >= 0)
        memcpy(buf,(void *)&val,sz);
}

int main(){
    int buf = 0;
    copy_int(10,&buf,2);
    printf("%d\n",buf);
    copy_int(10,&buf,4);
    printf("%d\n",buf);
}

