// ipc.h部分
\* Filename

: ipc.h

\* copyright

: (C) 2006 by zhonghonglie

\* Function

: 声明 IPC 机制的函数原型和全局变量

*/

\#include <stdio.h>

\#include <stdlib.h>

\#include <sys/types.h>

\#include <sys/ipc.h>

\#include <sys/shm.h>

\#include <sys/sem.h>

\#include <sys/msg.h>

\#define BUFSZ 256

//建立或获取 ipc 的一组函数的原型说明

int get_ipc_id(char *proc_file,key_t key);

char *set_shm(key_t shm_key,int shm_num,int shm_flag);

int set_msq(key_t msq_key,int msq_flag);

int set_sem(key_t sem_key,int sem_val,int sem_flag);

int down(int sem_id);

int up(int sem_id);

/*信号灯控制用的共同体*/

typedef union semuns {

int val;

} Sem_uns;

/* 消息结构体*/

typedef struct msgbuf0 {

long mtype;

char mtext[1];

} Msg_buf;

//生产消费者共享缓冲区即其有关的变量

key_t buff_key;

int buff_num;

char *buff_ptr;

//生产者放产品位置的共享指针

key_t pput_key;

int pput_num;

int *pput_ptr;

//消费者取产品位置的共享指针

key_t cget_key;

int cget_num;

int *cget_ptr;

//消费者有关的信号量

key_t tobacco_key;     //消费者1

key_t glue_key;       //消费者2

key_t paper_key;      //消费者3

//key_t cmtx_key; 

//int cmtx_sem;       //消费者互斥信号量，这里不需要

int tobacco_sem;

int glue_sem;

int paper_sem;



//生产者有关的信号量

key_t empty_key;    //同步信号量,是否为空

key_t pmtx_key;     //互斥信号量，为1

int pmtx_sem;

int empty_sem;

//信号量大小以及权限

int sem_val;

int sem_flg;

int shm_flg;


