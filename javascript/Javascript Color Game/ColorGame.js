var numSquares=6;
var colors= [];
var pickedcolor; 
var h1=document.querySelector('h1');
var squares=document.querySelectorAll('.square');
var colorDisplay=document.getElementById('colorDisplay');
var messageDisp=document.querySelector('#message');
var resetButton=document.querySelector('#reset');
var modeButtons=document.querySelectorAll('.mode');

init();

function init(){
	setUpModeButtons();
	setUpSquare();
	reset();
}

function setUpModeButtons(){
	//mode buttons event listeners
for(var i=0;i<modeButtons.length;i++){
	modeButtons[i].addEventListener('click',function(){
		modeButtons[0].classList.remove('selected');
		modeButtons[1].classList.remove('selected');
		this.classList.add('selected');
		this.textContent==="Easy"?numSquares=3:numSquares=6;
		reset();
	});
	}
}

function setUpSquare(){
for (var i =0;i<squares.length;i++){
	//add click event listeners to colors
	squares[i].addEventListener('click',function(){
		//grab color of clicked square
		var clickedColor= this.style.backgroundColor;
		//check conditions game
		if (clickedColor===pickedcolor){
			messageDisp.textContent="Correct!";
			changeColors(clickedColor);
			h1.style.backgroundColor=clickedColor;
			resetButton.textContent="Play Again!";
		}
		else{
			this.style.backgroundColor='#232323';
			messageDisp.textContent="Try Again!";
		}
	});
}
}

function reset(){
	//generate new colors
	colors=generateRandomColors(numSquares);
	//pick a random color from array
	pickedcolor=pickColor();
	//Change colorDisplay to match picked Color
	resetButton.textContent="New color";
	colorDisplay.textContent=pickedcolor;
	messageDisp.textContent = "";
	//change color of squares
	for(var i=0;i<squares.length;i++){
		if(colors[i]){
		squares[i].style.display="block";
		squares[i].style.backgroundColor=colors[i];			
		}
		else{
		squares[i].style.display="none";
		}
	}
	h1.style.backgroundColor='steelblue';
}

resetButton.addEventListener('click',function(){
reset();	
})


function changeColors(color){
	for(var i=0;i<squares.length;i++)
	{
		squares[i].style.backgroundColor=color;	}
	}

function pickColor()
{
	var random = Math.floor(Math.random() * colors.length);
	return colors[random];
}

function generateRandomColors(num)
{
	var arr=[];
	for(var i=0;i<num;i++){
		arr.push(randomColor());
	}
	return arr;
}


function randomColor(){
	//pick a red from 0 to 255
	var R=Math.floor(Math.random()*256);
	//pick a green from 0 to 255
	var G=Math.floor(Math.random()*256);
	//pick a blue from 0 to 255
	var B=Math.floor(Math.random()*256);
	return "rgb("+R +", "+G+", "+B+")";
}