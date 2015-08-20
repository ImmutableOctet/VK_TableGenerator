// Preprocessor related:
#define GENERATE_ALL

// Includes:
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

// Namespace(s):
using namespace std;

// Functions:
template <typename strSymbol_t, typename T>
void emitSymbol(ostream& s, const strSymbol_t strSymbol, const T symbol, const bool trailing_comma=true)
{
	s << "{\"VK_" << strSymbol << "\", VK_" << symbol << "}";

	if (trailing_comma)
	{
		s << ",";
	}

	s << endl;

	return;
}

template <typename T>
void emitSymbol(ostream& s, const T symbol, const bool trailing_comma=true)
{
	s << "{\"VK_"<<symbol<<"\", VK_"<<symbol<<"}";
	
	if (trailing_comma)
	{
		s << ",";
	}

	s << endl;

	return;
}

void emitSymbols(ostream& f)
{
	emitSymbol(f, "LBUTTON");
	emitSymbol(f, "RBUTTON");
	emitSymbol(f, "CANCEL");
	emitSymbol(f, "MBUTTON");

	#if (defined(GENERATE_ALL) || (_WIN32_WINNT >= 0x0500))
		emitSymbol(f, "XBUTTON1");
		emitSymbol(f, "XBUTTON2");
	#endif

	emitSymbol(f, "BACK");
	emitSymbol(f, "TAB");

	emitSymbol(f, "CLEAR");
	emitSymbol(f, "SHIFT");
	emitSymbol(f, "CONTROL");
	emitSymbol(f, "MENU");
	emitSymbol(f, "PAUSE");
	emitSymbol(f, "CAPITAL");
	
	emitSymbol(f, "KANA");
	emitSymbol(f, "HANGEUL");
	emitSymbol(f, "HANGUL");
	emitSymbol(f, "JUNJA");
	emitSymbol(f, "FINAL");
	emitSymbol(f, "HANJA");
	emitSymbol(f, "KANJI");

	emitSymbol(f, "ESCAPE");
	emitSymbol(f, "CONVERT");
	emitSymbol(f, "NONCONVERT");
	emitSymbol(f, "ACCEPT");
	emitSymbol(f, "MODECHANGE");

	emitSymbol(f, "SPACE");
	emitSymbol(f, "PRIOR");
	emitSymbol(f, "NEXT");
	emitSymbol(f, "END");
	emitSymbol(f, "HOME");
	emitSymbol(f, "LEFT");
	emitSymbol(f, "UP");
	emitSymbol(f, "RIGHT");
	emitSymbol(f, "DOWN");
	emitSymbol(f, "SELECT");
	emitSymbol(f, "PRINT");
	emitSymbol(f, "EXECUTE");
	emitSymbol(f, "SNAPSHOT");
	emitSymbol(f, "INSERT");
	emitSymbol(f, "DELETE");
	emitSymbol(f, "HELP");

	f << hex;

	// Numbers:
	for (unsigned i = 0; i <= 9; i++)
	{
		f << "{\"VK_"<<i<<"\", 0x" << uppercase << (0x30+i) << "}," << endl;
	}

	// Alphabet / face buttons:
	for (char a = 'A'; a <= 'Z'; a++)
	{
		f << "{\"VK_"<<a<<"\", 0x" << uppercase << (0x41+a) << "}," << endl;
	}

	f << dec;

	emitSymbol(f, "LWIN");
	emitSymbol(f, "RWIN");
	emitSymbol(f, "APPS");

	emitSymbol(f, "SLEEP");

	// Numpad / other:
	for (unsigned i = 0; i <= 9; i++)
	{
		f << "{\"VK_NUMPAD"<<i<<"\", VK_NUMPAD"<<i<<"}," << endl;
	}

	emitSymbol(f, "MULTIPLY");
	emitSymbol(f, "ADD");
	emitSymbol(f, "SEPARATOR");
	emitSymbol(f, "SUBTRACT");
	emitSymbol(f, "DECIMAL");
	emitSymbol(f, "DIVIDE");

	// Function buttons:
	for (unsigned fk = 1; fk <= 24; fk++)
	{
		f << "{\"VK_F"<<fk<<"\", VK_F"<<fk<<"}," << endl;
	}

	emitSymbol(f, "NUMLOCK");
	emitSymbol(f, "SCROLL");

	emitSymbol(f, "OEM_NEC_EQUAL");

	emitSymbol(f, "OEM_FJ_JISHO");
	emitSymbol(f, "OEM_FJ_MASSHOU");
	emitSymbol(f, "OEM_FJ_TOUROKU");
	emitSymbol(f, "OEM_FJ_LOYA");
	emitSymbol(f, "OEM_FJ_ROYA");

	emitSymbol(f, "LSHIFT");
	emitSymbol(f, "RSHIFT");
	emitSymbol(f, "LCONTROL");
	emitSymbol(f, "RCONTROL");
	emitSymbol(f, "LMENU");
	emitSymbol(f, "RMENU");

	#if (defined(GENERATE_ALL) || (_WIN32_WINNT >= 0x0500))
		emitSymbol(f, "BROWSER_BACK");
		emitSymbol(f, "BROWSER_FORWARD");
		emitSymbol(f, "BROWSER_REFRESH");
		emitSymbol(f, "BROWSER_STOP");
		emitSymbol(f, "BROWSER_SEARCH");
		emitSymbol(f, "BROWSER_FAVORITES");
		emitSymbol(f, "BROWSER_HOME");
		
		emitSymbol(f, "VOLUME_MUTE");
		emitSymbol(f, "VOLUME_DOWN");
		emitSymbol(f, "VOLUME_UP");
		emitSymbol(f, "MEDIA_NEXT_TRACK");
		emitSymbol(f, "MEDIA_PREV_TRACK");
		emitSymbol(f, "MEDIA_STOP");
		emitSymbol(f, "MEDIA_PLAY_PAUSE");
		emitSymbol(f, "LAUNCH_MAIL");
		emitSymbol(f, "LAUNCH_MEDIA_SELECT");
		emitSymbol(f, "LAUNCH_APP1");
		emitSymbol(f, "LAUNCH_APP2");
	#endif

	// OEM Symbols:
	emitSymbol(f, "OEM_1");
	emitSymbol(f, "OEM_PLUS");
	emitSymbol(f, "OEM_COMMA");
	emitSymbol(f, "OEM_MINUS");
	emitSymbol(f, "OEM_PERIOD");

	for (unsigned i = 2; i <= 8; i++)
	{
		f << "{\"VK_OEM_"<<i<<"\", VK_OEM_"<<i<<"}," << endl;
	}

	emitSymbol(f, "OEM_AX");
	emitSymbol(f, "OEM_102");
	emitSymbol(f, "ICO_HELP");
	emitSymbol(f, "ICO_00");

	#if (defined(GENERATE_ALL) || (WINVER >= 0x0400))
		emitSymbol(f, "PROCESSKEY");
	#endif

	emitSymbol(f, "ICO_CLEAR");

	#if (defined(GENERATE_ALL) || (_WIN32_WINNT >= 0x0500))
		emitSymbol(f, "PACKET");
	#endif

	emitSymbol(f, "OEM_RESET");
	emitSymbol(f, "OEM_JUMP");
	emitSymbol(f, "OEM_PA1");
	emitSymbol(f, "OEM_PA2");
	emitSymbol(f, "OEM_PA3");
	emitSymbol(f, "OEM_WSCTRL");
	emitSymbol(f, "OEM_CUSEL");
	emitSymbol(f, "OEM_ATTN");
	emitSymbol(f, "OEM_FINISH");
	emitSymbol(f, "OEM_COPY");
	emitSymbol(f, "OEM_AUTO");
	emitSymbol(f, "OEM_ENLW");
	emitSymbol(f, "OEM_BACKTAB");
	
	emitSymbol(f, "ATTN");
	emitSymbol(f, "CRSEL");
	emitSymbol(f, "EXSEL");
	emitSymbol(f, "EREOF");
	emitSymbol(f, "PLAY");
	emitSymbol(f, "ZOOM");
	emitSymbol(f, "NONAME");
	emitSymbol(f, "PA1");
	
	// This is currently the final entry.
	emitSymbol(f, "OEM_CLEAR", false);

	return;
}

int main(int argc, char** argv)
{
	// Enumerator(s):
	enum generatorMode
	{
		MODE_FILE,
		MODE_STDOUT,
	};

	// Local variable(s):
	generatorMode mode;
	string filePath;

	if (argc > 1)
	{
		try
		{
			mode = (generatorMode)stoi(argv[1]);
		}
		catch (const invalid_argument&)
		{
			filePath = argv[1];
		}
	}
	else
	{
		mode = MODE_FILE;
		filePath = "vk.txt";
	}

	switch (mode)
	{
		case MODE_FILE:
			{
				ofstream f;

				f.open(filePath);

				emitSymbols(f);

				f.close();

				cout << "File generated." << endl;
			}

			break;
		case MODE_STDOUT:
			emitSymbols(cout);

			//cout << "Output finished." << endl;

			break;
		default:
			return 1; // -1;
	}

	cout << "Press enter to continue..." << endl;

	cin.get();

	// Return the default response.
	return 0;
}