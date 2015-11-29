#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

typedef unsigned int cube_t; //0bMETA DATA ffff bbbb llll rrrr uuuu dddd

#define GET_FRONT(x) ((CubeColor)(((x)&0xF00000)>>20))
#define GET_BACK(x)  ((CubeColor)(((x)&0x0F0000)>>16))
#define GET_LEFT(x)  ((CubeColor)(((x)&0x00F000)>>12))
#define GET_RIGHT(x) ((CubeColor)(((x)&0x000F00)>>8))
#define GET_UP(x)    ((CubeColor)(((x)&0x0000F0)>>4))
#define GET_DOWN(x)  ((CubeColor)(((x)&0x00000F)>>0))

#define SET_FRONT(x) (((x)&0xF)<<20)
#define SET_BACK(x)  (((x)&0xF)<<16)
#define SET_LEFT(x)  (((x)&0xF)<<12)
#define SET_RIGHT(x) (((x)&0xF)<<8)
#define SET_UP(x)    (((x)&0xF)<<4)
#define SET_DOWN(x)  (((x)&0xF)<<0)

#define MAKE_CUBE(f, b, l, r, u, d) (SET_FRONT(f)|SET_BACK(b)|SET_LEFT(l)|SET_RIGHT(r)|SET_UP(u)|SET_DOWN(d))

#define ROTATE_LEFT(x)  MAKE_CUBE(GET_RIGHT(x), GET_LEFT(x), GET_FRONT(x), GET_BACK(x), GET_UP(x), GET_DOWN(x))
#define ROTATE_RIGHT(x) MAKE_CUBE(GET_LEFT(x), GET_RIGHT(x), GET_BACK(x), GET_FRONT(x), GET_UP(x), GET_DOWN(x))
#define ROTATE_UP(x)    MAKE_CUBE(GET_DOWN(x), GET_UP(x), GET_LEFT(x), GET_RIGHT(x), GET_FRONT(x), GET_BACK(x))
#define ROTATE_DOWN(x)  MAKE_CUBE(GET_UP(x), GET_DOWN(x), GET_LEFT(x), GET_RIGHT(x), GET_BACK(x), GET_FRONT(x))
#define ROTATE_CLK(x)   MAKE_CUBE(GET_FRONT(x), GET_BACK(x), GET_DOWN(x), GET_UP(x), GET_LEFT(x), GET_RIGHT(x)) //clockwise
#define ROTATE_CCLK(x)  MAKE_CUBE(GET_FRONT(x), GET_BACK(x), GET_UP(x), GET_DOWN(x), GET_RIGHT(x), GET_LEFT(x)) //counter-clockwise

enum CubeColor
{
	COLOR_RED,
	COLOR_GREEN,
	COLOR_BLUE,
	COLOR_ORANGE,
	COLOR_WHITE,
	COLOR_YELLOW,
	COLOR_INVALID = 0xF
};

//i means inverse, +10 -> i
enum CubeRotateMethod
{
	ROTATE_NONE,
	ROTATE_FRONT,
	ROTATE_BACK,
	ROTATE_LEFT,
	ROTATE_RIGHT,
	ROTATE_UP,
	ROTATE_DOWN,
	ROTATE_NONEi,
	ROTATE_FRONTi,
	ROTATE_BACKi,
	ROTATE_LEFTi,
	ROTATE_RIGHTi,
	ROTATE_UPi,
	ROTATE_DOWNi,
};

CubeRotateMethod NameToCubeRotateMethod(string);
CubeRotateMethod NameToCubeRotateMethod(string name)
{
	if (name == "F")
		return ROTATE_FRONT;
	else if (name == "B")
		return ROTATE_BACK;
	else if (name == "L")
		return ROTATE_LEFT;
	else if (name == "R")
		return ROTATE_RIGHT;
	else if (name == "U")
		return ROTATE_UP;
	else if (name == "D")
		return ROTATE_DOWN;
	else if (name == "Fi")
		return ROTATE_FRONTi;
	else if (name == "Bi")
		return ROTATE_BACKi;
	else if (name == "Li")
		return ROTATE_LEFTi;
	else if (name == "Ri")
		return ROTATE_RIGHTi;
	else if (name == "Ui")
		return ROTATE_UPi;
	else if (name == "Di")
		return ROTATE_DOWNi;
	else
		return ROTATE_NONE;
}

