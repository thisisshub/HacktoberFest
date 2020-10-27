c = document.getElementById('c').getContext('2d')
l = 1
a = [{ x: 0, y: 0 }]
xv = yv = 0
window.onkeydown = function (e) {
  e = e.keyCode
  if (e == 37) {
    xv = -1
    yv = 0
  }
  if (e == 38) {
    xv = 0
    yv = -1
  }
  if (e == 39) {
    xv = 1
    yv = 0
  }
  if (e == 40) {
    xv = 0
    yv = 1
  }
}
function g() {
  f = {
    x: Math.floor(Math.random() * 15),
    y: Math.floor(Math.random() * 15),
  }
}
g()
function d() {
  x = a[0].x + xv
  y = a[0].y + yv
  if (x > 14) {
    x = 0
  }
  if (x < 0) {
    x = 14
  }
  if (y > 14) {
    y = 0
  }
  if (y < 0) {
    y = 14
  }
  a.unshift({ x: x, y: y })
  for (var i = 1; i < l; i++) {
    if (x == a[i].x && y == a[i].y) {
      l = 1
    }
  }
  if (x == f.x && y == f.y) {
    l++
    g()
  }
  c.clearRect(0, 0, 500, 500)
  c.strokeRect(0, 0, 15 * 30, 15 * 30)
  for (var i = 0; i < l; i++) {
    c.fillRect(a[i].x * 30, a[i].y * 30, 25, 25)
  }
  c.fillRect(f.x * 30, f.y * 30, 25, 25)
}
setInterval(d, 100)
