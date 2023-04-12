#include <iostream>
#include <string>
#include <fstream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <json/json.h>

int main(void) {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    // Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    
    // Mix_Chunk* Mix_ChunkMix_Chunk = Mix_LoadWAV("resources/menu.mp3");
    // Mix_PlayChannel(-1, Mix_ChunkMix_Chunk, 0); SDL_Delay(4000);
    // Mix_FreeChunk(Mix_ChunkMix_Chunk);

    SDL_Window* SDL_WindowWindow = SDL_CreateWindow("hugaxyu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* SDL_RendererRenderer =  SDL_CreateRenderer(SDL_WindowWindow, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event SDL_EventEvent;

    int intLocation = 1, intPlayerAnimation = 0, intPositionX = 0, intPositionY = 0, intTrigger = 0, intZoom = 1, intMouseX = 0, intMouseY = 0;
    std::string stringText = "";

    TTF_Font* TTF_FontFont = TTF_OpenFont("resources/arial.ttf", 15);
    if (TTF_FontFont == nullptr) {
        std::cerr << "Error loading font" << std::endl;
        SDL_WindowWindow = nullptr;
    }

    SDL_Surface* SDL_SurfaceLocation = IMG_Load("resources/location.png");
    if (SDL_SurfaceLocation == nullptr) {
        std::cerr << "Error loading location" << std::endl;
        SDL_WindowWindow = nullptr;
    }

    SDL_Surface* SDL_SurfacePlayer = IMG_Load("resources/player.png");
    if (SDL_SurfaceLocation == nullptr) {
        std::cerr << "Error loading player" << std::endl;
        SDL_WindowWindow = nullptr;
    }

    SDL_Surface* SDL_SurfaceDialog = IMG_Load("resources/dialog.png");
    if (SDL_SurfaceDialog == nullptr) {
        std::cerr << "Error loading player" << std::endl;
        SDL_WindowWindow = nullptr;
    }

    while (SDL_WindowWindow != nullptr && SDL_RendererRenderer != nullptr) {
        if (intLocation == 2) {
            if (intPositionY < 336) {
                intPositionY = intPositionY + 5;
            } else if (intPositionY > 563) {
                intPositionY = intPositionY - 5;
                // Mix_Chunk* Mix_ChunkMix_Chunk = Mix_LoadWAV("resources/zxc.mp3");
                // Mix_PlayChannel(-1, Mix_ChunkMix_Chunk, 0); SDL_Delay(2000);
                // Mix_FreeChunk(Mix_ChunkMix_Chunk);
            } else if (intPositionX < -18) {
                intLocation = 4;
                intPositionX = 800;
            } else if (intPositionX > 818) {
                intPositionX = 0;
                intLocation = 3;
            } else if (intPositionX > 53 && intPositionX < 53 + 100 && intPositionY > 515 && intPositionY < 515 + 50 && intTrigger == 6) {
                intTrigger = intTrigger + 1;
            } else if (intPositionX > 229 && intPositionX < 229 + 57 && intPositionY > 339 && intPositionY < 339 + 16 && intTrigger == 12) {
                intTrigger = intTrigger + 1;
            }
        } else if (intLocation == 3) {
            if (intPositionY < 336) {
                intPositionY = intPositionY + 5;
            } else if (intPositionY > 563) {
                intPositionY = intPositionY - 5;
                // Mix_Chunk* Mix_ChunkMix_Chunk = Mix_LoadWAV("resources/zxc.mp3");
                // Mix_PlayChannel(-1, Mix_ChunkMix_Chunk, 0); SDL_Delay(2000);
                // Mix_FreeChunk(Mix_ChunkMix_Chunk);
            } else if (intPositionX < -18) {
                intLocation = 2;
                intPositionX = 800;
            } else if (intPositionX > 818) {
                intPositionX = 0;
                intLocation = 4;
            } else if (intPositionX > 682 && intPositionX < 682 + 100 && intPositionY > 320 && intPositionY < 320 + 50) {
                if (intTrigger == 1) { intTrigger = 2; }
                // Mix_Chunk* Mix_ChunkMix_Chunk = Mix_LoadWAV("resources/1.mp3");
                // Mix_PlayChannel(-1, Mix_ChunkMix_Chunk, 0); SDL_Delay(4000);
                // Mix_FreeChunk(Mix_ChunkMix_Chunk);
                intPositionX = 0;
                intPositionY = 427;
                intLocation = 6;
            }
        } else if (intLocation == 4) {
            if (intPositionY < 336) {
                intPositionY = intPositionY + 5;
            } else if (intPositionY > 563) {
                intPositionY = intPositionY - 5;
                // Mix_Chunk* Mix_ChunkMix_Chunk = Mix_LoadWAV("resources/zxc.mp3");
                // Mix_PlayChannel(-1, Mix_ChunkMix_Chunk, 0); SDL_Delay(2000);
                // Mix_FreeChunk(Mix_ChunkMix_Chunk);
            } else if (intPositionX < -18) {
                intLocation = 3;
                intPositionX = 800;
            } else if (intPositionX > 818) {
                intPositionX = 0;
                intLocation = 2;
            } else if (intPositionX > 236 && intPositionX < 236 + 52 && intPositionY > 320 && intPositionY < 320 + 50 && intTrigger == 4) {
                intTrigger = intTrigger + 1;
            } else if (intPositionX > 236 && intPositionX < 236 + 52 && intPositionY > 320 && intPositionY < 320 + 50 && intTrigger == 8) {
                intTrigger = intTrigger + 1;
            } else if (intPositionX > 372 && intPositionX < 372 + 71 && intPositionY > 435 && intPositionY < 435 + 80 && intTrigger == 10) {
                intTrigger = intTrigger + 1;
            } else if (intPositionX > 372 && intPositionX < 372 + 71 && intPositionY > 435 && intPositionY < 435 + 80 && intTrigger == 10) {
                intTrigger = intTrigger + 1;
            } else if (intPositionX > 372 && intPositionX < 372 + 71 && intPositionY > 435 && intPositionY < 435 + 80 && intTrigger == 14) {
                intTrigger = intTrigger + 1;
            }
        } else if (intLocation == 6) {
            if (intPositionY < 416) {
                intPositionY = intPositionY + 5;
            } else if (intPositionY > 467) {
                intPositionY = intPositionY - 5;
            } else if (intPositionX < -18) {
                // Mix_Chunk* Mix_ChunkMix_Chunk = Mix_LoadWAV("resources/1.mp3");
                // Mix_PlayChannel(-1, Mix_ChunkMix_Chunk, 0); SDL_Delay(4000);
                // Mix_FreeChunk(Mix_ChunkMix_Chunk);
                intLocation = 3;
                intPositionX = 671;
                intPositionY = 383;
            } else if (intPositionX > 818) {
                // Mix_Chunk* Mix_ChunkMix_Chunk = Mix_LoadWAV("resources/1.mp3");
                // Mix_PlayChannel(-1, Mix_ChunkMix_Chunk, 0); SDL_Delay(4000);
                // Mix_FreeChunk(Mix_ChunkMix_Chunk);
                intLocation = 3;
                intPositionX = 671;
                intPositionY = 383;
            } else if (intPositionX > 529 && intTrigger == 16) {
                intTrigger = intTrigger + 1;
            }
        } else if (intLocation == 7) {
            SDL_Delay(3000);
            intLocation = 1;
        }

        while (SDL_PollEvent(&SDL_EventEvent) != 0) {
            switch (SDL_EventEvent.type) {
                case SDL_QUIT: SDL_WindowWindow = nullptr; break;
                case SDL_KEYDOWN: if (SDL_EventEvent.key.keysym.sym == SDLK_ESCAPE) {
                    Json::Value ValueJson;
                    std::ofstream ofstreamJson("save.json");
                    if (ofstreamJson.is_open() == true) {
                        ValueJson["save"]["intLocation"] = intLocation;
                        ValueJson["save"]["intTrigger"] = intTrigger;
                        ValueJson["save"]["intPositionX"] = intPositionX;
                        ValueJson["save"]["intPositionY"] = intPositionY;
                        ValueJson["save"]["stringText"] = stringText;
                        ofstreamJson << ValueJson;
                        ofstreamJson.close();
                        intLocation = 1;
                    } else if (ofstreamJson.is_open() == false) {
                        std::cerr << "resources damaged!" << std::endl;
                        SDL_WindowWindow = nullptr;
                    }
                } else if (intTrigger == 0 || intTrigger == 2 || intTrigger == 3 || intTrigger == 5 || intTrigger == 7 || intTrigger == 9 || intTrigger == 11 || intTrigger == 13 || intTrigger == 15 || intTrigger == 17) { break; }
                switch (SDL_EventEvent.key.keysym.sym) {
                    case SDLK_w: intPositionY = intPositionY - 5; break;
                    case SDLK_s: intPositionY = intPositionY + 5; break;
                    case SDLK_a: intPositionX = intPositionX - 5; break;
                    case SDLK_d: intPositionX = intPositionX + 5; break;
                } break;
                case SDL_MOUSEBUTTONDOWN: if (intLocation == 1) {
                    SDL_GetMouseState(&intMouseX, &intMouseY);

                    if (intMouseX > 471 && intMouseX < 471 + 329 && intMouseY > 65 && intMouseY < 65 + 112) {
                        stringText = "Тоха: Надо бы за энергетосом сходить. (WASD - ходить ESC - сохранение + меню)";
                        intLocation = 2;
                        intTrigger = 0;
                        intPositionX = 541;
                        intPositionY = 349;
                        intZoom = 1;
                    } else if (intMouseX > 471 && intMouseX < 471 + 329 && intMouseY > 65 && intMouseY < 208 + 112) {
                        std::ifstream ifstreamJson("save.json");
                        if (ifstreamJson.is_open() == true) {
                            Json::Value ValueJson; ifstreamJson >> ValueJson;
                            ifstreamJson.close();

                            intLocation = ValueJson["save"]["intLocation"].asInt();
                            intTrigger = ValueJson["save"]["intTrigger"].asInt();
                            intPositionX = ValueJson["save"]["intPositionX"].asInt();
                            intPositionY = ValueJson["save"]["intPositionY"].asInt();
                            stringText = ValueJson["save"]["stringText"].asString();
                            intZoom = 1;
                        } else if (ifstreamJson.is_open() == false) {
                            std::cerr << "resources damaged!" << std::endl;
                        }
                    } else if (intMouseX > 471 && intMouseX < 471 + 329 && intMouseY > 65 && intMouseY < 351 + 112) {
                        std::cerr << "resources damaged!" << std::endl;
                        SDL_WindowWindow = nullptr;
                    }
                } else if (intLocation != 1 && intTrigger == 0) {
                    // Mix_Chunk* Mix_ChunkMix_Chunk = Mix_LoadWAV("resources/0.mp3");
                    // Mix_PlayChannel(-1, Mix_ChunkMix_Chunk, 0); SDL_Delay(2000);
                    // Mix_FreeChunk(Mix_ChunkMix_Chunk);
                    intTrigger = intTrigger + 1;
                    stringText = "Тоха: Блин я деньги забыл <_>";
                } else if (intLocation != 1 && intTrigger == 2) { 
                    // Mix_Chunk* Mix_ChunkMix_Chunk = Mix_LoadWAV("resources/2.ogg");
                    // Mix_PlayChannel(-1, Mix_ChunkMix_Chunk, 0); SDL_Delay(5000);
                    // Mix_FreeChunk(Mix_ChunkMix_Chunk);
                    intTrigger = intTrigger + 1;
                    stringText = "Тоха: Нужно отыскать Саню мб он дома.";
                } else if (intLocation != 1 && intTrigger == 3) {
                    // Mix_Chunk* Mix_ChunkMix_Chunk = Mix_LoadWAV("resources/3.ogg");
                    // Mix_PlayChannel(-1, Mix_ChunkMix_Chunk, 0); SDL_Delay(2000);
                    // Mix_FreeChunk(Mix_ChunkMix_Chunk);
                    intTrigger = intTrigger + 1;
                    stringText = "Тоха: Саня дай денег в долг пж Саня: Хорошо, сходи мне за шавой и дам";
                } else if (intLocation != 1 && intTrigger == 5) {
                    // Mix_Chunk* Mix_ChunkMix_Chunk = Mix_LoadWAV("resources/5.ogg");
                    // Mix_PlayChannel(-1, Mix_ChunkMix_Chunk, 0); SDL_Delay(15000);
                    // Mix_FreeChunk(Mix_ChunkMix_Chunk);
                    intTrigger = intTrigger + 1;
                    stringText = "Тоха: Дай-те пожалуйста шаву за 200. Костя: Все будет еже брат. Тоха: Спасибо";
                } else if (intLocation != 1 && intTrigger == 7) {
                    // Mix_Chunk* Mix_ChunkMix_Chunk = Mix_LoadWAV("resources/7.ogg");
                    // Mix_PlayChannel(-1, Mix_ChunkMix_Chunk, 0); SDL_Delay(16000);
                    // Mix_FreeChunk(Mix_ChunkMix_Chunk);
                    intTrigger = intTrigger + 1;
                    stringText = "Саня: Спасибо за шаву деньги у Дисы. Тоха: Да пошел ты нахуй";
                } else if (intLocation != 1 && intTrigger == 9) { 
                    // Mix_Chunk* Mix_ChunkMix_Chunk = Mix_LoadWAV("resources/9.ogg");
                    // Mix_PlayChannel(-1, Mix_ChunkMix_Chunk, 0); SDL_Delay(11000);
                    // Mix_FreeChunk(Mix_ChunkMix_Chunk);
                    intTrigger = intTrigger + 1;
                    stringText = "Тоха: Меня Саня до тебя отправил сказал деньги у тебя. Диса: Принеси мне закладку она у надписи Диса Лох и дам тебе денег";
                } else if (intLocation != 1 && intTrigger == 11) { 
                    // Mix_Chunk* Mix_ChunkMix_Chunk = Mix_LoadWAV("resources/11.ogg");
                    // Mix_PlayChannel(-1, Mix_ChunkMix_Chunk, 0); SDL_Delay(5000);
                    // Mix_FreeChunk(Mix_ChunkMix_Chunk);
                    intTrigger = intTrigger + 1;
                    stringText = "Тоха: О а вот и она";
                } else if (intLocation != 1 && intTrigger == 13) { 
                    // Mix_Chunk* Mix_ChunkMix_Chunk = Mix_LoadWAV("resources/13.ogg");
                    // Mix_PlayChannel(-1, Mix_ChunkMix_Chunk, 0); SDL_Delay(5000);
                    // Mix_FreeChunk(Mix_ChunkMix_Chunk);
                    intTrigger = intTrigger + 1;
                    stringText = "Тоха: На твою закладку... Диса: На держи свои деньги";
                } else if (intLocation != 1 && intTrigger == 15) { 
                    // Mix_Chunk* Mix_ChunkMix_Chunk = Mix_LoadWAV("resources/15.ogg");
                    // Mix_PlayChannel(-1, Mix_ChunkMix_Chunk, 0); SDL_Delay(11000);
                    // Mix_FreeChunk(Mix_ChunkMix_Chunk);
                    intTrigger = intTrigger + 1;
                    stringText = "Тоха: Можно энергетик пж. Диса: Мы не продаем энергетики детям... Пиздуй от сюда!";
                } else if (intLocation != 1 && intTrigger == 17) { 
                    // Mix_Chunk* Mix_ChunkMix_Chunk = Mix_LoadWAV("resources/17.ogg");
                    // Mix_PlayChannel(-1, Mix_ChunkMix_Chunk, 0); SDL_Delay(30000);
                    // Mix_FreeChunk(Mix_ChunkMix_Chunk);
                    intLocation = 7;
                    intTrigger = intTrigger + 1;
                } break;
            }
        }

        SDL_SetRenderDrawColor(SDL_RendererRenderer, 57, 57, 57, 255);
        SDL_RenderClear(SDL_RendererRenderer);

        {
            SDL_Texture* SDL_TextureTexture = SDL_CreateTextureFromSurface(SDL_RendererRenderer, SDL_SurfaceLocation);
            SDL_Rect SDL_RectRectSource = {800 * intLocation, 0, 800, 600};
            SDL_Rect SDL_RectRect = {0, 0, SDL_RectRectSource.w * intZoom, SDL_RectRectSource.h * intZoom};
            SDL_RenderCopy(SDL_RendererRenderer, SDL_TextureTexture, &SDL_RectRectSource, &SDL_RectRect);
            SDL_DestroyTexture(SDL_TextureTexture);
        }
        if (intLocation != 1) {
            SDL_Texture* SDL_TextureTexture = SDL_CreateTextureFromSurface(SDL_RendererRenderer, SDL_SurfacePlayer);
            SDL_Rect SDL_RectRectSource = {0, 0, 18, 37};
            SDL_Rect SDL_RectRect = {intPositionX, intPositionY, SDL_RectRectSource.w * intZoom, SDL_RectRectSource.h * intZoom};
            SDL_RenderCopy(SDL_RendererRenderer, SDL_TextureTexture, &SDL_RectRectSource, &SDL_RectRect);
            SDL_DestroyTexture(SDL_TextureTexture);

            if (intTrigger == 0 || intTrigger == 2 || intTrigger == 3 || intTrigger == 5 || intTrigger == 7 || intTrigger == 9 || intTrigger == 11 || intTrigger == 13 || intTrigger == 15 || intTrigger == 17) {
                {
                    SDL_Texture* SDL_TextureTexture = SDL_CreateTextureFromSurface(SDL_RendererRenderer, SDL_SurfaceDialog);
                    SDL_Rect SDL_RectRectSource = {0, 0, 800, 600};
                    SDL_Rect SDL_RectRect = {0, 0, SDL_RectRectSource.w * intZoom, SDL_RectRectSource.h * intZoom};
                    SDL_RenderCopy(SDL_RendererRenderer, SDL_TextureTexture, &SDL_RectRectSource, &SDL_RectRect);
                    SDL_DestroyTexture(SDL_TextureTexture);
                }
                {
                    SDL_Color SDL_ColorColor = {240, 255, 255, 255};

                    SDL_Surface* SDL_SurfaceSurface = TTF_RenderUTF8_Solid(TTF_FontFont, stringText.c_str(), SDL_ColorColor);
                    if (SDL_SurfaceSurface == nullptr) {
                        SDL_WindowWindow = nullptr;
                    }

                    SDL_Texture* SDL_TextureTexture = SDL_CreateTextureFromSurface(SDL_RendererRenderer, SDL_SurfaceSurface);
                    if (SDL_TextureTexture == nullptr) {
                        SDL_WindowWindow = nullptr;
                    } SDL_FreeSurface(SDL_SurfaceSurface);
                    
                    SDL_Rect SDL_RectRect = {35, 465, SDL_SurfaceSurface->w, SDL_SurfaceSurface->h};
                    SDL_RenderCopy(SDL_RendererRenderer, SDL_TextureTexture, nullptr, &SDL_RectRect);
                    SDL_DestroyTexture(SDL_TextureTexture);
                }
            }
        }

        SDL_RenderPresent(SDL_RendererRenderer);
    }

    SDL_FreeSurface(SDL_SurfaceLocation);
    SDL_FreeSurface(SDL_SurfacePlayer);
    SDL_FreeSurface(SDL_SurfaceDialog);
    SDL_DestroyRenderer(SDL_RendererRenderer);
    SDL_DestroyWindow(SDL_WindowWindow);
    // Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    return 0;
}