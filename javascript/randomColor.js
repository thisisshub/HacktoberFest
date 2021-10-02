
function randomColor(){
    return "#" + ((1<<24)*Math.random() | 0).toString(16)
}

console.log(randomColor())
