// javascript reference to our sketch
var pjs = undefined;
var bound = false;

// bind JS to the p5 sketch for two way communication
function bindJavaScript() {
  if(Processing) { pjs = Processing.getInstanceById("a2"); }
  if (pjs !== undefined && pjs.bindJavaScript !== undefined) {
    pjs.bindJavaScript(this);
    bound = true; }
  if(!bound) setTimeout(bindJavaScript, 250);
}

// schedule binding
bindJavaScript();

function addThick(){

    pjs.addThick();
}
function addBorder(){

    pjs.addBorder();
}
function addDots(){

    pjs.addDots();
}
function removeLast(){

}