CubeColor CharColorMap(char);
char ColorCharMap(CubeColor);
string CharWordMap(char);

class Cube
{
public:
	Cube();
	~Cube();

	cube_t subCubes[3][3][3];
	//              x  y  z
	/*
	    y
	    |
	    |
	    |
	    |________x
	   /_/_/_/
	  /_/_/_/
	 /_/_/_/
	z 
	*/

	void Load(string);
	string Save();
	void SaveState();
	void DoMethod(CubeRotateMethod);
	void R();
	void Ri();
	void L();
	void Li();
	void B();
	void Bi();
	void D();
	void Di();
	void F();
	void Fi();
	void U();
	void Ui();

private:
	cube_t oldSubCubes[3][3][3];
};

CubeColor CharColorMap(char ch)
{
	switch (ch)
	{
	case '-':
		return COLOR_INVALID;
	case 'W':
		return COLOR_WHITE;
	case 'O':
		return COLOR_ORANGE;
	case 'B':
		return COLOR_BLUE;
	case 'R':
		return COLOR_RED;
	case 'G':
		return COLOR_GREEN;
	case 'Y':
		return COLOR_YELLOW;
	}
}

char ColorCharMap(CubeColor c)
{
	switch (c)
	{
	case COLOR_WHITE:
		return 'W';
	case COLOR_ORANGE:
		return 'O';
	case COLOR_BLUE:
		return 'B';
	case COLOR_RED:
		return 'R';
	case COLOR_GREEN:
		return 'G';
	case COLOR_YELLOW:
		return 'Y';
	}
}

Cube::Cube()
{
	//-BO--Y-B---Y-B-R-Y-BO----B-----B-R---BO-W--B--W--B-RW---O--Y-----Y---R-Y--O------------R----O-W-----W----RW-G-O--YG----YG--R-YG-O---G-----G--R--G-O-W-G---W-G--RW-
	subCubes[0][0][0] = 0x063002;
	subCubes[1][0][0] = 0x060002;
	subCubes[2][0][0] = 0x060402;
	subCubes[0][0][1] = 0x003002;
	subCubes[1][0][1] = 0x000002;
	subCubes[2][0][1] = 0x000402;
	subCubes[0][0][2] = 0x503002;
	subCubes[1][0][2] = 0x500002;
	subCubes[2][0][2] = 0x500402;

	subCubes[0][1][0] = 0x063000;
	subCubes[1][1][0] = 0x060000;
	subCubes[2][1][0] = 0x060400;
	subCubes[0][1][1] = 0x003000;
	subCubes[1][1][1] = 0x000000;
	subCubes[2][1][1] = 0x000400;
	subCubes[0][1][2] = 0x503000;
	subCubes[1][1][2] = 0x500000;
	subCubes[2][1][2] = 0x500400;

	subCubes[0][2][0] = 0x063010;
	subCubes[1][2][0] = 0x060010;
	subCubes[2][2][0] = 0x060410;
	subCubes[0][2][1] = 0x003010;
	subCubes[1][2][1] = 0x000010;
	subCubes[2][2][1] = 0x000410;
	subCubes[0][2][2] = 0x503010;
	subCubes[1][2][2] = 0x500010;
	subCubes[2][2][2] = 0x500410;
}


Cube::~Cube()
{
}

void Cube::Load(string data)
{
	for (int z = 0; z < 3; ++z)
	{
		for (int y = 0; y < 3; ++y)
		{
			for (int x = 0; x < 3; ++x)
			{
				subCubes[x][y][z] =
					MAKE_CUBE(CharColorMap(data[((z * 3 + y) * 3 + x) * 6 + 0]),
							  CharColorMap(data[((z * 3 + y) * 3 + x) * 6 + 1]),
							  CharColorMap(data[((z * 3 + y) * 3 + x) * 6 + 2]),
							  CharColorMap(data[((z * 3 + y) * 3 + x) * 6 + 3]),
							  CharColorMap(data[((z * 3 + y) * 3 + x) * 6 + 4]),
							  CharColorMap(data[((z * 3 + y) * 3 + x) * 6 + 5]));
			}
		}
	}
}

