#include <stdio.h>

void LenghtyTask(void (*pInform)(int));
void Inform(int percentage);

int main()
{
    LenghtyTask(&Inform);
    return 0;
}

// Counts from 0 to billion
void LenghtyTask(void (*pInform)(int)) 
{
    int billion = 1000000000;
    double percentToInform[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100};
    int length = sizeof(percentToInform) / sizeof(percentToInform[0]);
    
    for (int i = 0; i <= billion; i++) {
        double percentage = (double) i / billion * 100;        
        // jos prosentti on kokonaisluku
        if (i % (billion / 100) == 0) {
            for (int j = 0; j < length; j++) {
                if (percentage == percentToInform[j]) {
                    (*pInform)((int) percentage);
                }
            }
        }
    }
}

void Inform(int percentage)
{
    printf("%d %% executed\n", percentage);
}