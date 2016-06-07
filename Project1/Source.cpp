//#include <opencv\cv.h>
#include <opencv2/opencv.hpp>
#include <opencv\highgui.h>
#include <Windows.h>
#include <fstream>


using namespace cv;


void openSpotify() {
		ShellExecute(NULL, "open", "C:\\Users\\Mateusz\\AppData\\Roaming\\Spotify\\SpotifyLauncher.exe", NULL, NULL, SW_SHOWDEFAULT);
}

void readKey(unsigned char key){
	
	switch (key)
		{
		case 'w': {
			ShellExecute(NULL, "open", "clmcontrol.exe", "spotify -mvu -mvu", NULL, SW_HIDE);
			//up
			break;
		}
		case 's': {	
			ShellExecute(NULL, "open", "clmcontrol.exe", "spotify -mvd -mvd", NULL, SW_HIDE);
			//down
			break;
		}
		case 'a': {	
			ShellExecute(NULL, "open", "clmcontrol.exe", "spotify -pt", NULL, SW_HIDE);
			//left
			break;
		}
		case 'd': {	
			ShellExecute(NULL, "open", "clmcontrol.exe", "spotify -nt", NULL, SW_HIDE);
			//right
			break;
		}
		case 32: {
			ShellExecute(NULL, "open", "clmcontrol.exe", "spotify -pp", NULL, SW_HIDE);
			//space
			break;
		}
	}
}

int main() {
	
	HWND isOpened = FindWindow(NULL, "Spotify");
	if (isOpened == NULL)
	{
		openSpotify();
	}

	Mat image;          //Create Matrix to store image
	VideoCapture cap;          //initialize capture
	cap.open(0);
	namedWindow("window", 1); //create window to show image
	
	unsigned char key = NULL;
	waitKey(1000);
	isOpened = FindWindow(NULL, "Spotify");
	ShowWindow(isOpened, SW_FORCEMINIMIZE);


	while (key!=27) {
		cap >> image;            //copy webcam stream to image
		imshow("window", image); //print image to screen
		key = waitKey(33);       //delay 33ms
		readKey(key);
	}

	return 0;
}