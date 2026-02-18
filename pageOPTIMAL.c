#include <stdio.h>

int main() {
    int pages, frames;
    int ref[50], frame[10];
    int i, j, k, fault = 0, found, farthest, pos;

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter reference string:\n");
    for(i = 0; i < pages; i++)
        scanf("%d", &ref[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for(i = 0; i < frames; i++)
        frame[i] = -1;

    for(i = 0; i < pages; i++) {
        found = 0;
        for(j = 0; j < frames; j++) {
            if(frame[j] == ref[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            if(i < frames) {
                frame[i] = ref[i];
            } else {
                farthest = i + 1;
                pos = 0;

                for(j = 0; j < frames; j++) {
                    for(k = i + 1; k < pages; k++) {
                        if(frame[j] == ref[k])
                            break;
                    }
                    if(k > farthest) {
                        farthest = k;
                        pos = j;
                    }
                }
                frame[pos] = ref[i];
            }
            fault++;
        }

        printf("\nFrames after %d: ", ref[i]);
        for(j = 0; j < frames; j++)
            printf("%d ", frame[j]);
    }

    printf("\nTotal Page Faults = %d\n", fault);
    return 0;
}

