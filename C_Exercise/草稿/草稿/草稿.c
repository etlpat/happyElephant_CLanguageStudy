#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define furthest 5

struct process { /* PCB STRUCTURE */
    int id;
    int priority;
    int cputime;
    int alltime;
    char state;
    int next;
} prochain[furthest];

int procnum;
int algo;
int run = 0, head = 0, tail = 0, j;

void print(); /* 函数声明 */
void insert(int q);
void insert2();
void init();
void prisch();
void timesch();

int main() { /* MAIN PROGRAM */
    int agan = 1;
    while (agan) {
        printf("Type the algorithm is (1:RR,2:PRIO): ");
        scanf("%d", &algo);
        if (algo == 2) {
            printf("Output of priority.\n");
            init();
            prisch();
        }
        else if (algo == 1) {
            printf("Output of round robin.\n");
            init();
            timesch();
        }
        else {
            printf("Try again, please\n");
        }
        agan = 0; /* 移除goto，使用循环控制 */
    }
    for (j = 1; j <= 40; j++) {
        printf("=");
    }
    printf("\n\n");
    for (j = 1; j <= 40; j++) {
        printf("=");
    }
    printf("\n\n");
    printf("System finished\n");
    return 0;
}

void print() { /* PRINT THE RUNNING PROCESS, WAITING QUEUE AND PCB SEQUENCE LIST */
    int k, p;
    for (k = 1; k <= 40; k++) {
        printf("=");
    }
    printf("\nRunning proc.                Waiting queue.\n");
    printf("    %d      ", prochain[run].id);
    p = head;
    while (p != 0) {
        printf("%5d", p);
        p = prochain[p].next;
    }
    printf("\n");
    for (k = 1; k <= 40; k++) {
        printf("=");
    }
    printf("\n");
    printf(" id            ");
    for (k = 1; k <= furthest; k++) {
        printf("%5d", prochain[k].id);
    }
    printf("\n");
    printf("priority       ");
    for (k = 1; k <= furthest; k++) {
        printf("%5d", prochain[k].priority);
    }
    printf("\n");
    printf("cputime        ");
    for (k = 1; k <= furthest; k++) {
        printf("%5d", prochain[k].cputime);
    }
    printf("\n");
    printf("alltime        ");
    for (k = 1; k <= furthest; k++) {
        printf("%5d", prochain[k].alltime);
    }
    printf("\n");
    printf("state          ");
    for (k = 1; k <= furthest; k++) {
        printf("%5c", prochain[k].state);
    }
    printf("\n");
    printf("next           ");
    for (k = 1; k <= furthest; k++) {
        printf("%5d", prochain[k].next);
    }
    printf("\n");
}

void insert(int q) { /* INSERT A PROCESS */
    int p, s;
    p = head;
    s = prochain[head].next;
    while ((prochain[q].priority < prochain[s].priority) && (s != 0)) {
        p = s;
        s = prochain[s].next;
    }
    prochain[p].next = q;
    prochain[q].next = s;
}

void insert2() { /* PUT A PROCESS ONTO THE TAIL OF THE QUEUE */
    prochain[tail].next = run;
    tail = run;
    prochain[run].next = 0;
}

void init() { /* CREATE A WAITING QUEUE */
    int i;
    head = 0;
    if (algo == 2) {
        for (i = 1; i <= furthest; i++) {
            prochain[i].id = i;
            prochain[i].priority = (rand() % 41) + 1;
            prochain[i].cputime = 0;
            prochain[i].alltime = (rand() % 7) + 1;
            prochain[i].state = 'W';
            prochain[i].next = 0;
            if ((head == 0) || (prochain[i].priority < prochain[head].priority)) {
                prochain[i].next = head;
                head = i;
            }
            else {
                insert(i);
            }
        }
    }
    else {
        for (i = 1; i <= furthest; i++) {
            prochain[i].id = i;
            prochain[i].priority = (rand() % 3) + 1;
            prochain[i].cputime = 0;
            prochain[i].alltime = (rand() % 7) + 1;
            prochain[i].state = 'W';
            if (i < furthest) {
                prochain[i].next = i + 1;
            }
            else {
                prochain[i].next = 0;
            }
        }
        head = 1;
        tail = furthest;
    }
    run = head;
    prochain[run].state = 'R';
    head = prochain[head].next;
    prochain[run].next = 0;
    print();
}

void prisch() { /* THE PROCESS WITH PRIO ALGORITHM */
    while (run != 0) {
        prochain[run].cputime += 1;
        prochain[run].priority -= 3;
        prochain[run].alltime -= 1;
        if (prochain[run].alltime == 0) {
            prochain[run].state = 'F';
            prochain[run].next = 0;
            if (head != 0) {
                run = head;
                prochain[run].state = 'R';
                head = prochain[head].next;
            }
            else {
                run = 0;
            }
        }
        else if ((prochain[run].priority < prochain[head].priority) && (head != 0)) {
            prochain[run].state = 'W';
            insert(run);
            run = head;
            prochain[run].state = 'R';
            head = prochain[head].next;
        }
        print();
    }
}

void timesch() { /* THE PROCESS WITH RR ALGORITHM */
    while (run != 0) {
        prochain[run].alltime -= 1;
        prochain[run].cputime += 1;
        if (prochain[run].alltime == 0) {
            prochain[run].state = 'F';
            prochain[run].next = 0;
            if (head != 0) {
                run = head;
                prochain[run].state = 'R';
                head = prochain[head].next;
            }
            else {
                run = 0;
            }
        }
        else if ((prochain[run].cputime == prochain[run].priority) && (head != 0)) {
            prochain[run].state = 'W';
            prochain[run].cputime = 0;
            insert2();
            run = head;
            prochain[run].state = 'R';
            head = prochain[head].next;
        }
        print();
    }
}