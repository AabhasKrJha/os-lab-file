#include <stdio.h> 
#include <stdbool.h> 
#include <limits.h>

int abs(int a) {
    return (a < 0) ? -a : a;
}
int findClosest(int diskQueue[], bool visited[], int head, int n) {
    int minDist = INT_MAX;
    int closest = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && abs(diskQueue[i] - head) < minDist) {
            minDist = abs(diskQueue[i] - head);
            closest = i;
        }
    }
    return closest;
}
int main() {
    int n; // number of disk requests
    int diskQueue[100]; // array to store disk requests
    int head, seekTime = 0; // head position and seek time
    bool visited[100] = {
        false
    }; // array to keep track of visited disk requests
    printf("Enter the number of disk requests: ");
    scanf("%d", & n);
    printf("Enter the disk request queue: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", & diskQueue[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", & head);
    printf("\nSSTF Disk Scheduling:\n");
    printf("Head Movement\tSeek Time\n");
    printf("---------------------------\n");
    int totalRequests = 0;
    while (totalRequests < n) {
        int closest = findClosest(diskQueue, visited, head, n);
        if (closest == -1) {
            break;
        }
        printf("%d -> %d\t\t%d\n", head, diskQueue[closest], abs(head - diskQueue[closest]));
        seekTime += abs(head - diskQueue[closest]);
        head = diskQueue[closest];
        visited[closest] = true;
        totalRequests++;
    }
    printf("---------------------------\n");
    printf("Total Seek Time: %d\n", seekTime);
    return 0;
}