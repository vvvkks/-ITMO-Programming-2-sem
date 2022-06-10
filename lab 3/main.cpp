#include <iostream>
#include "buffer.h"
#include "curc.h"
#include <algorithm>

int main() {
    Circle<int> CircleBuffer(6);
    Circle<int>::Iterator it = CircleBuffer.Begin();
    for (int i = 1; i <= 10; i++) {
        CircleBuffer.Push_Front(i);
    }
    std::cout << "Buffer state with iterator: ";
    for (it = CircleBuffer.Begin(); it != CircleBuffer.End(); it++) {
        std::cout << *it << " ";
    }
    std::cout << *CircleBuffer.End() << std::endl;
    std::cout << "Add first element:\n";
    CircleBuffer.Push_Back(3);
    for (int i = 0; i < CircleBuffer.Size(); i++)
        std::cout << CircleBuffer[i] << " ";

    std::cout << "\n Add last element:\n";
    CircleBuffer.Push_Front(5);
    for (int i = 0; i < CircleBuffer.Size(); i++)
        std::cout << CircleBuffer[i] << " ";

    std::cout << "\n Delete first element:\n";
    CircleBuffer.Pop_Front();
    for (int i = 0; i < CircleBuffer.Size(); i++)
        std::cout << CircleBuffer[i] << " ";

    std::cout << "\nDelete last element:\n";
    CircleBuffer.Pop_Back();
    for (int i = 0; i < CircleBuffer.Size(); i++)
        std::cout << CircleBuffer[i] << " ";

    std::cout << "\nDelete all elements with iterator:\n";
    it = CircleBuffer.Begin();
    while (!CircleBuffer.Is_Empty()) {
        CircleBuffer.Delete(it);
        it++;
    }
    for (int i = 0; i < CircleBuffer.Size(); i++)
        std::cout << CircleBuffer[i] << " ";
    std::cout << std::endl;
    std::cout << "Buffer size: ";
    std::cout << CircleBuffer.Capacity();
    std::cout << "\nBuffer resize to 10\n";
    CircleBuffer.Resize(10);


    std::cout << "Insert new numbers: \n";
    for (int i = 1; i <= 10; i++) {
        CircleBuffer.Push_Back(i);
    }
    for (int i = 0; i < CircleBuffer.Size(); i++)
        std::cout << CircleBuffer[i] << " ";
    std::cout << std::endl;


    std::cout << "Replace elements:\n";
    *(CircleBuffer.Begin()) = -7;
    *(CircleBuffer.End()) = -9;
    CircleBuffer.Push(it, 7);
    for (int i = 0; i < CircleBuffer.Size(); i++)
        std::cout << CircleBuffer[i] << " ";
    std::cout << std::endl;

return 0;
}
