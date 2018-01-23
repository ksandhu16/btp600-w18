#include <iostream>
#include <string>
using namespace std;

class Image;

//this is the abstract base class that forms
//the interface for the strategy
class Exporter{
public:
//this function is implemented in each
//of the different exporters
	virtual void writeToFile(const char* fname, Image& s)=0;
};
class PNGExporter:public Exporter{
public:
	virtual void writeToFile(const char* fname, Image& s);
};

class JPEGExporter:public Exporter{
public:
	virtual void writeToFile(const char* fname, Image& s);
};
class GIFExporter:public Exporter{
public:
	virtual void writeToFile(const char* fname, Image& s);
};

//this is an example of a context. It contains
//the information needed by the algorithm
class Image{
	string pixels_;
	Exporter* exp_;
public:
	Image(){
		pixels_="the picture";
	}
	string pixels() {return pixels_;}
	void setExporter(Exporter* e){
		exp_=e;
	}
	void exportImage(){
		if(exp_)
			exp_->writeToFile("myPicture", *this);
	}

};
void PNGExporter::writeToFile(const char* fname, Image& s){
	cout << "printing to: " << fname << ".png" << endl;
	cout << s.pixels() << endl;
}
void JPEGExporter::writeToFile(const char* fname, Image& s){
	cout << "printing to: " << fname << ".jpg" << endl;
	cout << "compressing" << endl;
	cout << s.pixels() << endl;
}
void GIFExporter::writeToFile(const char* fname, Image& s){
	cout << "printing to: " << fname << ".gif" << endl;
	cout << s.pixels() << endl;
}

//at run time, the appropriate stategy can be set (and even changed)
int main(void){
	Image img;
	Exporter* e;
	int choice;
	cout << "would you like to print to png, jpeg, or gif format?" << endl;
	cout << "1) png" << endl;
	cout << "2) jpeg" << endl;
	cout << "3) gif" << endl;
	cin >> choice;
	if(choice == 1){
		e=new PNGExporter();
	}
	else if(choice==2){
		e=new JPEGExporter();
	}
	else if(choice==3){
		e=new GIFExporter();
	}
	img.setExporter(e);
	img.exportImage();

}