#include <iostream>
#include <cstring>
using namespace std;

class BinaryNum {
private:
    int* binNum;  // integer array to save binary number
    int noOfBits; // total no. of bits

public:
    BinaryNum() : binNum(nullptr), noOfBits(0) {}

    BinaryNum(const char* ch) {
        noOfBits = strlen(ch);
        binNum = new int[noOfBits];
        for(int i = 0; i < noOfBits; i++) {
            binNum[i] = ch[i] - '0';
        }
    }

    BinaryNum(int num) {
        int temp = num;
        int bits = 0;
        while (temp > 0) {
            temp >>= 1;
            bits++;
        }
        if (bits == 0) bits = 1; // Handle case when num is 0

        binNum = new int[bits];
        noOfBits = bits;

        for (int i = 0; i < bits; i++) {
            binNum[i] = num % 2;
            num >>= 1;
        }
    }

    ~BinaryNum() {
        delete[] binNum;
    }

    void Print() {
        for (int i = noOfBits - 1; i >= 0; i--) {
            cout << binNum[i];
        }
        cout << endl;
    }

    BinaryNum operator+(const BinaryNum& num) const {
        int maxBits = max(noOfBits, num.noOfBits);
        int* result = new int[maxBits + 1]; // +1 for possible carry
        int carry = 0;

        for (int i = 0; i < maxBits; i++) {
            int sum = carry;
            if (i < noOfBits) sum += binNum[i];
            if (i < num.noOfBits) sum += num.binNum[i];
            result[i] = sum % 2; // Remainder is the bit value
            carry = sum / 2;     // Update carry for the next bit
        }
        result[maxBits] = carry; // Store any remaining carry at MSB

        // Count leading zeros
        int leadingZeros = 0;
        for (int i = maxBits; i >= 0; i--) {
            if (result[i] == 0) {
                leadingZeros++;
            } else {
                break;
            }
        }

        // Create BinaryNum with correct size and data
        BinaryNum sumBinary;
        sumBinary.noOfBits = maxBits - leadingZeros + 1;
        sumBinary.binNum = new int[sumBinary.noOfBits];
        for (int i = 0; i < sumBinary.noOfBits; i++) {
            sumBinary.binNum[i] = result[i];
        }

        delete[] result;
        return sumBinary;
    }
    int operator[](int index) const
    {
        return binNum[noOfBits - 1 -index];
    }
    BinaryNum operator++(int) {
    BinaryNum temp(*this);  // Create a temporary copy of the current object
    // Increment the current object (b3)
    int carry = 1;
    for (int i = 0; i < noOfBits; i++) {
        int sum = binNum[i] + carry;
        binNum[i] = sum % 2;  // Update the current bit
        carry = sum / 2;       // Update the carry
    }
    // If there is a carry after the loop, resize the binary number to accommodate it
    if (carry) {
        int* newBinNum = new int[noOfBits + 1];
        memcpy(newBinNum, binNum, noOfBits * sizeof(int));
        newBinNum[noOfBits] = carry; // Set the new most significant bit
        delete[] binNum;  // Deallocate the old memory
        binNum = newBinNum;
        noOfBits++;  // Increment the number of bits
    }
    return temp;  // Return the temporary copy
}

};

int main() {
    BinaryNum b1;         // b1 = 0
    BinaryNum b2("101");  // b2 = 101
    BinaryNum b3("1001"); // b3 = 1001

    cout<<"b1 = ";
    b1.Print(); //Prints Nothing
    cout<<"b2 = ";
    b2.Print(); //Prints 101
    cout<<"b3 = ";
    b3.Print(); //Prints 1001

    b1 = b2 + b3; // 5 + 9 = 14
    cout << "b1 = ";
    b1.Print(); // Prints 1110

    cout<<"b1[0] = "<<b1[0]<<endl; //Prints 1 (0th bit in b1)
    cout<<"b1[1] = "<<b1[1]<<endl; //Prints 0 (3rd bit in b1)
    cout<<"b1[2] = "<<b1[2]<<endl; //Prints 0 (3rd bit in b1)
    cout<<"b1[3] = "<<b1[3]<<endl; //Prints 0 (3rd bit in b1)

    (b3++).Print(); //Prints 1001
    b3.Print(); //Prints 1010
    // b1 = "111" + b2;
    // b1.Print(); //Prints 1100

    return 0;
}
