void setup(){
    //this function is called exactly one time when the sketch starts
    //creates a drawing area, 500px X 500 px
    size(500,500);
}

void draw(){
    //this function is called 60 times per second
    //draws a white background (this effectively erases the previous frame)
    background(255,255,255);
    //this next lines draws an ellipse
    ellipse(100,100,100,100);
}
