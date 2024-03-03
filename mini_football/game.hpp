#pragma once

#include "GUI_SDL.hpp"

class TinyFootball
{
public:
	TinyFootball();
	void setgame(type_piece t1, type_piece t2);
	~TinyFootball();
	void start();
	
	std::vector<piece> _pieces; // [6]:= [bot bot bot bot bot player]
	type_piece t1;
	type_piece t2;
	ball_type type_of_ball;


private:
	void begin_pos();
	void behav_bot();
	void behav_ball(ball_type type_of_ball);
	void hit_ball(int type, ball_type type_of_ball);
	void confines(int type);
	void extrude();
	void wind();
	std::unique_ptr<GUI_SDL> _lib;
	bool _pvp = false , _hard = false, _pvc = false, _mute = true;
	Event_en _event;
};
