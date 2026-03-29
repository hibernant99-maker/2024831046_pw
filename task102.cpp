#include <SDL2/SDL.h>
#include <cmath>

void drawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius) {
    for (int i = 0; i < 360; i++) {
        double angle = i * M_PI / 180.0;
        int x = centerX + static_cast<int>(radius * std::cos(angle));
        int y = centerY + static_cast<int>(radius * std::sin(angle));
        SDL_RenderDrawPoint(renderer, x, y);
    }
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Task 102: Expanding Circle", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool running = true;
    SDL_Event event;
    
    int radius = 0; // Starts at 0
    int maxRadius = 300; // Limit (half of height)

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;
        }

        // --- TASK 102 LOGIC ---
        if (radius < maxRadius) {
            radius++; // Increase radius each frame
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        drawCircle(renderer, 400, 300, radius);

        SDL_RenderPresent(renderer);
        SDL_Delay(10); // Controls the speed of expansion
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}