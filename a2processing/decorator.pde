class Label{
	string labelText_;
	bool hasBorder_;
	bool hasThickRectBorder_;
	bool hasDots_;

	int x_;
	int y_;
	int width_;
	int height_;

	Label(string s, int x, int y){
		labelText_=s;
		x_=x;
		y_=y;
		width_=s.length()*10;
		height_=40;
		hasBorder_=false;
		hasThickRectBorder_=false;
		hasDots_=false;

	}
	void draw(){
		if(hasBorder_){
			rectMode(CENTER);
			strokeWeight(1);
			stroke(1,1,1);
			noFill();
			rect(x_,y_,width_,height_);			
		}
		if(hasThickRectBorder_){
			rectMode(CENTER);
			strokeWeight(3);
			stroke(1,1,1);
			noFill();
			rect(x_,y_,width_,height_);						
		}
		if (hasDots_){
			ellipseMode(CENTER);
			strokeWeight(1);
			fill(255,0,0);
			stroke(255,0,0);
			//above label
			for(int i=0;i<width_/10 + 1;i++){

				ellipse((x_-width_/2+i*10),(y_-height_/2),5,5);
			}
			//below label
			for(int i=0;i<width_/10 +1;i++){
				ellipse((x_-width_/2+i*10),(y_+height_/2),5,5);
			}
			//left of label
			for(int i=0;i<height_/10-1;i++){
				ellipse((x_-width_/2),(y_-height_/2+((i+1)*10)),5,5);
			}
			//right of label
			for(int i=0;i<height_/10-1;i++){
				ellipse((x_+width_/2),(y_-height_/2+((i+1)*10)),5,5);
			}
		}
		strokeWeight(1);
		stroke(0,0,0);
		fill(0,0,0);
		textAlign(CENTER,CENTER);
		text(labelText_,x_,y_);
	}
	void toggleRectBorder(){
		if (hasBorder_==true){
			hasBorder_=false;
		}
		else{
			hasBorder_=true;
		}
	}
	void toggleThickBorder(){
		if (hasThickRectBorder_==true){
			hasThickRectBorder_=false;
		}
		else{
			hasThickRectBorder_=true;
		}
	}
	void toggleDots(){
		if (hasDots_==true){
			hasDots_=false;
		}
		else{
			hasDots_=true;
		}
	}
}
Label l;
void addBorder(){
	l.toggleRectBorder();
}
void addThick(){
	l.toggleThickBorder();
}
void addDots(){
	l.toggleDots();
}
void setup(){
	size(500,400);
	l = new Label("the Label", 150,200);
}
void draw(){
	background(255,255,255)
	l.draw();
}