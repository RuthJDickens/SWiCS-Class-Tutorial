#pragma once

class Player: public GameObject
{
private:

public:
	Player(Point2f pos);
	void Update(GameState& state);
	void Draw(GameState& state);
};

