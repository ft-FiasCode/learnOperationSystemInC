#include <stdio.h>

int findLRU(int time[], int n) {
    int i, min = time[0], pos = 0;
    for(i = 1; i < n; i++) {
        if(time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int pages, frames;
    int ref[50], frame[10], time[10];
    int i, j, fault = 0, found, counter = 0;

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
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }

        if(!found) {
            int pos;
            for(j = 0; j < frames; j++) {
                if(frame[j] == -1) {
                    pos = j;
                    break;
                }
            }

            if(j == frames)
                pos = findLRU(time, frames);

            counter++;
            frame[pos] = ref[i];
            time[pos] = counter;
            fault++;
        }

        printf("\nFrames after %d: ", ref[i]);
        for(j = 0; j < frames; j++)
            printf("%d ", frame[j]);
    }

    printf("\nTotal Page Faults = %d\n", fault);
    return 0;
}

