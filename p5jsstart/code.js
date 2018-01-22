function setup(){
    //this function is called exactly one time when the sketch starts
    //creates a drawing area, 500px X 500 px
    createCanvas(500,500);
}

function draw(){
    //this function is called 60 times per second
    //draws a white background (this effectively erases the previous frame)
    background(255,255,255);
    //this next lines draws an ellipse
    ellipse(100,100,100,100);
}
