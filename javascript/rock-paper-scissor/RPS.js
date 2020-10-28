//declaring constants for DOM

let userScore = 0;
let compScore =0;
const userScore_span = document.getElementById("user-score");
const compScore_span = document.getElementById("comp-score");
const scoreBoard_div = document.querySelector(".score_board");
const result_div = document.querySelector(".result");
const rock_div = document.getElementById("r");
const paper_div = document.getElementById("p");
const scissor_div = document.getElementById("s");

//function will return random values of r,p,s
function getComputerChoice() {
    const choices = ['r','p','s'];
    const randomNum = Math.floor(Math.random()*3);
    return choices [randomNum];
}

//to convert r,p,s to rock,paper,scissor
function convert(letter) {
    if(letter==='r') return "Rock";
    if(letter==='p') return "Paper";
    return "Scissor";

}
 
//put (user) and(comp) in subscript
function win(userInput,compChoice) {
    const smallUserWord = "(user)".fontsize(3).sub();
    const smallCompWord = "(comp)".fontsize(3).sub();
    const userInputDiv = document.getElementById(userInput);

    userScore++;
    userScore_span.innerHTML = userScore;
    result_div.innerHTML = `${convert(userInput)}${smallUserWord} beats ${convert(compChoice)}${smallCompWord}. You win.!`;
    
//temporarily adds a class of green-glow

    userInputDiv.classList.add('green-glow');

//removes the tmp class after 300ms

    setTimeout(()=> userInputDiv.classList.remove('green-glow'), 300);
}
function lost(userInput,compChoice) {
    compScore++;
    compScore_span.innerHTML = compScore;
    const smallUserWord = "(user)".fontsize(3).sub();
    const smallCompWord = "(comp)".fontsize(3).sub();
    const userInputDiv = document.getElementById(userInput);
    result_div.innerHTML = `${convert(compChoice)}${smallCompWord} beats ${convert(userInput)}${smallUserWord}. You lose :(`;
    userInputDiv.classList.add('red-glow');
    setTimeout(() =>userInputDiv.classList.remove('red-glow'), 300);
    ``
}
function draw(userInput,compChoice) {
    const smallUserWord = "(user)".fontsize(3).sub();
    const smallCompWord = "(comp)".fontsize(3).sub();
    const userInputDiv = document.getElementById(userInput);
    result_div.innerHTML = `${convert(compChoice)}${smallCompWord} equals ${convert(userInput)}${smallUserWord}. Its a draw.`;
    userInputDiv.classList.add('grey-glow');
    setTimeout(() =>userInputDiv.classList.remove('grey-glow'), 300);
}

//tells who wins
function game(userInput) {
    const computerChoice = getComputerChoice();
    switch(userInput + computerChoice) {
        case "rs":
        case "pr":
        case "sp":
            win(userInput,computerChoice);
            break;

        case "rp":
        case "ps":
        case "sr":
            lost(userInput,computerChoice);
            break;
        case "rr":
        case "ss":
        case "pp":
            draw(userInput,computerChoice);
            break;

    }
}

//function returns the user choice
function main() {
    rock_div.addEventListener('click', ()=> 
        game("r"));

    paper_div.addEventListener('click', ()=>
        game("p"));

    scissor_div.addEventListener('click',() =>
        game("s"));
}
main();
getComputerChoice();