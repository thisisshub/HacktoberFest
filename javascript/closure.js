//demonstration of closure

function outer() {
    let counter = 0;
    return function() {
        counter++;
        console.log(counter);
    }
    
}
let incrementCounter = outer();
incrementCounter();
