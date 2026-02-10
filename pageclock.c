#include <stdio.h>

int main() {
    int pages, frames;
    int ref[50], frame[10], use[10];
    int i, j, fault = 0, pointer = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter reference string:\n");
    for(i = 0; i < pages; i++)
        scanf("%d", &ref[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for(i = 0; i < frames; i++) {
        frame[i] = -1;
        use[i] = 0;
    }

    for(i = 0; i < pages; i++) {
        found = 0;
        for(j = 0; j < frames; j++) {
            if(frame[j] == ref[i]) {
                use[j] = 1;
                found = 1;
                break;
            }
        }

        if(!found) {
            while(use[pointer] == 1) {
                use[pointer] = 0;
                pointer = (pointer + 1) % frames;
            }
            frame[pointer] = ref[i];
            use[pointer] = 1;
            pointer = (pointer + 1) % frames;
            fault++;
        }

        printf("\nFrames after %d: ", ref[i]);
        for(j = 0; j < frames; j++)
            printf("%d ", frame[j]);
    }

    printf("\nTotal Page Faults = %d\n", fault);
    return 0;
}

