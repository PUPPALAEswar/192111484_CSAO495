#include <stdio.h>
#include <sys/msg.h>
struct message { long mtype; char mtext[255]; } msg;
int main() {
    int msgid = msgget(ftok("/tmp/msg.temp", 1), 0666 | IPC_CREAT);
    printf("Enter a message to send: ");
    fgets(msg.mtext, 255, stdin);
    msg.mtext[strcspn(msg.mtext, "\n")] = 0;
    msg.mtype = 1;
    msgsnd(msgid, &msg, sizeof(msg), 0);
    msgrcv(msgid, &msg, sizeof(msg), 0, 0);
    printf("Received: %s\n", msg.mtext);
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}
