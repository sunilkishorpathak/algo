/*
** Read metadata from a JPG file
*/

/*
** JPEG : JOINT PHOTGRAPHIC 
** If file has 2 byte header 0xFF 0xD8 (called SOI : Start of Image) : file will be a JPEG/JFIF 
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class FileReader {
public:
	FileReader();
	string FileType(string path);
	bool IsJPEGFile(string path);
	bool OpenFile(string path);
	void Close();
	~FileReader();
private:
	ifstream fs;
};

//constructor
FileReader::FileReader()
{
}

//If file is open, close it
FileReader::~FileReader()
{
	if(fs.is_open())
		fs.close();
}

//Open file
bool FileReader::OpenFile(string path)
{
	fs.open(path, ios::binary);

	return fs.is_open();
}

string FileReader::FileType(string filePath)
{
	string ftype;

	return ftype;
}

bool FileReader::IsJPEGFile(string filePath)
{
	bool isjpeg = false;

	//return if file is not open
	if (!fs.is_open()) {
		cout <<"First open file  " <<endl;
	}

	//Read first 2 bytes, if that is FF D8; return true
	fs.seekg(0);

	char * memblock = new char [2];
	fs.read(memblock, 2);

	if ((memblock[0] == (char) 0xFF) && (memblock[1] == (char) 0xD8))
		isjpeg = true;

	delete[] memblock;

	return isjpeg;
}

void FileReader::Close()
{
	fs.close();
}

int main()
{
	string file("C:\\work\\metadata\\main\\xmp\\toolkit\\samples\\build\\CPP_BOOTCAMP\\LCS\\Debug\\bug2416566.jpg");
	FileReader fr;

	//cout <<"Enter file name : ";
	//getline(cin, file);

	bool ret = fr.OpenFile(file);
	if (ret) {
		bool isjpeg = fr.IsJPEGFile(file);
		cout <<"File " <<file <<"is JPEG file " <<isjpeg <<endl;
		
		fr.Close();
	} else {
		cout <<"File open issue " <<endl;
	}

	return 0;
}


	