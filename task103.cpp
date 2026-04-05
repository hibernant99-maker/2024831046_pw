#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

struct Circle {
    float x, y;     
    float r;  //radus of circle
    SDL_Color color; 
};

bool isColliding(Circle c1, Circle c2) {
    
    float dx = c1.x - c2.x;
    float dy = c1.y - c2.y;//using pythagoras theorem
    float distance = sqrt(dx * dx + dy * dy); // If distance is less than both radii combined, they are touching
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

    Circle autoC = {0, SCREEN_HEIGHT / 2.0f, 30, {255, 255, 255, 255}};//circle that would move continously
    
    
    Circle userC = {SCREEN_WIDTH / 2.0f, 100, 30, {0, 255, 255, 255}};//the circle we have to move

    bool running = true;
    SDL_Event e;

    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) running = false;
        }

        const Uint8* keystate = SDL_GetKeyboardState(NULL);
        if (keystate[SDL_SCANCODE_UP])    userC.y -= 5;
        if (keystate[SDL_SCANCODE_DOWN])  userC.y += 5;
        if (keystate[SDL_SCANCODE_LEFT])  userC.x -= 5;
        if (keystate[SDL_SCANCODE_RIGHT]) userC.x += 5;

    
        if (userC.x - userC.r < 0) userC.x = userC.r;//circle that we can move doesnot cross left screen
        if (userC.x + userC.r > SCREEN_WIDTH) userC.x = SCREEN_WIDTH - userC.r;//circle that we use doesnot cross right screen
        
        if (userC.y - userC.r < 0) userC.y = userC.r;//circle that we can move doesnot cross left screen
        if (userC.y + userC.r > SCREEN_HEIGHT) userC.y = SCREEN_HEIGHT - userC.r;//circle that we use doesnot cross right screen


        autoC.x += 3;

        if (autoC.x - autoC.r > SCREEN_WIDTH)
        {autoC.x = -autoC.r;//if moving circle crosses the left side
        }
  
        if (isColliding(autoC, userC)) {
            autoC.color = {255, 0, 0, 255}; //if collided then color changes to red
            userC.color = {255, 0, 0, 255};
        } else {
           
            autoC.color = {255, 255, 255, 255}; 
            userC.color = {0, 255, 255, 255};//no color change
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        
   
        drawCircle(renderer, autoC);
        drawCircle(renderer, userC);

      
        SDL_RenderPresent(renderer);//show the outcomes
        
        
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}