string Cube::Save()
{
	string data;
	for (int z = 0; z < 3; ++z)
	{
		for (int y = 0; y < 3; ++y)
		{
			for (int x = 0; x < 3; ++x)
			{
				cube_t subcube = subCubes[x][y][z];
				data += ColorCharMap(GET_FRONT(subcube));
				data += ColorCharMap(GET_BACK(subcube));
				data += ColorCharMap(GET_LEFT(subcube));
				data += ColorCharMap(GET_RIGHT(subcube));
				data += ColorCharMap(GET_UP(subcube));
				data += ColorCharMap(GET_DOWN(subcube));
			}
		}
	}
	return data;
}

void Cube::SaveState()
{
	for (int x = 0; x < 3; ++x)
	{
		for (int y = 0; y < 3; ++y)
		{
			for (int z = 0; z < 3; ++z)
			{
				oldSubCubes[x][y][z] = subCubes[x][y][z];
			}
		}
	}
}

void Cube::DoMethod(CubeRotateMethod method)
{
	switch (method)
	{
	case ROTATE_NONE:
		break;
	case ROTATE_FRONT:
		F();
		break;
	case ROTATE_BACK:
		B();
		break;
	case ROTATE_LEFT:
		L();
		break;
	case ROTATE_RIGHT:
		R();
		break;
	case ROTATE_UP:
		U();
		break;
	case ROTATE_DOWN:
		D();
		break;
	case ROTATE_FRONTi:
		Fi();
		break;
	case ROTATE_BACKi:
		Bi();
		break;
	case ROTATE_LEFTi:
		Li();
		break;
	case ROTATE_RIGHTi:
		Ri();
		break;
	case ROTATE_UPi:
		Ui();
		break;
	default:
		break;
	}
}

void Cube::R()
{
	SaveState();
	subCubes[2][0][0] = ROTATE_UP(oldSubCubes[2][2][0]);
	subCubes[2][0][1] = ROTATE_UP(oldSubCubes[2][1][0]);
	subCubes[2][0][2] = ROTATE_UP(oldSubCubes[2][0][0]);
	subCubes[2][1][0] = ROTATE_UP(oldSubCubes[2][2][1]);
	subCubes[2][1][1] = ROTATE_UP(oldSubCubes[2][1][1]);
	subCubes[2][1][2] = ROTATE_UP(oldSubCubes[2][0][1]);
	subCubes[2][2][0] = ROTATE_UP(oldSubCubes[2][2][2]);
	subCubes[2][2][1] = ROTATE_UP(oldSubCubes[2][1][2]);
	subCubes[2][2][2] = ROTATE_UP(oldSubCubes[2][0][2]);
}

void Cube::Ri()
{
	SaveState();
	subCubes[2][0][0] = ROTATE_DOWN(oldSubCubes[2][0][2]);
	subCubes[2][0][1] = ROTATE_DOWN(oldSubCubes[2][1][2]);
	subCubes[2][0][2] = ROTATE_DOWN(oldSubCubes[2][2][2]);
	subCubes[2][1][0] = ROTATE_DOWN(oldSubCubes[2][0][1]);
	subCubes[2][1][1] = ROTATE_DOWN(oldSubCubes[2][1][1]);
	subCubes[2][1][2] = ROTATE_DOWN(oldSubCubes[2][2][1]);
	subCubes[2][2][0] = ROTATE_DOWN(oldSubCubes[2][0][0]);
	subCubes[2][2][1] = ROTATE_DOWN(oldSubCubes[2][1][0]);
	subCubes[2][2][2] = ROTATE_DOWN(oldSubCubes[2][2][0]);
}

void Cube::L()
{
	SaveState();
	subCubes[0][0][0] = ROTATE_DOWN(oldSubCubes[0][0][2]);
	subCubes[0][0][1] = ROTATE_DOWN(oldSubCubes[0][1][2]);
	subCubes[0][0][2] = ROTATE_DOWN(oldSubCubes[0][2][2]);
	subCubes[0][1][0] = ROTATE_DOWN(oldSubCubes[0][0][1]);
	subCubes[0][1][1] = ROTATE_DOWN(oldSubCubes[0][1][1]);
	subCubes[0][1][2] = ROTATE_DOWN(oldSubCubes[0][2][1]);
	subCubes[0][2][0] = ROTATE_DOWN(oldSubCubes[0][0][0]);
	subCubes[0][2][1] = ROTATE_DOWN(oldSubCubes[0][1][0]);
	subCubes[0][2][2] = ROTATE_DOWN(oldSubCubes[0][2][0]);
}

