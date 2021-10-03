var number1 = Math.round(Math.random() * 100)
const number1box = document.getElementById("number1")
number1box.innerHTML = number1

var number2 = Math.round(Math.random() * 100)
const number2box = document.getElementById("number2")
number2box.innerHTML = number2

const greaterThan = document.getElementById("greater-than")
const equalTo = document.getElementById("equal-to")
const lesserThan = document.getElementById("lesser-than")

var score = 0

greaterThan.onclick = () => {
    if (number1 > number2) {
        score++;
        resetTime(timerId)
    } else {
        location.href = "./gameover.html?score=" + score;
    }

    number1 = Math.round(Math.random() * 100)
    number1box.innerHTML = number1
    number2 = Math.round(Math.random() * 100)
    number2box.innerHTML = number2
}

lesserThan.onclick = () => {
    if (number1 < number2) {
        score++;
        resetTime(timerId)
    } else {
        location.href = "./gameover.html?score=" + score;
    }

    number1 = Math.round(Math.random() * 100)
    number1box.innerHTML = number1
    number2 = Math.round(Math.random() * 100)
    number2box.innerHTML = number2
}

equalTo.onclick = () => {
    if (number1 == number2) {
        score++;
        resetTime(timerId)
    } else {
        location.href = "./gameover.html?score=" + score;
    }

    number1 = Math.round(Math.random() * 100)
    number1box.innerHTML = number1
    number2 = Math.round(Math.random() * 100)
    number2box.innerHTML = number2
}

var time = 2;
var timer = document.getElementById("timer");
var timerId;

function startTimer() {
    time = 2;
    timer.innerHTML = time;
    timerId = setInterval(() => {
        time--;
        if (time == 0) {
            location.href = "./gameover.html?score=" + score;
        }
        timer.innerHTML = time;
    }, 1000);
}

function resetTime(intervalId) {
    clearInterval(intervalId);
    startTimer();
}

startTimer();