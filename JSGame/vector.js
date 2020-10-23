function Vector(x, y) {
    this.x = x;
    this.y = y;
}

Vector.prototype.plus = function(other) {
    return new Vector(this.x + other.x, this.y + other.y);
}

Vector.prototype.times = function(factor) {
    return new Vector(this.x * factor, this.y * factor);
}