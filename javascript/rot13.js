const rot13 = str => {
    const chars = str.split('');
    let shifted_chars = [];
    
    for (char of chars) {
        let shifted_char;
        if (!/[a-zA-Z]/.test(char))
            shifted_char = char;
        else {
            let shifted_char_code = char.charCodeAt(0);
            shifted_char_code += char.toLowerCase() < 'n' ? 13 : -13;
            shifted_char = String.fromCharCode(shifted_char_code);
        }

        shifted_chars.push(shifted_char);
    }

    return shifted_chars.join('');
}
