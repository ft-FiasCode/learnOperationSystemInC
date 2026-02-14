#include <stdio.h>

int main() {
    int pages, frames;
    int ref[50], frame[10], freq[10];
    int i, j, fault = 0, found, min, pos;

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter reference string:\n");
    for(i = 0; i < pages; i++)
        scanf("%d", &ref[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for(i = 0; i < frames; i++) {
        frame[i] = -1;
        freq[i] = 0;
    }

    for(i = 0; i < pages; i++) {
        found = 0;
        for(j = 0; j < frames; j++) {
            if(frame[j] == ref[i]) {
                freq[j]++;
                found = 1;
                break;
            }
        }

        if(!found) {
            pos = 0;
            min = freq[0];
            for(j = 1; j < frames; j++) {
                if(freq[j] < min) {
                    min = freq[j];
                    pos = j;
                }
            }
            frame[pos] = ref[i];
            freq[pos] = 1;
            fault++;
        }

        printf("\nFrames after %d: ", ref[i]);
        for(j = 0; j < frames; j++)
            printf("%d ", frame[j]);
    }

    printf("\nTotal Page Faults = %d\n", fault);
    return 0;
}

