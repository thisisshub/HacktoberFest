const counter = document.getElementById('counter');
const incr = document.querySelector('.incr');
const decr = document.querySelector('.decr');

let count = 0;
incr.addEventListener("click", () => {
    count++;
    counter.innerHTML = count;
})
decr.addEventListener("click", () => {
    if(count<=0){ 
        count=0;
    } 
    else count--;
    
    counter.innerHTML = count;
})
