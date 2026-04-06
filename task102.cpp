#include <SDL2/SDL.h>

#define M_PI 3.14159265358979323846


void fillCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius) {
    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            int dx = radius - w; 
            int dy = radius - h; 
            if ((dx * dx + dy * dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer, centerX + dx, centerY + dy);
            }
        }
    }
}


void fillCircleEfficient(SDL_Renderer* renderer, int x, int y, int radius) {
    for (int dy = -radius; dy <= radius; dy++) {
        for (int dx = -radius; dx <= radius; dx++) {
            if (dx * dx + dy * dy <= radius * radius) {
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }
}


void fillCircleOptimized(SDL_Renderer* renderer, int x, int y, int radius) {
    for (int w = 0; w < radius * 2; w++) {
        int dx = radius - w;
        int dy = (int)sqrt(radius * radius - dx * dx);
        SDL_RenderDrawLine(renderer, x + dx, y - dy, x + dx, y + dy);
    }
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO) ;

    SDL_Window* window = SDL_CreateWindow("Task 102: Filled Resetting Circle", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    int running = 1;
    SDL_Event event;
    int radius = 0;
    int maxRadius = 300;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = 0;
        }

        if (radius < maxRadius) {
            radius++; //if not max radius then increment radius 
        } else {
            radius = 0; //reset 
        }

     
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw Filled Circle (Green)
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        
        // Using horizontal lines to fill the circle efficiently
        for (int dy = -radius; dy <= radius; dy++) {
            int dx = (int)sqrt(radius * radius - dy * dy);
            SDL_RenderDrawLine(renderer, 400 - dx, 300 + dy, 400 + dx, 300 + dy);
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(10); 
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}