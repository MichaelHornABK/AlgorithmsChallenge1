#include <iostream>
#include <stdlib.h> 
#include <chrono>

uint32_t GetNanos();
void FillArray(int arrayToFill[], int sizeOfArray);
void BubbleSort(int arrayToSort[], int sizeOfArray);
void PrintArray(int arrayToPrint[], int sizeOfArray);

int main()
{
    int sizeOfArray;
    std::cout << "What size of array do you want? ";
    std::cin >> sizeOfArray;
    int* dataset = new int[sizeOfArray];

    srand(time(0));

    FillArray(dataset, sizeOfArray);
    PrintArray(dataset, sizeOfArray);

    uint32_t startNanos = GetNanos();
    BubbleSort(dataset, sizeOfArray);
    uint32_t endNanos = GetNanos();

    std::cout << std::endl << std::endl;
    PrintArray(dataset, sizeOfArray);
    std::cout << std::endl << std::endl;

    std::cout << "The bubble sort took " << (endNanos - startNanos) << " nanoseconds." << std::endl;
}

uint32_t GetNanos()
{
    using namespace std::chrono;
    return static_cast<uint32_t>(duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count());
}

void PrintArray(int arrayToPrint[], int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; i++)
    {
        std::cout << arrayToPrint[i] << ", ";
    }
}

void FillArray(int arrayToFill[], int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; i++)
    {
        arrayToFill[i] = rand() % sizeOfArray + 1;
    }
}

void BubbleSort(int arrayToSort[], int sizeOfArray)
{
    for (int pass = 0; pass < sizeOfArray; pass++)
    {
        for (int i = 0; i < sizeOfArray - 1; i++)
        {
            if (arrayToSort[i] > arrayToSort[i + 1])
            {
                int temp = arrayToSort[i];

                arrayToSort[i] = arrayToSort[i + 1];

                arrayToSort[i + 1] = temp;
            }
        }
    }
}
