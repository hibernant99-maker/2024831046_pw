#include <SDL2/SDL.h>
#include <math.h>

// Modified function to draw a FILLED circle instead of just an outline
void drawFilledCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius) {
    // We create a bounding box around the circle
    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            // Calculate distance from the center of the bounding box
            int dx = radius - w; 
            int dy = radius - h;
            
            // Pythagorean theorem: If distance squared <= radius squared, it's inside
            if ((dx * dx + dy * dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer, centerX + dx, centerY + dy);
            }
        }
    }
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    
    SDL_Window* window = SDL_CreateWindow("C Circle Task101", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    int running = 1; // In C, we often use 1 for true
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = 0;
        }

        // 1. Background Color: RED (255, 0, 0)
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderClear(renderer);

        // 2. Circle Color: GREEN (0, 255, 0)
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        
        // Use the new filled circle function
        drawFilledCircle(renderer, 400, 300, 150);

        // 3. Show the result
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}