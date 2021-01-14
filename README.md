# Fbinigma
The infinite combinations cipher

Features > default enigma:
 - Supports every character (0-255)
 - Unlimited rotors.
 - Rotor values have no particular order.
 - 1 in 255 chance hat a character will become itself.
 
How it works:
1. Encryption: Input 'a' -> 'a' in decimal is 65 -> get the value of the index 65 of 1st rotor -> get the value of the index of the value of the first rotor -> ... all untill you reach the last rotor and the last value will be the output character. After one char gave the output, first rotor rotates to the right and second rotor rotates to the left, when they do a full rotation 3th rotor rotates.. and so on..
2. Decryption: For example, 'a' char - encrypted: go to last rotor, find the 'a' char, get its index in the rotor, take that index and move to the rotor infront of him, in him find the character with the value of that index, do that until you come to the first rotor and you decrypted a char, rotate the rotors and move on to next char.

 
