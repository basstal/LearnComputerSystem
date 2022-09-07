# 系统级I/O #

## Unix I/O ##

1. 一个Linux文件就是一个字节序列，所有的I/O设备都被模块化为文件，所有的输入输出都被当作对相应文件的读和写来处理：
    - 打开文件，应用程序要求内核打开文件，返回一个非负整数的描述符，它在后续对此文件的所有操作中标示这个文件。
    - Linux Shell创建的每个进程开始时都会打开三个文件：标准输入、标准输出、标准错误。
    - 改变当前的文件位置。
    - 读写文件。
    - 关闭文件。

## 文件 ##

1. Linux每个文件都有一个类型：
    - 普通文件，包括文本文件和二进制文件。文本文件包含一个文本行序列，每一行都以一个新行符结尾，二进制文件是除文本文件外的其他文件。
    - 目录，包含一组链接的文件，每个链接都将一个文件名映射到一个文件，每个目录至少含有两个条目，到该目录自身的链接（.），到目录层次结构中父目录的链接（..）。
    - 套接字，用来与另一个进程进行跨网络通信的文件。

## 打开和关闭文件 ##

1. Open函数打开一个已存在的文件或创建一个新文件。

2. flags参数指明了进程打算如何访问这个文件：
    - O_RDONLY，只读。
    - O_WRONLY，只写。
    - O_RDWR，可读可写。
    - O_CREAT，如果文件不存在，就创建它的一个截断的空文件。
    - O_TRUNC，如果文件已经存在，就截断它。
    - O_APPEND，在每次写操作前，设置文件位置到结尾处。

3. mode参数指定了新文件的访问权限位。

## 读和写文件 ##

## 用RIO包健壮地读写 ##

## 读取文件元数据 ##

## 读取目录内容 ##

## 共享文件 ##

1. 内核用三个相关的数据结构来表示打开的文件：
    - 描述符表，每个进程都有它独立的描述符表，它的表项是由进程打开的文件描述符来索引的，每个打开的描述符表项只想文件表中的一个表项。
    - 文件表，打开文件的集合是由一张文件表来表示的，所有的进程共享这张表。每个文件表的表项组成包括当前的文件位置、引用计数、以及一个指向v-node表中对应表项的指针。关闭一个描述符会减少相应的文件表表项中的引用计数。内核不会删除一个引用计数不为零的文件表表项。
    - v-node表，同文件表一样，所有的进程共享这张v-node表。每个表项包含stat结构中的大多数信息，包括st_mode和st_size成员。

## I/O重定向 ##

1. dum2函数复制描述符表表项oldfd到描述符表表项newfd，覆盖描述符表表项newfd以前的内容。如果newfd已经打开了，dup2会在复制oldfd之前关闭newfd。

## 标准I/O ##

## 综合：我该使用哪些I/O函数 ##

1. 下面是一些基本的指导原则：
    - 只要有可能就是用标准的I/O。
    - 不要使用scanf或rio_readlineb来读二进制文件。二进制文件可能散布着很多0xa字节，而这些字节又与终止文本行无关。
    - 对网络套接字的I/O使用RIO函数。

2. 标准I/O流，从某种意义上而言是全双工的，因为程序能够在同一个流上执行输入和输出。然而，对流的限制和对套接字的限制，有时候会互相冲突，而又极少有文档描述这些现象：
    - 限制一：跟在输出函数之后的输入函数。如果中间没有插入对fflush、fseek、fsetpos或者rewind的调用，一个输入函数不能跟随在一个输出函数之后。
    - 限制二：跟在输入函数之后的输出函数。如果中间没有插入对fseek、fsetpos或者rewind的调用，一个输出函数不能跟随在一个输入函数之后，除非该出入函数遇到了一个文件结束。

3. 在网络套接字上不要使用标准I/O函数来进行输入和输出，而要使用健壮的RIO函数。

## 家庭作业未完成 ##

- 9、10