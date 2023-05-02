#include <stdio.h>

int main() {
    int n;
    int diskQueue[100];
    int head, seekTime = 0;
    printf("Enter the number of disk requests: ");
    scanf("%d", & n);
    printf("Enter the disk request queue: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", & diskQueue[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", & head);
    printf("\nFCFS Disk Scheduling:\n");
    printf("Head Movement\tSeek Time\n");
    printf("---------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> %d\t\t%d\n", head, diskQueue[i], abs(head - diskQueue[i]));
        seekTime += abs(head - diskQueue[i]);
        head = diskQueue[i];
    }
    printf("---------------------------\n");
    printf("Total Seek Time: %d\n", seekTime);
    return 0;
}