void Cube::Li()
{
	SaveState();
	subCubes[0][0][0] = ROTATE_UP(oldSubCubes[0][2][0]);
	subCubes[0][0][1] = ROTATE_UP(oldSubCubes[0][1][0]);
	subCubes[0][0][2] = ROTATE_UP(oldSubCubes[0][0][0]);
	subCubes[0][1][0] = ROTATE_UP(oldSubCubes[0][2][1]);
	subCubes[0][1][1] = ROTATE_UP(oldSubCubes[0][1][1]);
	subCubes[0][1][2] = ROTATE_UP(oldSubCubes[0][0][1]);
	subCubes[0][2][0] = ROTATE_UP(oldSubCubes[0][2][2]);
	subCubes[0][2][1] = ROTATE_UP(oldSubCubes[0][1][2]);
	subCubes[0][2][2] = ROTATE_UP(oldSubCubes[0][0][2]);
}

void Cube::B()
{
	SaveState();
	subCubes[0][0][0] = ROTATE_CCLK(oldSubCubes[0][2][0]);
	subCubes[1][0][0] = ROTATE_CCLK(oldSubCubes[0][1][0]);
	subCubes[2][0][0] = ROTATE_CCLK(oldSubCubes[0][0][0]);
	subCubes[0][1][0] = ROTATE_CCLK(oldSubCubes[1][2][0]);
	subCubes[1][1][0] = ROTATE_CCLK(oldSubCubes[1][1][0]);
	subCubes[2][1][0] = ROTATE_CCLK(oldSubCubes[1][0][0]);
	subCubes[0][2][0] = ROTATE_CCLK(oldSubCubes[2][2][0]);
	subCubes[1][2][0] = ROTATE_CCLK(oldSubCubes[2][1][0]);
	subCubes[2][2][0] = ROTATE_CCLK(oldSubCubes[2][0][0]);
}

void Cube::Bi()
{
	SaveState();
	subCubes[0][0][0] = ROTATE_CLK(oldSubCubes[2][0][0]);
	subCubes[1][0][0] = ROTATE_CLK(oldSubCubes[2][1][0]);
	subCubes[2][0][0] = ROTATE_CLK(oldSubCubes[2][2][0]);
	subCubes[0][1][0] = ROTATE_CLK(oldSubCubes[1][0][0]);
	subCubes[1][1][0] = ROTATE_CLK(oldSubCubes[1][1][0]);
	subCubes[2][1][0] = ROTATE_CLK(oldSubCubes[1][2][0]);
	subCubes[0][2][0] = ROTATE_CLK(oldSubCubes[0][0][0]);
	subCubes[1][2][0] = ROTATE_CLK(oldSubCubes[0][1][0]);
	subCubes[2][2][0] = ROTATE_CLK(oldSubCubes[0][2][0]);
}

void Cube::D()
{
	SaveState();
	subCubes[0][0][0] = ROTATE_RIGHT(oldSubCubes[2][0][0]);
	subCubes[1][0][0] = ROTATE_RIGHT(oldSubCubes[2][0][1]);
	subCubes[2][0][0] = ROTATE_RIGHT(oldSubCubes[2][0][2]);
	subCubes[0][0][1] = ROTATE_RIGHT(oldSubCubes[1][0][0]);
	subCubes[1][0][1] = ROTATE_RIGHT(oldSubCubes[1][0][1]);
	subCubes[2][0][1] = ROTATE_RIGHT(oldSubCubes[1][0][2]);
	subCubes[0][0][2] = ROTATE_RIGHT(oldSubCubes[0][0][0]);
	subCubes[1][0][2] = ROTATE_RIGHT(oldSubCubes[0][0][1]);
	subCubes[2][0][2] = ROTATE_RIGHT(oldSubCubes[0][0][2]);
}

void Cube::Di()
{
	SaveState();
	subCubes[0][0][0] = ROTATE_LEFT(oldSubCubes[0][0][2]);
	subCubes[1][0][0] = ROTATE_LEFT(oldSubCubes[0][0][1]);
	subCubes[2][0][0] = ROTATE_LEFT(oldSubCubes[0][0][0]);
	subCubes[0][0][1] = ROTATE_LEFT(oldSubCubes[1][0][2]);
	subCubes[1][0][1] = ROTATE_LEFT(oldSubCubes[1][0][1]);
	subCubes[2][0][1] = ROTATE_LEFT(oldSubCubes[1][0][0]);
	subCubes[0][0][2] = ROTATE_LEFT(oldSubCubes[2][0][2]);
	subCubes[1][0][2] = ROTATE_LEFT(oldSubCubes[2][0][1]);
	subCubes[2][0][2] = ROTATE_LEFT(oldSubCubes[2][0][0]);
}

