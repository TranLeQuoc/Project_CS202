#include "Game.h"
#include "Constants.h"
#include "Global.h"

Game::Game() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, APP_NAME);
    SetTargetFPS(60);  
    
    Global::initialize();
    state = GAME_STATE_MAIN_MENU;
    mainMenu = new MainMenu();
    level = nullptr;
}

void Game::run() {
    while (!WindowShouldClose())   
    {
        switch (state) {
        case GAME_STATE_MAIN_MENU: {
            if (mainMenu->showMenu() == 1) {
                level = new Level();
                state = GAME_STATE_PLAYING;
            }
            else if (mainMenu->showMenu() == 2) {
                state = GAME_STATE_LOADGAME;
            }
            else if (mainMenu->showMenu() == 3) {
                state = GAME_STATE_SCOREBOARD;
            }
            else if (mainMenu->showMenu() == 4) {
                state = GAME_STATE_SETTINGS;
            }
            else if (mainMenu->showMenu() == 5) {
                state = GAME_STATE_EXIT;
            }
            break;
        } 
        case GAME_STATE_PLAYING: {
            if (!level->isOver()) {
                ++COUNT_FRAME;
                if(COUNT_FRAME == 60) {
                    ++COUNT_TIME;
                    COUNT_FRAME = 0;
                }
                level->update();
                if (IsKeyDown(KEY_DOWN)) {
                    level->playerMoveDown();
                }
                if (IsKeyDown(KEY_UP)) {
                    level->playerMoveUp();
                }
                if (IsKeyDown(KEY_RIGHT)) {
                    level->playerMoveRight();
                }
                if (IsKeyDown(KEY_LEFT)) {
                    level->playerMoveLeft();
                }
                level->draw();
            } else {
                delete level;
                level = nullptr;
                state = GAME_STATE_MAIN_MENU;
            }
            break;
        }
        case GAME_STATE_LOADGAME: {
            break;
        }
        case GAME_STATE_SCOREBOARD: {
            break;
        }
        case GAME_STATE_SETTINGS: {
            break;
        }
        case GAME_STATE_EXIT: {
            CloseWindow();
            break;
        }
        default:
            break;
        }
    }
}

Game::~Game() {
    Global::deallocate();
    if (level != nullptr) {
        delete level;
    }
    delete mainMenu;
    CloseWindow(); 
}