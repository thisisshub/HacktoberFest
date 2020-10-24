function newCar({color,speed}) {
  
  function move(time){
    return calculateMove(time)
  }

  /*Private method*/
  function calculateMove(time) {
    return speed * time
  }

  return{
    move,
    color
  }
}


const car= newCar({color:'Red', speed:50})
console.log(car.move(2))
