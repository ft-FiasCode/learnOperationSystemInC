#include <stdio.h>

int main() {
    int pages, frames;
    int ref[50], frame[10], recent[10];
    int i, j, fault = 0, found, counter = 0;

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter reference string:\n");
    for(i = 0; i < pages; i++)
        scanf("%d", &ref[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    // Initialize frames
    for(i = 0; i < frames; i++) {
        frame[i] = -1;
        recent[i] = 0;
    }

    for(i = 0; i < pages; i++) {
        found = 0;

        // Check if page already exists
        for(j = 0; j < frames; j++) {
            if(frame[j] == ref[i]) {
                counter++;
                recent[j] = counter;
                found = 1;
                break;
            }
        }

        // Page fault
        if(!found) {
            int pos = 0, max = recent[0];

            // Find most recently used page
            for(j = 1; j < frames; j++) {
                if(recent[j] > max) {
                    max = recent[j];
                    pos = j;
                }
            }

            counter++;
            frame[pos] = ref[i];
            recent[pos] = counter;
            fault++;
        }

        // Display frame content
        printf("\nFrames after %d: ", ref[i]);
        for(j = 0; j < frames; j++)
            printf("%d ", frame[j]);
    }

    printf("\nTotal Page Faults = %d\n", fault);
    return 0;
}

