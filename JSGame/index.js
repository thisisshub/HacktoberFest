const ARROW_CODES = {
    37: 'left',
    38: 'up',
    39: 'right'
}

let arrows = trackKeys(ARROW_CODES);

function trackKeys(keyCodes) {
    let pressedKeys = {};
    function handler(event) {
        if (keyCodes.hasOwnProperty(event.keyCode)) {
            let downPressed = event.type === 'keydown';
            pressedKeys[keyCodes[event.keyCode]] = downPressed;
            event.preventDefault();
        }
    };
    addEventListener("keydown", handler);
    addEventListener("keyup", handler);

    return pressedKeys;
}

function runAnimation(frameFunction) {
    lastTime = null;
    function frame(time) {
        let stop = false;
        if (lastTime !== null) {
            let timeStep = Math.min(time - lastTime, 100) / 1000;
            stop = frameFunction(timeStep) === false;
        }
        lastTime = time;
        if (!stop) requestAnimationFrame(frame);
    }
    requestAnimationFrame(frame);
}

function runLevel(level, Display, callback) {
    let display = new Display(document.body, level);
    runAnimation(function(step) {
        level.animate(step, arrows);
        display.drawFrame();
        if (level.isFinished()) {
            display.clear();
            if (callback) callback(level.status);
            return false;
        }
    })
}

function runGame (levels, Display) {
    function startLevel(levelNumber) {
        let levelObject;
        try {
            levelObject = new Level(levels[levelNumber]);
        } catch(error) {
            return alert(error);
        }
        
        runLevel(levelObject, Display, status => {
            if (status === 'lost') startLevel(levelNumber);
            else if (levelNumber < levels.length - 1) startLevel(levelNumber + 1);
            else alert('¡HAS GANADO!')
        });
    }
    startLevel(0);
}

runGame(GAME_LEVELS, DOMDisplay);

/*let level = new Level(GAME_LEVELS);
let display = new DOMDisplay(document.body, level);
display.drawBackground();*/