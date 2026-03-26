#include <SDL2/SDL.h>
#include <cmath> // Required for sin() and cos()

// Function to draw the outline of a circle
void drawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius) {
    for (int i = 0; i < 360; i++) {
        // Convert degrees to radians
        double angle = i * M_PI / 180;
        int x = centerX + static_cast<int>(radius * cos(angle));
        int y = centerY + static_cast<int>(radius * sin(angle));
        SDL_RenderDrawPoint(renderer, x, y);
    }
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    
    SDL_Window* window = SDL_CreateWindow("C++ Circle Task", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;
        }

        // 1. Background Color (Black)
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // 2. Circle Color (Green)
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        
        // Draw circle at center (400, 300) with radius 150
        drawCircle(renderer, 400, 300, 150);

        // 3. Show the result
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}