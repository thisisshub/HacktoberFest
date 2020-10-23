const ACTORS = {
    'o': Coin,
    '@': Player,
    '=': Lava,
    '|': Lava,
    'v': Lava
};

const MAX_STEP = 0.05;
const gameAudio = new Audio('./sounds/coin.wav')

//Constructor del objeto level de index.js
function Level(plan) {
    if (!validateLevel(plan)) throw new Error('You need a player and a coin.');
    
    this.width = plan[0].length;
    this.height = plan.length;
    this.status = null;
    this.finishDelay = null;

    this.grid = [];
    this.actors = [];

    for (let y = 0; y < this.height; y++) {
        let line = plan[y];
        let gridLine = [];
        for (let x = 0; x < this.width; x++) {
            var character = line[x];
            var characterType = null;
            let Actor = ACTORS[character];
            if (Actor) this.actors.push(new Actor(new Vector(x, y), character));
            if (character === 'x') characterType = 'wall';
            else if (character === '!') characterType = 'lava';
            gridLine.push(characterType);
        }
        this.grid.push(gridLine);
        //console.log(gridLine);
    }
    
    this.player = this.actors.filter(actor => actor.type === 'player')[0];

    //console.log(this.actor);

}

Level.prototype.isFinished = function() {
    return (this.status !== null && this.finishDelay < 0);
}

Level.prototype.animate = function(step, keys) {
    if (this.status !== null) this.finishDelay -= step;

    while (step > 0) {
        let thisStep = Math.min(step, MAX_STEP);
        //console.log(thisStep);
        this.actors.forEach(actor => actor.act(thisStep, this, keys));
        step -= thisStep;
    }
}

Level.prototype.obstacleAt = function(position, size) {
    let xStart = Math.floor(position.x);
    let xEnd = Math.ceil(position.x + size.x);
    let yStart = Math.floor(position.y);
    let yEnd = Math.ceil(position.y + size.y);

    if (xStart < 0 || xEnd > this.width || yStart < 0) return 'wall';
    if (yEnd > this.height) return 'lava';

    for (let y = yStart; y < yEnd; y++) {
        for (let x = xStart; x < xEnd; x++) {
            let fieldType = this.grid[y][x];
            if (fieldType) return fieldType;
        } 
    }
}

Level.prototype.playerTouched = function(type, actor) {
    if (type === 'lava' && this.status == null) {
        this.status = 'lost';
        this.finishDelay = 1;
    } else if (type === 'coin') {
        playAudio();
        this.actors = this.actors.filter(otherActor => otherActor !== actor);
        console.log(this.actors);
        if (!remainCoins(this.actors)) {
            this.status = 'won';
            this.finishDelay = 2;
        }
    }
}

Level.prototype.actorAt = function(actor) {
    for (let i = 0; i < this.actors.length; i++) {
        let other = this.actors[i];
        if (actor !== other && 
        actor.position.x + actor.size.x > other.position.x && 
        actor.position.x < other.position.x + other.size.x &&
        actor.position.y + actor.size.y > other.position.y && 
        actor.position.y < other.position.y + other.size.y) return other;
    }
}

function validateLevel(level) {
    return (level.some(row => row.indexOf('@') !== -1) && level.some(row => row.indexOf('o') !== -1))
} 

function remainCoins(actors) {
    return actors.some(actor => actor.type === 'coin');
}

function playAudio() {
    gameAudio.pause();
    gameAudio.currentTime = 0;
    gameAudio.play();
}