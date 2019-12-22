
A.  x -> %rdi</br>
    n -> %esi</br>
    result -> %rax</br>
    mask -> %rdx

B.  result -> 0</br>
    mask -> 1

C.  mask != 0

D.  mask <<= n

E.  result |= mask & x

[loop.c](./Resources/loop.c)