#pragma once

class RedSaucer : public Saucer
{
private:

public:
	RedSaucer(Point2f pos);
	void Draw(GameState& state);
	static void SpawnWave(GameState& state);
};

