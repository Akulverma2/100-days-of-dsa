#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int sum = 0, count = 0;
    int hash[2 * MAX + 1] = {0};
    int offset = MAX;
    hash[offset] = 1;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        if(hash[sum + offset] > 0) {
            count += hash[sum + offset];
        }
        hash[sum + offset]++;
    }
    printf("%d", count);

    return 0;
}