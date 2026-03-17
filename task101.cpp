#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {
    // 1. Your C++ logic can go here
    std::cout << "Addin Ahmed Digonto" << std::endl;
    std::cout << "Sum: " << 8 + 7 << " Division: " << 6 / 4 << std::endl;

    // 2. SDL2 Window Setup
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("My C++ Task", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

    if (window) {
        // This keeps the window open for 2 seconds
        SDL_Delay(2000); 
        SDL_DestroyWindow(window);
    }

    SDL_Quit();
    return 0;
}