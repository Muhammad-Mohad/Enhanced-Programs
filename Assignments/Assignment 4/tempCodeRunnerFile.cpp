int main()
{
    ComplexNumber c1, c2;

    cout << "Enter c1:\n";
    c1.Input();

    cout << "\n\nEnetr c2:\n";
    c2.Input();

    cout << "\nc1 =    "; 
    c1.Output();

    cout << "\n\nc2 =    "; 
    c2.Output();

    if(c1.IsEqual(c2) == true)
        cout << "\n\nc1 is equal to c2.";
    else
        cout << "\n\nc1 is not equal to c2.";

    cout << "\n\nConjugate of c1:    ";
    ComplexNumber conjugate_c1 = c1.Conjugate();
    conjugate_c1.Output();

    cout << "\n\nConjugate of c2:    ";
    ComplexNumber conjugate_c2 = c2.Conjugate();
    conjugate_c2.Output();

    cout << "\n\nc1 + c2:    ";
    ComplexNumber add = c1.Add(c2);
    add.Output();

    cout << "\n\nc1 - c2:    ";
    ComplexNumber subtract = c1.Subtract(c2);
    subtract.Output();

    cout << "\n\nc1 x c2:    ";
    ComplexNumber multiply  = c1.Multiplication(c2);
    multiply.Output();

    float mag1 = c1.Magnitude();
    cout << "\n\nMagnitude of c1:    " << mag1;

    float mag2 = c2.Magnitude();
    cout << "\n\nMagnitude of c2:    " << mag2;

    return 0;
}