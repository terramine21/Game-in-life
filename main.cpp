#include <iostream>
#include <vector>

using namespace std;


class Dot
{
public:
	Dot();
	~Dot();

	void create()
	{

	}
	void move()
	{

	}
	void draw()
	{

	}

private:
	Dot* mPreDot;
	Dot* mAfterDot;
};

class MapManager
{
public:
	MapManager();
	~MapManager();

private:

};



class Game
{
public:
	Game();
	~Game();

	void checkWin()
	{
		
	}
	void run()
	{
		draw();
	}

	void draw()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				int z;
			cout << endl;
		}
	}

	void createMap(std::size_t size = 3)
	{
		for (std::size_t i = 0; i < size; i++)
		{
			mMap.push_back(*new vector<Dot>);
			for (std::size_t i = 0; i < size; i++)
				mMap[i].push_back(*new Dot);
		}
	}
	void fillMap()
	{

	}
private:
	vector<vector<Dot>> mMap;
};



int main()
{/*
	Game game;
	game.run()*/;
}
