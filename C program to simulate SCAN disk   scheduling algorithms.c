#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, head, i, j, temp, pos, total_movement = 0;
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

    // Sorting the tracks in ascending order
    for(i = 0; i < n; i++) {
        pos = i;
        for(j = i+1; j < n; j++) {
            if(tracks[j] < tracks[pos]) {
                pos = j;
            }
        }
        temp = tracks[i];
        tracks[i] = tracks[pos];
        tracks[pos] = temp;
    }

    // Finding the index of the head position in the sorted array
    for(i = 0; i < n; i++) {
        if(tracks[i] > head) {
            break;
        }
    }

    printf("The sequence of movement of the disk head is:\n");
    if(i == n) {
        // Head is at the end of the disk, moving towards lower tracks
        for(j = i-1; j >= 0; j--) {
            printf("%d -> ", tracks[j]);
            total_movement += abs(head - tracks[j]);
            head = tracks[j];
        }
        for(j = i; j < n; j++) {
            printf("%d -> ", tracks[j]);
            total_movement += abs(head - tracks[j]);
            head = tracks[j];
        }
    } else if(i == 0) {
        // Head is at the beginning of the disk, moving towards higher tracks
        for(j = i; j < n; j++) {
            printf("%d -> ", tracks[j]);
            total_movement += abs(head - tracks[j]);
            head = tracks[j];
        }
        for(j = i-1; j >= 0; j--) {
            printf("%d -> ", tracks[j]);
            total_movement += abs(head - tracks[j]);
            head = tracks[j];
        }
    } else {
        // Head is in the middle of the disk, moving towards higher tracks
        for(j = i; j < n; j++) {
            printf("%d -> ", tracks[j]);
            total_movement += abs(head - tracks[j]);
            head = tracks[j];
        }
        for(j = i-1; j >= 0; j--) {
            printf("%d -> ", tracks[j]);
            total_movement += abs(head - tracks[j]);
            head = tracks[j];
        }
    }

    avg_movement = (float) total_movement / n;
    printf("\n\nThe total head movement is: %d\n", total_movement);
    printf("The average head movement is: %.2f\n", avg_movement);
    return 0;
}