void Cube::F()
{
	SaveState();
	subCubes[0][0][2] = ROTATE_CLK(oldSubCubes[2][0][2]);
	subCubes[1][0][2] = ROTATE_CLK(oldSubCubes[2][1][2]);
	subCubes[2][0][2] = ROTATE_CLK(oldSubCubes[2][2][2]);
	subCubes[0][1][2] = ROTATE_CLK(oldSubCubes[1][0][2]);
	subCubes[1][1][2] = ROTATE_CLK(oldSubCubes[1][1][2]);
	subCubes[2][1][2] = ROTATE_CLK(oldSubCubes[1][2][2]);
	subCubes[0][2][2] = ROTATE_CLK(oldSubCubes[0][0][2]);
	subCubes[1][2][2] = ROTATE_CLK(oldSubCubes[0][1][2]);
	subCubes[2][2][2] = ROTATE_CLK(oldSubCubes[0][2][2]);
}

void Cube::Fi()
{
	SaveState();
	subCubes[0][0][2] = ROTATE_CCLK(oldSubCubes[0][2][2]);
	subCubes[1][0][2] = ROTATE_CCLK(oldSubCubes[0][1][2]);
	subCubes[2][0][2] = ROTATE_CCLK(oldSubCubes[0][0][2]);
	subCubes[0][1][2] = ROTATE_CCLK(oldSubCubes[1][2][2]);
	subCubes[1][1][2] = ROTATE_CCLK(oldSubCubes[1][1][2]);
	subCubes[2][1][2] = ROTATE_CCLK(oldSubCubes[1][0][2]);
	subCubes[0][2][2] = ROTATE_CCLK(oldSubCubes[2][2][2]);
	subCubes[1][2][2] = ROTATE_CCLK(oldSubCubes[2][1][2]);
	subCubes[2][2][2] = ROTATE_CCLK(oldSubCubes[2][0][2]);
}

void Cube::U()
{
	SaveState();
	subCubes[0][2][0] = ROTATE_LEFT(oldSubCubes[0][2][2]);
	subCubes[1][2][0] = ROTATE_LEFT(oldSubCubes[0][2][1]);
	subCubes[2][2][0] = ROTATE_LEFT(oldSubCubes[0][2][0]);
	subCubes[0][2][1] = ROTATE_LEFT(oldSubCubes[1][2][2]);
	subCubes[1][2][1] = ROTATE_LEFT(oldSubCubes[1][2][1]);
	subCubes[2][2][1] = ROTATE_LEFT(oldSubCubes[1][2][0]);
	subCubes[0][2][2] = ROTATE_LEFT(oldSubCubes[2][2][2]);
	subCubes[1][2][2] = ROTATE_LEFT(oldSubCubes[2][2][1]);
	subCubes[2][2][2] = ROTATE_LEFT(oldSubCubes[2][2][0]);
}

void Cube::Ui()
{
	SaveState();
	subCubes[0][2][0] = ROTATE_RIGHT(oldSubCubes[2][2][0]);
	subCubes[1][2][0] = ROTATE_RIGHT(oldSubCubes[2][2][1]);
	subCubes[2][2][0] = ROTATE_RIGHT(oldSubCubes[2][2][2]);
	subCubes[0][2][1] = ROTATE_RIGHT(oldSubCubes[1][2][0]);
	subCubes[1][2][1] = ROTATE_RIGHT(oldSubCubes[1][2][1]);
	subCubes[2][2][1] = ROTATE_RIGHT(oldSubCubes[1][2][2]);
	subCubes[0][2][2] = ROTATE_RIGHT(oldSubCubes[0][2][0]);
	subCubes[1][2][2] = ROTATE_RIGHT(oldSubCubes[0][2][1]);
	subCubes[2][2][2] = ROTATE_RIGHT(oldSubCubes[0][2][2]);
}

