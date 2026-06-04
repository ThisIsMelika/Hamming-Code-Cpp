---

# Hamming Code in C++

**A robust implementation of the Hamming Error-Correcting Code for encoding, single-bit error detection, and correction.**

---

##  Overview

This project implements the **(21, 16) Hamming Code** in C++. It can:

- Encode 16-bit data messages into 21-bit codewords by adding 5 parity bits.
- Detect and locate single-bit errors in the received codeword.
- Correct the detected error automatically.
- Verify message integrity.

Hamming Code is a classic linear error-correcting code capable of correcting single-bit errors and detecting double-bit errors (when extended).

##  Features

- **Efficient Encoding**: Converts 16-bit binary data into 21-bit Hamming codeword.
- **Single Error Correction (SEC)**: Detects and corrects single-bit errors.
- **Error Position Detection**: Reports the exact position of the error (if any).
- **Message Validation**: Checks whether the received message is valid or corrupted.
- **Clean & Modular Code**: Well-commented and structured for easy understanding and extension.
- **Command-line Interface**: Simple and user-friendly testing.

##  Example

### Input (16-bit data)
```bash
1010101000011010
```

### Encoded Message (21-bit codeword)
```bash
111101001010000011010
```

##  How It Works

The algorithm uses **5 parity bits** at positions that are powers of 2 (1, 2, 4, 8, 16). Each parity bit checks specific positions based on binary representation.

- **Encoding**: Parity bits are calculated and inserted into the data.
- **Decoding**: Syndrome calculation determines the error position.
  - Syndrome = 0 → No error
  - Syndrome ≠ 0 → Error at the position indicated by the syndrome value

---

##  Getting Started

### Prerequisites
- C++ compiler (g++ recommended)
- Linux / macOS / Windows (with MinGW or WSL)

### Compilation

```bash
g++ main.cpp -o hamming -Wall -Wextra -std=c++17
```

### Execution

```bash
./hamming
```

---

##  Project Structure

```bash
Hamming-Code-CPP/
├── main.cpp          # Main program with menu and tests
├── hamming.h         # Header file (if separated)
├── hamming.cpp       # Implementation (if separated)
├── README.md
└── test_cases.txt    # (Optional) sample test cases
```

---

##  Testing

The program includes a built-in test routine that demonstrates:

1. Original message encoding
2. Transmission with simulated single-bit error
3. Error detection and correction
4. Recovery of original message

You can easily add more test cases in `main.cpp`.

---

##  Future Enhancements (Roadmap)

- [ ] Support for different Hamming Code lengths (e.g., (7,4), (15,11), (31,26))
- [ ] Extended Hamming Code (SECDED) with overall parity bit
- [ ] File encoding/decoding support
- [ ] Interactive menu with more options
- [ ] Unit tests using GoogleTest or Catch2

---

##  License

This project is open-source and available under the **MIT License**.

---

##  Contributing

Contributions, issues, and feature requests are welcome!  
Feel free to fork the repository and submit a pull request.

---

**Feel free to star ⭐ the repository if you found it useful!**

---
