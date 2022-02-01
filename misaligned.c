#include <stdio.h>
#include <assert.h>
#include <string.h>


const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
const char* majorColorMem[25]; 
const char* minorColorMem[25];
unsigned char pairNumberMem[25];


void printColor(unsigned int minorColorIndex, unsigned int majorColorIndex)
{
    unsigned char pairNumber = (majorColorIndex * 5 + minorColorIndex) +1;
    
    printf("%3d ",pairNumber);
    pairNumberMem[pairNumber-1] = pairNumber;
    printf("|%-8s",majorColor[majorColorIndex]);
    majorColorMem[pairNumber-1] = majorColor[majorColorIndex];
    printf("|%-8s\n",minorColor[minorColorIndex]);
    minorColorMem[pairNumber-1] = minorColor[minorColorIndex];
}

void ColorMap(void) {
    unsigned int l_majorColorIndex = 0;
    unsigned int l_minorColorIndex = 0;
    for(l_majorColorIndex = 0; l_majorColorIndex < 5;l_majorColorIndex++) {
        for(l_minorColorIndex = 0;l_minorColorIndex < 5; l_minorColorIndex++) {
            printColor(l_minorColorIndex,l_majorColorIndex);
        }
    }
}

int main() {
    /*test*/
    
    printf("Start of Test\n");
    printf("Test case 1 White and Blue print\n");
    printColor(0, 0);
    assert(pairNumberMem[0] == 1);
    
    assert(strcmp(majorColorMem[0],"White") == 0);
    assert(strcmp(minorColorMem[0],"Blue") == 0);
    
    printf("Test case 2 White and Slate print\n");
    printColor(4, 0);
    assert(pairNumberMem[4] == 5);
    assert(strcmp(majorColorMem[0],"White") == 0);
    assert(strcmp(minorColorMem[0],"Slate") == 0);
    
    printf("Test case 3 Violet and Blue print\n");
    printColor(0, 4);
    assert(pairNumberMem[20] == 21);
    assert(strcmp(majorColorMem[0],"Violet") == 0);
    assert(strcmp(minorColorMem[0],"Blue") == 0);
    
    printf("Test case 4 Violet and Slate print\n");
    printColor(4, 4);
    assert(pairNumberMem[24] == 25);
    assert(strcmp(majorColorMem[0],"Violet") == 0);
    assert(strcmp(minorColorMem[0],"Slate") == 0);
    
    
    printf("End of Test\n\n");
    
    ColorMap();
    return 0;
}
