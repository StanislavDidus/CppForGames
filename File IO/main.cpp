#include <iostream>
#include <fstream>

struct highscore
{
	char name[4];
	uint32_t score;
};

int main()
{
	//Write ascii files
	{
		std::ofstream highscores("highscores.txt", std::ios::out);
		if (!highscores)
		{
			std::cerr << "ERROR: Could not open file for writing" << std::endl;
			return 1;
		}

		highscores << "DAN " << 2014 << std::endl;
		highscores << "TOM " << 2012 << std::endl;
		highscores << "LUC " << 2009 << std::endl;
		highscores << "SUZ " << 1978 << std::endl;

		if (highscores.bad())
		{
			std::cerr << "ERROR: Could not open file for writing" << std::endl;
			return 1;
		}

		highscores.close();
		//File will clsoe when it gets out of scope
	}

	{
		std::ofstream highscores("highscores.txt", std::ios::app);
		if (!highscores)
		{
			std::cerr << "ERROR: Could not open file for writing" << std::endl;
			return 1;
		}

		highscores << "JER " << 1977 << std::endl;

		if (highscores.bad())
		{
			std::cerr << "ERROR: Could not open file for writing" << std::endl;
			return 1;
		}

		highscores.close();
	}

	{
		std::ifstream highscores("highscores.txt");
		if (!highscores)
		{
			std::cerr << "ERROR: Could not open file for reading" << std::endl;
			return 1;
		}

		char name[4];
		int score;
		while (highscores >> name >> score)
		{
			std::cout << name << " " << score << std::endl;
		}

		if (highscores.bad())
		{
			std::cerr << "ERROR: Could not open file for writing" << std::endl;
			return 1;
		}

		highscores.close();
	}

	//Writing binary files
	{
		std::ofstream highscores("highscores.bin", std::ios::binary);
		if (!highscores)
		{
			std::cerr << "ERROR: Could not open file for reading" << std::endl;
			return 1;
		}

		highscore scores[] =
		{
			{"DAN", 2014},
			{"TOM", 2012},
			{"LUC", 2009},
			{"SUZ", 1978},
			{"JER", 1977}
		};

		auto numScores = std::size(scores);

		highscores.write(reinterpret_cast<const char*>(&numScores), sizeof(numScores));
		highscores.write(reinterpret_cast<const char*>(scores), numScores * sizeof(highscore));

		if (highscores.bad())
		{
			std::cerr << "ERROR: Could not open file for writing" << std::endl;
			return 1;
		}

		highscores.close();
	}

	std::cout << std::endl;

	{
		std::ifstream highscores("highscores.bin", std::ios::binary);
		if (!highscores)
		{
			std::cerr << "ERROR: Could not open file for reading" << std::endl;
			return 1;
		}

		size_t numEntries;
		highscores.read(reinterpret_cast<char*>(&numEntries), sizeof(numEntries));

		highscore* scores = new highscore[numEntries];

		highscores.read(reinterpret_cast<char*>(scores), numEntries * sizeof(highscore));

		for (int i = 0; i < numEntries; i++)
		{
			std::cout << scores[i].name << " " << scores[i].score << std::endl;
		}

		delete[] scores;
		
		if (highscores.bad())
		{
			std::cerr << "ERROR: Could not open file for writing" << std::endl;
			return 1;
		}

		highscores.close();
	}

	return 0;
} 