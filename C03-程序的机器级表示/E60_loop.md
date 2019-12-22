# E60_loop #

[loop.c](./Resources/loop.c)

A.  

    x -> %rdi
    n -> %esi
    result -> %rax
    mask -> %rdx

B.  

    result -> 0
    mask -> 1

C.  

    mask != 0

D.  

    mask <<= n

E.  

    result |= mask & x
