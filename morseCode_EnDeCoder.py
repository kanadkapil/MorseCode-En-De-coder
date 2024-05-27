# Morse Code Mappings
morse_encode_map = {
    'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 'F': '..-.', 'G': '--.', 'H': '....', 'I': '..',
    'J': '.---', 'K': '-.-', 'L': '.-..', 'M': '--', 'N': '-.', 'O': '---', 'P': '.--.', 'Q': '--.-', 'R': '.-.',
    'S': '...', 'T': '-', 'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-', 'Y': '-.--', 'Z': '--..', '1': '.----',
    '2': '..---', '3': '...--', '4': '....-', '5': '.....', '6': '-....', '7': '--...', '8': '---..', '9': '----.',
    '0': '-----', ' ': '/'
}

morse_decode_map = {v: k for k, v in morse_encode_map.items()}

# Function to encode text to Morse code
def encode_to_morse(text):
    return ' '.join(morse_encode_map.get(char.upper(), '?') for char in text)

# Function to decode Morse code to text
def decode_from_morse(morse_code):
    return ''.join(morse_decode_map.get(code, '?') for code in morse_code.split())

# Main function
def main():
    while True:
        print("Morse Code Encoder/Decoder")
        print("1. Encode to Morse Code")
        print("2. Decode from Morse Code")
        print("3. Exit")
        choice = input("Choose an option (1, 2, or 3): ")

        if choice == '1':
            text = input("Enter text to encode: ")
            encoded_text = encode_to_morse(text)
            print("Encoded Morse Code:", encoded_text)
        elif choice == '2':
            morse_code = input("Enter Morse Code to decode (use space between characters and '/' for space between words): ")
            decoded_text = decode_from_morse(morse_code)
            print("Decoded Text:", decoded_text)
        elif choice == '3':
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
