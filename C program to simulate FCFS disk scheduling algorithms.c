#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, head, i, total_movement = 0;
    float avg_movement;
    printf("Enter the number of tracks: ");
    scanf("%d", &n);
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    int tracks[n];
    printf("Enter the track positions:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &tracks[i]);
    }

    printf("The sequence of movement of the disk head is:\n");
    printf("%d", head);
    total_movement += abs(head - tracks[0]);
    for(i = 0; i < n; i++) {
        printf(" -> %d", tracks[i]);
        if(i+1 < n) {
            total_movement += abs(tracks[i] - tracks[i+1]);
        }
    }

    avg_movement = (float) total_movement / n;
    printf("\n\nThe total head movement is: %d\n", total_movement);
    printf("The average head movement is: %.2f\n", avg_movement);
    return 0;
}