int mapTable1[] = {-1, 17, 24, -1, -1, 51, -1, 16, -1, -1, -1, 52, -1, 15, -1, 35, -1, 53, //(0, 0, 0) ~ (2, 0, 0)
                  -1, 14, 21, -1, -1, -1, -1, 13, -1, -1, -1, -1, -1, 12, -1, 32, -1, -1, //(0, 1, 0) ~ (2, 1, 0)
				  -1, 11, 18, -1, 36, -1, -1, 10, -1, -1, 37, -1, -1,  9, -1, 29, 38, -1, //(0, 2, 0) ~ (2, 2, 0)
				  -1, -1, 25, -1, -1, 48, -1, -1, -1, -1, -1, 49, -1, -1, -1, 34, -1, 50, //(0, 0, 1) ~ (2, 0, 1)
				  -1, -1, 22, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 31, -1, -1, //(0, 1, 1) ~ (2, 1, 1)
				  -1, -1, 19, -1, 39, -1, -1, -1, -1, -1, 40, -1, -1, -1, -1, 28, 41, -1, //(0, 2, 1) ~ (2, 2, 1)
				   6, -1, 26, -1, -1, 45,  7, -1, -1, -1, -1, 46,  8, -1, -1, 33, -1, 47, //(0, 0, 2) ~ (2, 0, 2)
				   3, -1, 23, -1, -1, -1,  4, -1, -1, -1, -1, -1,  5, -1, -1, 30, -1, -1, //(0, 1, 2) ~ (2, 1, 2)
				   0, -1, 20, -1, 42, -1,  1, -1, -1, -1, 43, -1,  2, -1, -1, 27, 44, -1  //(0, 2, 2) ~ (2, 2, 2)
                  };

int mapTable2[54]; 

void makeTable2()
{
	for (int i = 0; i < 162; ++i)
	{
		if (mapTable1[i] >= 0) mapTable2[mapTable1[i]] = i;
	}
}

struct Config
{
	int name, //0: digit, 1: ascii
	    dim; //1: 王同学, 2: 赵同学
};

Config LoadConfig(string filename)
{
	Config config;
	ifstream fin;
	fin.open(filename.c_str());
	string data;
	while (getline(fin, data))
	{
		if (data == "NAME = digit")
		{
			config.name = 0;
		}
		else if (data == "NAME = ascii")
		{
			config.name = 1;
		}
		else if (data == "DIM = 1")
		{
			config.dim = 1;
		}
		else if (data == "DIM = 2")
		{
			config.dim = 2;
		}
	}
	return config;
}

Cube LoadCube(Config config, string filename)
{
	ifstream fin;
	fin.open(filename.c_str());
	string cubeData;
	string data;
	while (getline(fin, data))
	{
		if (config.name == 0)
		{
			for (int i = 0; i < data.size(); ++i)
			{
				cubeData += ColorCharMap((CubeColor)(data[i] - '0'));
			}
		}
		else
		{
			cubeData += data;
		}
	}

	string cubeString;
	for (int i = 0; i < 162; ++i)
	{
		if (mapTable1[i] >= 0)
		{
			cubeString += cubeData[mapTable1[i]];
		}
		else
		{
			cubeString += '-';
		}
	}

	Cube cube;
	cube.Load(cubeString);
	return cube;
}

void PrintCube(Config config, Cube &cube)
{
	string cubeString = cube.Save();
	string cubeData;
	for (int i = 0; i < 54; ++i)
	{
		cubeData += cubeString[mapTable2[i]];
	}
	for (int i = 0; i < 54; ++i)
	{
		if (config.name == 1) //ascii
		{
			cout << cubeData[i];
		}
		else //digit
		{
			cout << (char)(CharColorMap(cubeData[i]) + '0');
		}

		if (i > 0 && (i + 1) % 9 == 0) 
		{
			cout << endl;
		}

		if (i > 0 && (i + 1) % 3 == 0 && (i + 1) % 9 != 0) 
		{ 
			cout << endl;
		}
	}
}

int main()
{
	makeTable2();
	Config config = LoadConfig("config.ini");
	string cubefile;
	cin >> cubefile;
	Cube cube = LoadCube(config, cubefile);
	PrintCube(config, cube);

	string command;
	getline(cin, command);

	while (getline(cin, command))
	{
		CubeRotateMethod method = NameToCubeRotateMethod(command);
		if (method == ROTATE_NONE) break;
		cube.DoMethod(method);
		PrintCube(config, cube);
	}

	return 0;
}
