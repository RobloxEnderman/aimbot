#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <windows.h>
#include <math.h>
#include <time.h>
int main() {
    printf("Aimbot by Jaxson\n");
    printf("Press Ctrl+C to exit\n");
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];
    portno = 1337;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("ERROR opening socket");
    }
    server = gethostbyname("");
    if (server == NULL) {
        printf("ERROR, no such host");
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        printf("ERROR connecting");
    }
    while(1) {
        bzero(buffer,256);
        n = read(sockfd,buffer,255);
        if (n < 0) {
            printf("ERROR reading from socket");
        }
        if (strcmp(buffer, "exit") == 0) {
            printf("Exiting...");
            break;
        }
        if (strcmp(buffer, "aim") == 0) {
            printf("Aiming...");
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        }
        if (strcmp(buffer, "shoot") == 0) {
            printf("Shooting...");
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        }
        if (strcmp(buffer, "reload") == 0) {
            printf("Reloading...");
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        }
        if (strcmp(buffer, "jump") == 0) {
            printf("Jumping...");
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        }
        if (strcmp(buffer, "crouch") == 0) {
            printf("Crouching...");
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        }
        if (strcmp(buffer, "prone") == 0) {
            printf("Prone...");
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        }
        if (strcmp(buffer, "flash") == 0) {
            printf("Flashing...");
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        }
        if (strcmp(buffer, "smoke") == 0) {
            printf("Smoking...");
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        }
        scanf("%s", buffer);
        n = write(sockfd,buffer,strlen(buffer));
        if (n < 0) {
            printf("ERROR writing to socket");
        }
        return 0;
}
