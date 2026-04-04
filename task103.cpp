#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

struct Circle {
    float x, y, r;
    SDL_Color color;
};

// Function to calculate distance and check collision
bool isColliding(Circle c1, Circle c2) {
    float dx = c1.x - c2.x;
    float dy = c1.y - c2.y;
    float distance = sqrt(dx * dx + dy * dy);
    return distance < (c1.r + c2.r);
}

void drawCircle(SDL_Renderer* renderer, Circle c) {
    SDL_SetRenderDrawColor(renderer, c.color.r, c.color.g, c.color.b, c.color.a);
    for (int w = 0; w < c.r * 2; w++) {
        for (int h = 0; h < c.r * 2; h++) {
            int dx = (int)c.r - w;
            int dy = (int)c.r - h;
            if ((dx * dx + dy * dy) <= (c.r * c.r)) {
                SDL_RenderDrawPoint(renderer, c.x + dx, c.y + dy);
            }
        }
    }
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Task 103: Collision", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Circle autoC = {0, SCREEN_HEIGHT / 2.0f, 30, {255, 255, 255, 255}};
    Circle userC = {SCREEN_WIDTH / 2.0f, 100, 30, {0, 255, 255, 255}};

    bool running = true;
    SDL_Event e;

    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) running = false;
        }

        // 1. Handle User Input
        const Uint8* keystate = SDL_GetKeyboardState(NULL);
        if (keystate[SDL_SCANCODE_UP])    userC.y -= 5;
        if (keystate[SDL_SCANCODE_DOWN])  userC.y += 5;
        if (keystate[SDL_SCANCODE_LEFT])  userC.x -= 5;
        if (keystate[SDL_SCANCODE_RIGHT]) userC.x += 5;

        // 2. Autonomous Motion
        autoC.x += 3;
        if (autoC.x - autoC.r > SCREEN_WIDTH) autoC.x = -autoC.r;

        // 3. Collision Check & Visual Effect
        if (isColliding(autoC, userC)) {
            autoC.color = {255, 0, 0, 255}; // Turn Red
            userC.color = {255, 0, 0, 255};
        } else {
            autoC.color = {255, 255, 255, 255}; // Reset colors
            userC.color = {0, 255, 255, 255};
        }

        // 4. Rendering
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        
        drawCircle(renderer, autoC);
        drawCircle(renderer, userC);

        SDL_RenderPresent(renderer);
        SDL_Delay(16); // ~60 FPS
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}