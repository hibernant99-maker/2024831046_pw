#include <SDL2/SDL.h>
#include <math.h>

void drawFilledCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius) {
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

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    
    int screenWidth = 800;
    int screenHeight = 600;

    SDL_Window* window = SDL_CreateWindow("Growing & Resetting Circle", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, 0);
    
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    int running = 1;
    SDL_Event event;

    
    int radius = 30;
    int centerX = screenWidth / 2; 
    int centerY = screenHeight / 2; 
    

    int maxRadius = (screenHeight / 2); 

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = 0;
        }

    
        radius += 2; // Increasing the radius

        if (radius >= maxRadius) {
            radius = 30; // Reset after it reaches width or height
        }

     
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);//background black
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);//circle color green
        
       
        drawFilledCircle(renderer, centerX, centerY, radius);

        SDL_RenderPresent(renderer);
        
      
        SDL_Delay(10); 
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0; 
}