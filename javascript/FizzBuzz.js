const fizzbuzz = (n) => {
    let str;
    for (let i = 1; i < n+1; i++) {
        str = null;
        if (i % 3 === 0)
            str = (str || "") + "Fizz";
        if (i % 5 === 0)
            str = (str || "") + "Buzz";

        if (str)
            console.log(str);
        else
            console.log(i);
    }
}
