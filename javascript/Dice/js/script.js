var player = Math.floor(Math.random()*6)+1;
var computer = Math.floor(Math.random()*6)+1;
var winner;


if (player > computer) {
  winner =  "You win!";
} else if (player == computer) {
  winner =  "Tie!";
} else {
  winner =  "You lost!";
}

document.getElementById("winner") .innerHTML = winner;
document.getElementById("you") .innerHTML = "You:" + " " + player;
document.getElementById("pc") .innerHTML = "Computer:" + " " + computer;

//CON DUE DADI
var gdado1 = Math.floor(Math.random()*6)+1;
var gdado2 = Math.floor(Math.random()*6)+1;
var player = gdado1+gdado2;
var cdado1 = Math.floor(Math.random()*6)+1;
var cdado2 = Math.floor(Math.random()*6)+1;
var computer = cdado1+cdado2;
var winner;


if (player > computer) {
  winner =  "You win!";
} else if (player == computer) {
  winner =  "Tie!";
} else {
  winner =  "You lost!";
}

document.getElementById("winner2") .innerHTML = winner;
document.getElementById("you2") .innerHTML = "You:" + " " + gdado1 + " , " + gdado2 + " = " + player;
document.getElementById("pc2") .innerHTML = "Computer:" + " " + cdado1 + " , " + cdado2 + " = " + computer;
