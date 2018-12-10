#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>]
#include <vector>

using namespace std;

int sort(const string& s)
{
	int p = 0;
	if (s == "Wheel : red;")
		p = 1;
	if (s == "Wheel : blue;")
		p = 2;
	if (s == "Wheel : green;")
		p = 3;
	if (s == "Telega : red;")
		p = 4;
	if (s == "Telega : blue;")
		p = 5;
	if (s == "Telega : green;")
		p = 6;
	return p;
}

class Detail
{
public:
	string color;
};

class Wheel : public Detail
{
public:
	Wheel() {}
	Wheel(string s) { color = s; }
	Wheel(const Wheel& w)
	{
		color = w.color;
	}
};

class Telega : public Detail
{
public :
	Telega() {}
	Telega(string s) { color = s; }
};

int main()
{	
	string s1;
	int i = 0;
	int counterR = 0;
	int counterG = 0;
	int counterB = 0;
	vector<Wheel> redW;
	vector<Wheel> blueW;
	vector<Wheel> greenW ;
	vector<Telega> redT;
	vector<Telega> blueT ;
	vector<Telega> greenT;
	Wheel w;
	Telega t;
	ifstream ifile;
	ifile.open("C:\\Users\\Dell\\source\\repos\\Telega\\Details.txt");
	// Sort to vectores
	while(i == 0)
	{
		if (ifile.good())
		{
			int p = 0;
			getline(ifile, s1);
			p = sort(s1);
			switch (p)
			{
			case 1:
			{
				w.color = "Red";
				Wheel w1(w);
				Wheel * ptr = &w1;
				redW.push_back(*ptr);
				break;
			}
			case 2:
			{
				w.color = "Blue";
				Wheel w1(w);
				Wheel * ptr = &w1;
				blueW.push_back(*ptr);
				break;
			}

			case 3:
			{
				w.color = "Green";
				Wheel w1(w);
				Wheel * ptr = &w1;
				greenW.push_back(*ptr);
				break;
			}

			case 4:
			{
				t.color = "Red";
				Telega w1(t);
				Telega * ptr = &w1;
				redT.push_back(*ptr);
				break;
			}
			case 5:
			{
				t.color = "Blue";
				Telega w1(t);
				Telega * ptr = &w1;
				blueT.push_back(*ptr);
				break;
			}

			case 6:
			{
				t.color = "Green";
				Telega w1(t);
				Telega * ptr = &w1;
				greenT.push_back(*ptr);
				break;
			}
			default:
				break;
			}
		}
		else
		  i++;

	}
	//Create red car
	while (redW.size() >= 2 && redT.size() >= 1)
	{
		redW.erase(redW.begin());
		redW.erase(redW.begin());
		redT.erase(redT.begin());
		counterR++;
	}
	//Create blue car
	while (blueW.size() >= 2 && blueT.size() >= 1)
	{
		blueW.erase(blueW.begin());
		blueW.erase(blueW.begin());
		blueT.erase(blueT.begin());
		counterB++;
	}
	//Create green car
	while (greenW.size() >= 2 && greenT.size() >= 1)
	{
		greenW.erase(greenW.begin());
		greenW.erase(greenW.begin());
		greenT.erase(greenT.begin());
		counterG++;
	}
	ifile.close();
	ofstream ofile;
	ofile.open("C:\\Users\\Dell\\source\\repos\\Telega\\Cars.txt");
	if (ofile.is_open())
	{
		ofile << "Red cars : " << counterR << endl;
		ofile << "Blue cars : " << counterB << endl;
		ofile << "Green cars : " << counterG << endl;
	}
	ofile.close();
	system("pause");
}