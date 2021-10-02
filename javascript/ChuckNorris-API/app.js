//App to fetch joke from chuck-norris api and prints it in the console

function getJoke() {
    fetch('https://api.chucknorris.io/jokes/random')
    .then(response => response.json())
    .then(jokeObject => console.log(jokeObject.value))
    .catch(err => console.log(`Error : ${err}`));
}

getJoke();