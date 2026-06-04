#include <iostream>
#include <string>

using namespace std;

// Generate Hamming Code
string generateHammingCode(string data)
{
    int m = data.length();
    int r = 0;

    // Calculate required parity bits
    while ((1 << r) < (m + r + 1))
    {
        r++;
    }

    int totalBits = m + r;

    // Indexing starts from 1
    string code(totalBits + 1, '0');

    int dataIndex = 0;

    // Place data bits and reserve parity positions
    for (int i = 1; i <= totalBits; i++)
    {
        if ((i & (i - 1)) == 0)
        {
            code[i] = '0'; // parity bit
        }
        else
        {
            code[i] = data[dataIndex++];
        }
    }

    // Calculate parity bits
    for (int i = 0; i < r; i++)
    {
        int parityPos = (1 << i);
        int parity = 0;

        for (int j = 1; j <= totalBits; j++)
        {
            if (j & parityPos)
            {
                parity ^= (code[j] - '0');
            }
        }

        code[parityPos] = parity + '0';
    }

    return code.substr(1);
}

// Detect error position
int detectError(string received)
{
    int n = received.length();

    string code = " " + received;

    int errorPos = 0;

    for (int i = 0; (1 << i) <= n; i++)
    {
        int parityPos = (1 << i);
        int parity = 0;

        for (int j = 1; j <= n; j++)
        {
            if (j & parityPos)
            {
                parity ^= (code[j] - '0');
            }
        }

        if (parity)
        {
            errorPos += parityPos;
        }
    }

    return errorPos;
}

int main()
{
    string data = "1010101000011010";

    // Encode message
    string encoded = generateHammingCode(data);

    cout << "Original Data: " << data << endl;
    cout << "Encoded Hamming Code: " << encoded << endl;

    // Verify correct transmission
    int errorPosition = detectError(encoded);

    if (errorPosition == 0)
    {
        cout << "Message received correctly." << endl;
    }
    else
    {
        cout << "Error detected at bit position "
             << errorPosition << endl;
    }

    // Test routine: introduce a single-bit error
    string test = encoded;

    test[4] = (test[4] == '0') ? '1' : '0';

    cout << "\nCorrupted Message: "
         << test << endl;

    int error = detectError(test);

    if (error == 0)
    {
        cout << "No error detected." << endl;
    }
    else
    {
        cout << "Detected Error Position: "
             << error << endl;
    }

    return 0;
}