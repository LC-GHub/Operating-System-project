#include <stdio.h>
#include <stdlib.h>
#define MAX 60

void FIFO();


int main(void){
    int choice;
    printf("Select Page Replacement Algorithm: \n 1) FIFO \n"
           " 2) Optimal page replacement algorithm \n "
           "3) LRU page replacement algorithm");
    printf("\nYour preferred algorithm: \n");
    scanf("%d", &choice);

    if(choice == 1)
    {
        //printf("FIFO");
        FIFO();
    }else if(choice == 2){
        printf("Optimal");
    }else if (choice == 3){
        printf("LRU");
    }
    else{
        printf("Please enter a valid choice");
    }


    return 0;


    
}

void FIFO(){
    int frame_count;
    int i = 0;
    int memFramePointer = 0;
    int step = 1;
    int pagefault = 0;
    printf("Number of memory frames: \n");
    scanf("%d", &frame_count);
    int memoryFrame[frame_count];
    char referenceString[MAX];
    //initialize all elements to -1
    for (int i = 0; i<frame_count; i++){

        memoryFrame[i] = -1; 

    }

    printf("Enter reference string (size 20-30): ");
    fflush(stdin);
    fgets(referenceString,100,stdin);
    //scanf("%s", referenceString);

    while(referenceString[i] != '\000' && referenceString[i] != '\n'){
        if(referenceString[i] != ',' && referenceString[i] != ' '){
            for(int y= 0; y < frame_count; y++){
                if(memoryFrame[y] == referenceString[i] - '0'){
                    goto increment;
                }
            }

            if(memFramePointer < 3){
                int ConvertToInt = (referenceString[i] - '0');
                memoryFrame[memFramePointer] = ConvertToInt;
                pagefault++;
                memFramePointer++;
                printf("Step %d: %d %d %d \n", step, memoryFrame[0], memoryFrame[1], memoryFrame[2]);
                step++;
            }else{
                memFramePointer = 0;
                int ConvertToInt = (referenceString[i] - '0');
                memoryFrame[memFramePointer] = ConvertToInt;
                pagefault++;
                memFramePointer++;
                printf("Step %d: %d %d %d \n", step, memoryFrame[0], memoryFrame[1], memoryFrame[2]);
                step++;
            }

            
        }

        increment: i++;
    }

    printf("There are %d page faults in this page replacement found", pagefault);
    
    




}