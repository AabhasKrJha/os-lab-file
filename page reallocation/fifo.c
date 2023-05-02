#include <stdio.h> 
#include <stdbool.h>

#define MAX_PAGES 3 
#define MAX_FRAMES 4

bool isPagePresent(int page, int frames[], int size) {
    for (int i = 0; i < size; i++) {
        if (frames[i] == page) {
            return true;
        }
    }
    return false;
}
int findOldestPageIndex(int pages[], int n, int frames[], int size) {
    int oldestIndex = 0;
    int oldestPage = pages[0];
    for (int i = 1; i < n; i++) {
        if (!isPagePresent(pages[i], frames, size) && pages[i] != oldestPage) {
            return i;
        }
    }
    return oldestIndex;
}
void pageReAllocationFIFO(int pages[], int n, int frames[], int size) {
    int pageFaults = 0;
    int frameIndex = 0;
    printf("Page Re-Allocation (FIFO) Algorithm:\n");
    for (int i = 0; i < n; i++) {
        printf("Accessing Page %d\n", pages[i]);
        if (!isPagePresent(pages[i], frames, size)) {
            printf("Page Fault: Page %d not found in frames.\n", pages[i]);
            pageFaults++;
            if (frameIndex == size) {
                int oldestIndex = findOldestPageIndex(pages, n, frames, size);
                printf("Replacing Page %d with Page %d\n", frames[oldestIndex], pages[i]);
                frames[oldestIndex] = pages[i];
            } else {
                printf("Adding Page %d to Frame %d\n", pages[i], frameIndex);
                frames[frameIndex++] = pages[i];
            }
        } else {
            printf("Page %d found in frames.\n", pages[i]);
        }
        printf("Current Frames: ");
        for (int j = 0; j < frameIndex; j++) {
            printf("%d ", frames[j]);
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n", pageFaults);
}
int main() {
    int n;
    printf("Enter the number of pages : ");
    scanf("%d", &n);
    int pages[n];
    for (int i = 0; i<n; i++){
        printf("enter page value for page %d : ", i+1);
        scanf("%d", &pages[i]);
    }

    int frames[MAX_FRAMES];
    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }
    pageReAllocationFIFO(pages, n, frames, MAX_FRAMES);
    return 0;
}