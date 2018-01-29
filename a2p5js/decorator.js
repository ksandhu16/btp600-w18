var Label = function(labelText,x,y){
	var that = {};
	var labelText_=labelText || "";
	var x_=x || 200;
	var y_=y || 200;
	var hasBorder_ = false;
	var hasThickRectBorder_= false;
	var hasDots_ = false;
	var width_ = labelText_.length * 10;
	var height_ = 40;


	that.draw = function(){
		if(hasBorder_){
			rectMode(CENTER);
			strokeWeight(1);
			stroke(0,0,0);
			noFill();
			rect(x_,y_,width_,height_);			
		}
		if(hasThickRectBorder_){
			rectMode(CENTER);
			strokeWeight(3);
			stroke(0,0,0);
			noFill();
			rect(x_,y_,width_,height_);						
		}
		if (hasDots_){
			ellipseMode(CENTER);
			strokeWeight(1);
			fill(255,0,0);
			stroke(255,0,0);
			//above label
			for(var i=0;i<width_/10 + 1;i++){
				ellipse((x_-width_/2+i*10),(y_-height_/2),5,5);
			}
			//below label
			for(var i=0;i<width_/10 +1;i++){
				ellipse((x_-width_/2+i*10),(y_+height_/2),5,5);
			}
			//left of label
			for(var i=0;i<height_/10-1;i++){
				ellipse((x_-width_/2),(y_-height_/2+((i+1)*10)),5,5);
			}
			//right of label
			for(var i=0;i<height_/10-1;i++){
				ellipse((x_+width_/2),(y_-height_/2+((i+1)*10)),5,5);
			}
		}
		strokeWeight(1);
		stroke(0,0,0);
		fill(0,0,0);
		textAlign(CENTER,CENTER);
		text(labelText_,x_,y_);

	}
	that.toggleRectBorder = function(){
		if (hasBorder_==true){
			hasBorder_=false;
		}
		else{
			hasBorder_=true;
		}
	}
	that.toggleThickBorder = function(){
		if (hasThickRectBorder_==true){
			hasThickRectBorder_=false;
		}
		else{
			hasThickRectBorder_=true;
		}
	}
	that.toggleDots = function(){
		if (hasDots_==true){
			hasDots_=false;
		}
		else{
			hasDots_=true;
		}
	}

	return that;
};

var l;
var thickBorderButton;
var borderButton;
var dotButton;
var removeButton;
function addBorder(){
	l.toggleRectBorder();
}
function addThick(){
	l.toggleThickBorder();
}
function addDots(){
	l.toggleDots();
}
function setup(){
    thickBorderButton=createButton("Add Thick Border");
    thickBorderButton.mousePressed(addThick);
    borderButton=createButton("Add Border");
    borderButton.mousePressed(addBorder);
    dotButton=createButton("Add Dots Border");
    dotButton.mousePressed(addDots);
    removeButton=createButton("Remove Last");

	createCanvas(500,400);
	l = Label("the Label", 100,100);

}
function checkBorder(){
	l.toggleDots();
}
function draw(){
	background(255,255,255);
	l.draw();
}
	