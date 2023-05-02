#include <stdlib.h>

#include <stdio.h>
 // Comparison function for qsort()
int cmpfunc(const void * a,
    const void * b) {
    return ( * (int * ) a - * (int * ) b);
}
int main() {
    int i, j, k, n, m, sum = 0, x, y, h;
    printf("Enter the size of disk: ");
    scanf("%d", & m);
    printf("Enter number of requests: ");
    scanf("%d", & n);
    printf("Enter the requests: ");
    int a[n], b[3 * n];
    for (i = 0; i < n; i++) {
        scanf("%d", & a[i]);
    }
    for (i = 0; i < n; i++) {
        if (a[i] > m) {
            printf("Error, Unknown position %d\n", a[i]);
            return 0;
        }
    }
    printf("Enter the head position: ");
    scanf("%d", & h);
    int temp = h;
    a[n] = h;
    a[n + 1] = m;
    a[n + 2] = 0;
    qsort(a, n + 3, sizeof(int), cmpfunc);
    for (i = 0; i < n + 3; i++) {
        if (h == a[i]) break;
    }
    k = i;
    if (k < n / 2) {
        for (i = k; i < n + 3; i++) {
            b[i - k] = a[i];
        }
        for (i = k - 1; i >= 0; i--) {
            b[n + 2 - k + i] = a[i];
        }
    } else {
        for (i = k; i >= 0; i--) {
            b[k - i] = a[i];
        }
        for (i = k + 1; i < n + 3; i++) {
            b[n + 2 - i + k] = a[i];
        }
    }
    temp = b[0];
    printf("%d", temp);
    for (i = 1; i < n + 3; i++) {
        printf(" -> %d", b[i]);
        sum += abs(b[i] - temp);
        temp = b[i];
    }
    printf("\n");
    printf("Total head movements = %d\n", sum);
    printf("Average head movement = %.2f\n", (float) sum / n);
    return 0;
}