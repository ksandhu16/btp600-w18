#include <iostream>
using namespace std;
//This is the abstract component
class ScreenObject{
public:
//screen objects need to be able to draw itself
	virtual void show()=0;
	virtual int width()=0;
};


//a concrete component
class Label:public ScreenObject{
	string text_;

public:
	Label(string s){
		text_=s;
	}
	virtual void show(){
		cout << text_ << endl;
	}
	int width(){
		return text_.length();
	}
};

//Decorator, base decorator object
class Decorator:public ScreenObject{
	ScreenObject* so_;
public:
	Decorator(ScreenObject* s):ScreenObject(){
		so_=s;
	}
	virtual void show(){
		so_->show();
	}
	virtual int width(){
		return so_->width();
	}
};
//concrete decorator
class TopBorder:public Decorator{
	int width_;
public:
	TopBorder(ScreenObject* s,int w):Decorator(s){
		width_=w;
	}
	virtual void show(){
		for(int i=0;i<width_;i++){
			cout << "*";
		}
		cout << endl;
		Decorator::show();
	}
};
//another concrete decorator
class BottomBorder:public Decorator{
	int width_;
public:
	BottomBorder(ScreenObject* s,int w):Decorator(s){
		width_=w;
	}
	virtual void show(){
		Decorator::show();

		for(int i=0;i<width_;i++){
			cout << "*";
		}
		cout << endl;

	}
};

ScreenObject* addTopBorder(ScreenObject* original){
	return new TopBorder(original,original->width());
}
ScreenObject* addBottomBorder(ScreenObject* original){
	return new BottomBorder(original,original->width());
}

int main(void){
	ScreenObject* labels[4];

//objects can be created without any decoration
	labels[0]=new Label("no border label");
	labels[1]=new Label("top border label");
	labels[2]=new Label("bottom border label");
	labels[3]=new Label("both border label");

//objects can then be decorated as program continues
	labels[1]=addTopBorder(labels[1]);
	labels[2]=addBottomBorder(labels[2]);

//you can add more than one... each decorator simply wraps
//previous in it
	labels[3]=addTopBorder(labels[3]);
	labels[3]=addBottomBorder(labels[3]);

//note that all 4 objects are decorated differently.
//however in this loop we can display them all with the same
//function call
	for(int i=0;i<4;i++){
		labels[i]->show();

		cout << endl << endl;
	}
//while the code does not do this, it is possible to remove
//a decorator too.
}