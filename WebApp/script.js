// Morse Code Mappings
const morseEncodeMap = {
    'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 'F': '..-.', 'G': '--.', 'H': '....', 'I': '..',
    'J': '.---', 'K': '-.-', 'L': '.-..', 'M': '--', 'N': '-.', 'O': '---', 'P': '.--.', 'Q': '--.-', 'R': '.-.',
    'S': '...', 'T': '-', 'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-', 'Y': '-.--', 'Z': '--..', '1': '.----',
    '2': '..---', '3': '...--', '4': '....-', '5': '.....', '6': '-....', '7': '--...', '8': '---..', '9': '----.',
    '0': '-----', ' ': '/'
};

const morseDecodeMap = Object.fromEntries(Object.entries(morseEncodeMap).map(([k, v]) => [v, k]));

// Function to encode text to Morse code
function encodeToMorse(text) {
    return text.toUpperCase().split('').map(char => morseEncodeMap[char] || '?').join(' ');
}

// Function to decode Morse code to text
function decodeFromMorse(morseCode) {
    return morseCode.split(' ').map(code => morseDecodeMap[code] || '?').join('');
}

// Event listeners for buttons
document.getElementById('encodeBtn').addEventListener('click', () => {
    const inputText = document.getElementById('inputText').value;
    const encodedText = encodeToMorse(inputText);
    document.getElementById('outputText').value = encodedText;
});

document.getElementById('decodeBtn').addEventListener('click', () => {
    const inputText = document.getElementById('inputText').value;
    const decodedText = decodeFromMorse(inputText);
    document.getElementById('outputText').value = decodedText;
});
