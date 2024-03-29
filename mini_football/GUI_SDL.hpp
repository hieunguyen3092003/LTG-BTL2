#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <vector>
#include "piece.h"

#define WIDTH 480
#define HEIGHT 840
#define WID_BORDER 20
#define HEI_BORDER 50
#define SIZE_PIECE 542
#define SIZE_BAT 25
#define SIZE_BALL 25
#define BLACK_COLOR 0,0,0
#define RED_COLOR 255,0,0
#define BLUE_COLOR 0,0,255
#define MAX_SPEED SIZE_BALL/2
#define BOOT_SP 6

class GUI_SDL
{
public:
	GUI_SDL();
	~GUI_SDL();

	void new_game(bool hard);
	Event_en checkEvent();
	void draw( std::vector<piece> & pieces);
	bool change_noise();
	void countdown();
	void draw_field();
	void win(int x);
	void play_sound(Collision s);
	void draw_ball(ball_type type);

private:
	
	void load_ttf();
	void load_img();
	void load_sound();
	void draw_dynamic();
	
	bool _noise = true;
	SDL_Window *_win;
	SDL_Renderer *_rend;
	SDL_Surface *_ttf;
	SDL_Texture *_background, *_bat1, *_bat2, *_ball, *_text, *_dynamic, * _count;
	TTF_Font *_font;
	SDL_Color _color;
	SDL_Rect _src, _dst;
	Mix_Music *_music;
	Mix_Chunk *_board, *_hit, *_goal;
};
