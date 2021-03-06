/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	link({ 100,100 })
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	Vec2 dt = Vec2( 0.0f,0.0f );
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		dt.x -= 1;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		dt.x += 1;
	}
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		dt.y -= 1;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		dt.y += 1;
	}
	link.SetDirection(dt);
	link.Update(ft.Mark());
}

void Game::ComposeFrame()
{
	font.DrawText("BROTHERSSS!!! \nWITH me", { wnd.mouse.GetPosX(),wnd.mouse.GetPosY() }, gfx);
	link.Draw(gfx);
}
